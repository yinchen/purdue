/* cipher.c - En-/De-ciphering filter
 * Copyright (C) 1998, 1999, 2000, 2001 Free Software Foundation, Inc.
 *
 * This file is part of GnuPG.
 *
 * GnuPG is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * GnuPG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */

#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include "errors.h"
#include "iobuf.h"
#include "memory.h"
#include "util.h"
#include "filter.h"
#include "packet.h"
#include "options.h"
#include "main.h"
#include "status.h"


#define MIN_PARTIAL_SIZE 512


static void
write_header( cipher_filter_context_t *cfx, IOBUF a )
{
    PACKET pkt;
    PKT_encrypted ed;
    byte temp[18];
    unsigned blocksize;
    unsigned nprefix;
    int use_mdc = opt.force_mdc;

    blocksize = cipher_get_blocksize( cfx->dek->algo );
    if( blocksize < 8 || blocksize > 16 )
	log_fatal("unsupported blocksize %u\n", blocksize );
    if( blocksize != 8 )
	use_mdc = 1;  /* enable it for all modern ciphers */
    if( opt.rfc2440 )
	use_mdc = 0;  /* override - rfc2440 does not know about MDC */

    memset( &ed, 0, sizeof ed );
    ed.len = cfx->datalen;
    ed.extralen = blocksize+2;
    ed.new_ctb = !ed.len && !opt.rfc1991;
    if( use_mdc ) {
	ed.mdc_method = DIGEST_ALGO_SHA1;
	cfx->mdc_hash = md_open( DIGEST_ALGO_SHA1, 0 );
	if ( DBG_HASHING )
	    md_start_debug( cfx->mdc_hash, "creatmdc" );
    }
    init_packet( &pkt );
    pkt.pkttype = use_mdc? PKT_ENCRYPTED_MDC : PKT_ENCRYPTED;
    pkt.pkt.encrypted = &ed;
    if( build_packet( a, &pkt ))
	log_bug("build_packet(ENCR_DATA) failed\n");
    nprefix = blocksize;
    randomize_buffer( temp, nprefix, 1 );
    temp[nprefix] = temp[nprefix-2];
    temp[nprefix+1] = temp[nprefix-1];
    print_cipher_algo_note( cfx->dek->algo );
    cfx->cipher_hd = cipher_open( cfx->dek->algo,
				  use_mdc? CIPHER_MODE_CFB
					 : CIPHER_MODE_AUTO_CFB, 1 );
/*   log_hexdump( "thekey", cfx->dek->key, cfx->dek->keylen );*/
    cipher_setkey( cfx->cipher_hd, cfx->dek->key, cfx->dek->keylen );
    cipher_setiv( cfx->cipher_hd, NULL, 0 );
/*  log_hexdump( "prefix", temp, nprefix+2 ); */
    if( cfx->mdc_hash ) /* hash the "IV" */
	md_write( cfx->mdc_hash, temp, nprefix+2 );
    cipher_encrypt( cfx->cipher_hd, temp, temp, nprefix+2);
    cipher_sync( cfx->cipher_hd );
    iobuf_write(a, temp, nprefix+2);
    cfx->header=1;
}



/****************
 * This filter is used to en/de-cipher data with a conventional algorithm
 */
int
cipher_filter( void *opaque, int control,
	       IOBUF a, byte *buf, size_t *ret_len)
{
    size_t size = *ret_len;
    cipher_filter_context_t *cfx = opaque;
    int rc=0;

    if( control == IOBUFCTRL_UNDERFLOW ) { /* decrypt */
	rc = -1; /* not yet used */
    }
    else if( control == IOBUFCTRL_FLUSH ) { /* encrypt */
	assert(a);
	if( !cfx->header ) {
	    write_status( STATUS_BEGIN_ENCRYPTION );
	    write_header( cfx, a );
	}
	if( cfx->mdc_hash )
	    md_write( cfx->mdc_hash, buf, size );
	cipher_encrypt( cfx->cipher_hd, buf, buf, size);
	if( iobuf_write( a, buf, size ) )
	    rc = G10ERR_WRITE_FILE;
    }
    else if( control == IOBUFCTRL_FREE ) {
	if( cfx->mdc_hash ) {
	    byte *hash;
	    int hashlen = md_digest_length( md_get_algo( cfx->mdc_hash ) );
	    byte temp[22];

	    assert( hashlen == 20 );
	    /* we must hash the prefix of the MDC packet here */
	    temp[0] = 0xd3;
	    temp[1] = 0x14;
	    md_putc( cfx->mdc_hash, temp[0] );
	    md_putc( cfx->mdc_hash, temp[1] );

	    md_final( cfx->mdc_hash );
	    hash = md_read( cfx->mdc_hash, 0 );
	    memcpy(temp+2, hash, 20);
	    cipher_encrypt( cfx->cipher_hd, temp, temp, 22 );
	    md_close( cfx->mdc_hash ); cfx->mdc_hash = NULL;
	    if( iobuf_write( a, temp, 22 ) )
		log_error("writing MDC packet failed\n" );
	}
	cipher_close(cfx->cipher_hd);
    }
    else if( control == IOBUFCTRL_DESC ) {
	*(char**)buf = "cipher_filter";
    }
    return rc;
}


