CC="llvm-gcc.cde --emit-llvm"
LD=llvm-ld
AR=llvm-ar

cd util
$CC -DHAVE_CONFIG_H -I. -I../../util -I.. -I../../include -I../../intl    -g -Wall -c ../../util/g10u.c
$CC -DHAVE_CONFIG_H -I. -I../../util -I.. -I../../include -I../../intl    -g -Wall -c ../../util/logger.c
$CC -DHAVE_CONFIG_H -I. -I../../util -I.. -I../../include -I../../intl    -g -Wall -c ../../util/fileutil.c
$CC -DHAVE_CONFIG_H -I. -I../../util -I.. -I../../include -I../../intl    -g -Wall -c ../../util/miscutil.c
$CC -DHAVE_CONFIG_H -I. -I../../util -I.. -I../../include -I../../intl    -g -Wall -c ../../util/strgutil.c
$CC -DHAVE_CONFIG_H -I. -I../../util -I.. -I../../include -I../../intl    -g -Wall -c ../../util/ttyio.c
$CC -DHAVE_CONFIG_H -I. -I../../util -I.. -I../../include -I../../intl    -g -Wall -c ../../util/argparse.c
$CC -DHAVE_CONFIG_H -I. -I../../util -I.. -I../../include -I../../intl    -g -Wall -c ../../util/memory.c
$CC -DHAVE_CONFIG_H -I. -I../../util -I.. -I../../include -I../../intl    -g -Wall -c ../../util/secmem.c
$CC -DHAVE_CONFIG_H -I. -I../../util -I.. -I../../include -I../../intl    -g -Wall -c ../../util/errors.c
$CC -DHAVE_CONFIG_H -I. -I../../util -I.. -I../../include -I../../intl    -g -Wall -c ../../util/iobuf.c
$CC -DHAVE_CONFIG_H -I. -I../../util -I.. -I../../include -I../../intl    -g -Wall -c ../../util/dotlock.c
$CC -DHAVE_CONFIG_H -I. -I../../util -I.. -I../../include -I../../intl    -g -Wall -c ../../util/http.c
$CC -DHAVE_CONFIG_H -I. -I../../util -I.. -I../../include -I../../intl    -g -Wall -c ../../util/simple-gettext.c
$CC -DHAVE_CONFIG_H -I. -I../../util -I.. -I../../include -I../../intl    -g -Wall -c ../../util/w32reg.c
rm -f libutil.a
$AR cru libutil.a g10u.o logger.o fileutil.o miscutil.o strgutil.o ttyio.o argparse.o memory.o secmem.o errors.o iobuf.o dotlock.o http.o simple-gettext.o w32reg.o 
cd ..


cd mpi
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c ../../mpi/mpi-add.c
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c ../../mpi/mpi-bit.c
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c ../../mpi/mpi-cmp.c
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c ../../mpi/mpi-div.c
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c ../../mpi/mpi-gcd.c
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c ../../mpi/mpi-inline.c
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c ../../mpi/mpi-inv.c
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c ../../mpi/mpi-mul.c
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c ../../mpi/mpi-pow.c
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c ../../mpi/mpi-mpow.c
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c ../../mpi/mpi-scan.c
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c ../../mpi/mpicoder.c
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c ../../mpi/mpih-cmp.c
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c ../../mpi/mpih-div.c
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c ../../mpi/mpih-mul.c
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c ../../mpi/mpiutil.c
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c ../../mpi/g10m.c
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c mpih-mul1.c
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c mpih-mul2.c
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c mpih-mul3.c
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c mpih-add1.c
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c mpih-sub1.c
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c mpih-lshift.c
$CC -DHAVE_CONFIG_H -I. -I../../mpi -I.. -I../../include    -g -Wall  -c mpih-rshift.c
rm -f libmpi.a
$AR cru libmpi.a mpi-add.o mpi-bit.o mpi-cmp.o mpi-div.o mpi-gcd.o mpi-inline.o mpi-inv.o mpi-mul.o mpi-pow.o mpi-mpow.o mpi-scan.o mpicoder.o mpih-cmp.o mpih-div.o mpih-mul.o mpiutil.o g10m.o mpih-mul1.o    		     mpih-mul2.o    		     mpih-mul3.o    		     mpih-add1.o    		     mpih-sub1.o    		     mpih-lshift.o  		     mpih-rshift.o 
cd ..

cd cipher
$CC -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -c ../../cipher/cipher.c
$CC -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -c ../../cipher/pubkey.c
$CC -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -c ../../cipher/md.c
$CC -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -c ../../cipher/dynload.c
$CC -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -c ../../cipher/des.c
$CC -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -c ../../cipher/twofish.c
$CC -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -c ../../cipher/blowfish.c
$CC -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -c ../../cipher/cast5.c
$CC -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -c ../../cipher/rijndael.c
$CC -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -c ../../cipher/elgamal.c
$CC -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -c ../../cipher/rsa.c
$CC -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -c ../../cipher/primegen.c
$CC -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -c ../../cipher/random.c
$CC -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -c ../../cipher/dsa.c
$CC -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -c ../../cipher/g10c.c
$CC -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -c ../../cipher/smallprime.c
$CC -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -c construct.c
$CC -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -c ../../cipher/rndlinux.c
$CC -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -c ../../cipher/sha1.c
$CC -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -c ../../cipher/rmd160.c
$CC -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -c ../../cipher/md5.c
rm -f libcipher.a
$AR cru libcipher.a cipher.o pubkey.o md.o dynload.o des.o twofish.o blowfish.o cast5.o rijndael.o elgamal.o rsa.o primegen.o random.o dsa.o g10c.o smallprime.o construct.o rndlinux.o sha1.o rmd160.o md5.o
#ranlib libcipher.a
gcc -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -DIS_MODULE -shared -fPIC -o rndunix ../../cipher/rndunix.c
gcc -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -DIS_MODULE -shared -fPIC -o rndegd ../../cipher/rndegd.c
`echo gcc -DHAVE_CONFIG_H -I. -I../../cipher -I.. -I../../include -I../../intl    -g -Wall -DIS_MODULE -shared -fPIC -o tiger ../../cipher/tiger.c | \
    sed -e 's/-O[2-9s]*/-O/g' `
cd ..

#Making all in tools
#make[2]: Entering directory `/home/dohyeong/workspace/cs490/p3/test/gpg/gnupg-1.0.5/build/tools'
#gcc -DHAVE_CONFIG_H -I. -I../../tools -I.. -I../../include -I../../intl    -g -Wall -c ../../tools/mpicalc.c
#gcc  -g -Wall  -o mpicalc  mpicalc.o ../cipher/libcipher.a  	      ../mpi/libmpi.a ../util/libutil.a  -lz -ldl -lnsl -lgdbm  -lnsl
#gcc -DHAVE_CONFIG_H -I. -I../../tools -I.. -I../../include -I../../intl    -g -Wall -c ../../tools/bftest.c
#gcc  -g -Wall  -o bftest  bftest.o ../cipher/libcipher.a  	      ../mpi/libmpi.a ../util/libutil.a  -lz -ldl -lnsl -lgdbm  -lnsl
#gcc -DHAVE_CONFIG_H -I. -I../../tools -I.. -I../../include -I../../intl    -g -Wall -c ../../tools/clean-sat.c
#gcc  -g -Wall  -o clean-sat  clean-sat.o  -lz -ldl -lnsl -lgdbm  -lnsl
#gcc -DHAVE_CONFIG_H -I. -I../../tools -I.. -I../../include -I../../intl    -g -Wall -c ../../tools/mk-tdata.c
#gcc  -g -Wall  -o mk-tdata  mk-tdata.o  -lz -ldl -lnsl -lgdbm  -lnsl
#gcc -DHAVE_CONFIG_H -I. -I../../tools -I.. -I../../include -I../../intl    -g -Wall -c ../../tools/shmtest.c
#gcc  -g -Wall  -o shmtest  shmtest.o ../cipher/libcipher.a  	      ../mpi/libmpi.a ../util/libutil.a  -lz -ldl -lnsl -lgdbm  -lnsl
#make[2]: Leaving directory `/home/dohyeong/workspace/cs490/p3/test/gpg/gnupg-1.0.5/build/tools'


cd g10
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/g10.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/build-packet.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/compress.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/free-packet.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/getkey.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/ringedit.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/seskey.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/kbnode.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/mainproc.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/armor.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/mdfilter.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/textfilter.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/misc.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/openfile.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/keyid.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/parse-packet.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/comment.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/status.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/plaintext.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/sig-check.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/signal.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/pkclist.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/skclist.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/pubkey-enc.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/passphrase.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/seckey-cert.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/encr-data.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/cipher.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/keylist.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/encode.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/sign.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/verify.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/revoke.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/decrypt.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/keyedit.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/dearmor.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/import.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/export.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/hkp.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/trustdb.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/tdbdump.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/tdbio.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/delkey.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/keygen.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/pipemode.c
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/helptext.c
$LD -o gpg  g10.o build-packet.o compress.o free-packet.o getkey.o ringedit.o seskey.o kbnode.o mainproc.o armor.o mdfilter.o textfilter.o misc.o openfile.o keyid.o parse-packet.o comment.o status.o plaintext.o sig-check.o signal.o pkclist.o skclist.o pubkey-enc.o passphrase.o seckey-cert.o encr-data.o cipher.o keylist.o encode.o sign.o verify.o revoke.o decrypt.o keyedit.o dearmor.o import.o export.o hkp.o trustdb.o tdbdump.o tdbio.o delkey.o keygen.o pipemode.o helptext.o ../cipher/libcipher.a ../mpi/libmpi.a ../util/libutil.a   -lz -ldl -lnsl -lgdbm  -lnsl
$CC -DHAVE_CONFIG_H -I. -I../../g10 -I.. -I../../include -I../../intl    -g -Wall -c ../../g10/gpgv.c
$LD -o gpgv  gpgv.o build-packet.o compress.o free-packet.o getkey.o ringedit.o seskey.o kbnode.o mainproc.o armor.o mdfilter.o textfilter.o misc.o openfile.o keyid.o parse-packet.o comment.o status.o plaintext.o sig-check.o signal.o verify.o ../cipher/libcipher.a ../mpi/libmpi.a ../util/libutil.a   -lz -ldl -lnsl -lgdbm  -lnsl
cd ..

cd po
make 
cd ..

echo "Done"
ln -s g10/gpg.bc .
