# Generated automatically from Makefile.in by configure.
# Makefile.in generated automatically by automake 1.4 from Makefile.am

# Copyright (C) 1994, 1995-8, 1999 Free Software Foundation, Inc.
# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.

# Copyright (C) 1998, 1999, 2000, 2001 Free Software Foundation, Inc.
#
# This file is part of GnuPG.
#
# GnuPG is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
# 
# GnuPG is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA


SHELL = /bin/sh

srcdir = ../../g10
top_srcdir = ../..
VPATH = ../../g10
prefix = /usr/local
exec_prefix = ${prefix}

bindir = ${exec_prefix}/bin
sbindir = ${exec_prefix}/sbin
libexecdir = ${exec_prefix}/libexec
datadir = ${prefix}/share
sysconfdir = ${prefix}/etc
sharedstatedir = ${prefix}/com
localstatedir = ${prefix}/var
libdir = ${exec_prefix}/lib
infodir = ${prefix}/info
mandir = ${prefix}/man
includedir = ${prefix}/include
oldincludedir = /usr/include

DESTDIR =

pkgdatadir = $(datadir)/gnupg
pkglibdir = $(libdir)/gnupg
pkgincludedir = $(includedir)/gnupg

top_builddir = ..

ACLOCAL = aclocal
AUTOCONF = autoconf
AUTOMAKE = automake
AUTOHEADER = autoheader

INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL} $(AM_INSTALL_PROGRAM_FLAGS)
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_SCRIPT = ${INSTALL_PROGRAM}
transform = s,x,x,

NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
build_alias = x86_64-unknown-linux-gnu
build_triplet = x86_64-unknown-linux-gnu
host_alias = x86_64-unknown-linux-gnu
host_triplet = x86_64-unknown-linux-gnu
target_alias = x86_64-unknown-linux-gnu
target_triplet = x86_64-unknown-linux-gnu
AS = @AS@
AWK = gawk
CATALOGS = 
CATOBJEXT = 
CC = gcc
CPP = gcc -E
DATADIRNAME = share
DLLTOOL = @DLLTOOL@
DOCBOOK_TO_MAN = no
DOCBOOK_TO_TEXI = no
DYNAMIC_CIPHER_MODS =  rndunix rndegd tiger
DYNLINK_LDFLAGS = 
DYNLINK_MOD_CFLAGS = 
FAQPROG = : 
GENCAT = 
GMOFILES =  da.gmo de.gmo eo.gmo es_ES.gmo et.gmo fr.gmo id.gmo it.gmo ja.gmo nl.gmo pl.gmo pt_BR.gmo pt_PT.gmo ru.gmo sv.gmo tr.gmo
GMSGFMT = 
GT_NO = 
GT_YES = #YES#
INCLUDE_LOCALE_H = #include <locale.h>
INSTOBJEXT = 
INTLDEPS = 
INTLLIBS = 
INTLOBJS = 
MAINT = #
MAKEINFO = makeinfo
MKINSTALLDIRS = ../scripts/mkinstalldirs
MPI_EXTRA_ASM_OBJS = 
MPI_OPT_FLAGS = 
MPI_SFLAGS = 
MSGFMT = 
NM = /usr/bin/nm -B
PACKAGE = gnupg
POFILES =  da.po de.po eo.po es_ES.po et.po fr.po id.po it.po ja.po nl.po pl.po pt_BR.po pt_PT.po ru.po sv.po tr.po
POSUB = 
RANLIB = ranlib
STATIC_CIPHER_NAMES =  rndlinux sha1 rmd160 md5
STATIC_CIPHER_OBJS =  rndlinux.o sha1.o rmd160.o md5.o
USE_INCLUDED_LIBINTL = no
USE_NLS = no
VERSION = 1.0.5
ZLIBS = ../zlib/libzlib.a
l = 

INCLUDES = -I$(top_srcdir)/include -I$(top_srcdir)/intl
EXTRA_DIST = OPTIONS  pubring.asc  options.skel
OMIT_DEPENDENCIES = zlib.h zconf.h
LDFLAGS =  
needed_libs = ../cipher/libcipher.a ../mpi/libmpi.a ../util/libutil.a

#noinst_PROGRAMS = gpgd
bin_PROGRAMS = gpg gpgv

common_source =  	      build-packet.c		      compress.c		      filter.h			      free-packet.c		      getkey.c			      ringedit.c		      seskey.c			      keydb.h			      kbnode.c			      main.h			      mainproc.c		      armor.c			      mdfilter.c		      textfilter.c		      misc.c			      options.h 		      openfile.c		      keyid.c			      packet.h			      parse-packet.c		      comment.c 		      status.c			      status.h			      plaintext.c		      sig-check.c		      signal.c		


gpg_SOURCES = g10.c			      $(common_source)		      pkclist.c 		      skclist.c 		      pubkey-enc.c		      passphrase.c		      seckey-cert.c		      encr-data.c		      cipher.c			      keylist.c 		      encode.c			      sign.c			      verify.c			      revoke.c			      decrypt.c 		      keyedit.c 		      dearmor.c 		      import.c			      export.c			      hkp.h			      hkp.c			      trustdb.c 		      trustdb.h 		      tdbdump.c 		      tdbio.c			      tdbio.h			      delkey.c			      keygen.c          	      pipemode.c        	      helptext.c


gpgv_SOURCES = gpgv.c           	      $(common_source)  	      verify.c          


#gpgd_SOURCES = gpgd.c \
#	       ks-proto.h \
#	       ks-proto.c \
#	       ks-db.c \
#	       ks-db.h \
#	       $(common_source)

LDADD = $(needed_libs) ../zlib/libzlib.a 
mkinstalldirs = $(SHELL) $(top_srcdir)/scripts/mkinstalldirs
CONFIG_HEADER = ../config.h
CONFIG_CLEAN_FILES = 
PROGRAMS =  $(bin_PROGRAMS)


DEFS = -DHAVE_CONFIG_H -I. -I$(srcdir) -I..
CPPFLAGS = 
LIBS = -lnsl -lgdbm  -lnsl
gpg_OBJECTS =  g10.o build-packet.o compress.o free-packet.o getkey.o \
ringedit.o seskey.o kbnode.o mainproc.o armor.o mdfilter.o textfilter.o \
misc.o openfile.o keyid.o parse-packet.o comment.o status.o plaintext.o \
sig-check.o signal.o pkclist.o skclist.o pubkey-enc.o passphrase.o \
seckey-cert.o encr-data.o cipher.o keylist.o encode.o sign.o verify.o \
revoke.o decrypt.o keyedit.o dearmor.o import.o export.o hkp.o \
trustdb.o tdbdump.o tdbio.o delkey.o keygen.o pipemode.o helptext.o
gpg_LDADD = $(LDADD)
gpg_DEPENDENCIES =  ../cipher/libcipher.a ../mpi/libmpi.a \
../util/libutil.a
gpg_LDFLAGS = 
gpgv_OBJECTS =  gpgv.o build-packet.o compress.o free-packet.o getkey.o \
ringedit.o seskey.o kbnode.o mainproc.o armor.o mdfilter.o textfilter.o \
misc.o openfile.o keyid.o parse-packet.o comment.o status.o plaintext.o \
sig-check.o signal.o verify.o
gpgv_LDADD = $(LDADD)
gpgv_DEPENDENCIES =  ../cipher/libcipher.a ../mpi/libmpi.a \
../util/libutil.a
gpgv_LDFLAGS = 
CFLAGS = -g -O2 -Wall
COMPILE = $(CC) $(DEFS) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
CCLD = $(CC)
LINK = $(CCLD) $(AM_CFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
DIST_COMMON =  ChangeLog Makefile.am Makefile.in


DISTFILES = $(DIST_COMMON) $(SOURCES) $(HEADERS) $(TEXINFOS) $(EXTRA_DIST)

TAR = tar
GZIP_ENV = --best
SOURCES = $(gpg_SOURCES) $(gpgv_SOURCES)
OBJECTS = $(gpg_OBJECTS) $(gpgv_OBJECTS)

all: all-redirect
.SUFFIXES:
.SUFFIXES: .S .c .o .s
$(srcdir)/Makefile.in: # Makefile.am $(top_srcdir)/configure.in $(ACLOCAL_M4) 
	cd $(top_srcdir) && $(AUTOMAKE) --gnu --include-deps g10/Makefile

Makefile: $(srcdir)/Makefile.in  $(top_builddir)/config.status
	cd $(top_builddir) \
	  && CONFIG_FILES=$(subdir)/$@ CONFIG_HEADERS= $(SHELL) ./config.status


mostlyclean-binPROGRAMS:

clean-binPROGRAMS:
	-test -z "$(bin_PROGRAMS)" || rm -f $(bin_PROGRAMS)

distclean-binPROGRAMS:

maintainer-clean-binPROGRAMS:

install-binPROGRAMS: $(bin_PROGRAMS)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(bindir)
	@list='$(bin_PROGRAMS)'; for p in $$list; do \
	  if test -f $$p; then \
	    echo "  $(INSTALL_PROGRAM) $$p $(DESTDIR)$(bindir)/`echo $$p|sed 's/$(EXEEXT)$$//'|sed '$(transform)'|sed 's/$$/$(EXEEXT)/'`"; \
	     $(INSTALL_PROGRAM) $$p $(DESTDIR)$(bindir)/`echo $$p|sed 's/$(EXEEXT)$$//'|sed '$(transform)'|sed 's/$$/$(EXEEXT)/'`; \
	  else :; fi; \
	done

uninstall-binPROGRAMS:
	@$(NORMAL_UNINSTALL)
	list='$(bin_PROGRAMS)'; for p in $$list; do \
	  rm -f $(DESTDIR)$(bindir)/`echo $$p|sed 's/$(EXEEXT)$$//'|sed '$(transform)'|sed 's/$$/$(EXEEXT)/'`; \
	done

.c.o:
	$(COMPILE) -c $<

.s.o:
	$(COMPILE) -c $<

.S.o:
	$(COMPILE) -c $<

mostlyclean-compile:
	-rm -f *.o core *.core

clean-compile:

distclean-compile:
	-rm -f *.tab.c

maintainer-clean-compile:

gpg: $(gpg_OBJECTS) $(gpg_DEPENDENCIES)
	@rm -f gpg
	$(LINK) $(gpg_LDFLAGS) $(gpg_OBJECTS) $(gpg_LDADD) $(LIBS)

gpgv: $(gpgv_OBJECTS) $(gpgv_DEPENDENCIES)
	@rm -f gpgv
	$(LINK) $(gpgv_LDFLAGS) $(gpgv_OBJECTS) $(gpgv_LDADD) $(LIBS)

tags: TAGS

ID: $(HEADERS) $(SOURCES) $(LISP)
	list='$(SOURCES) $(HEADERS)'; \
	unique=`for i in $$list; do echo $$i; done | \
	  awk '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	here=`pwd` && cd $(srcdir) \
	  && mkid -f$$here/ID $$unique $(LISP)

TAGS:  $(HEADERS) $(SOURCES)  $(TAGS_DEPENDENCIES) $(LISP)
	tags=; \
	here=`pwd`; \
	list='$(SOURCES) $(HEADERS)'; \
	unique=`for i in $$list; do echo $$i; done | \
	  awk '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	test -z "$(ETAGS_ARGS)$$unique$(LISP)$$tags" \
	  || (cd $(srcdir) && etags $(ETAGS_ARGS) $$tags  $$unique $(LISP) -o $$here/TAGS)

mostlyclean-tags:

clean-tags:

distclean-tags:
	-rm -f TAGS ID

maintainer-clean-tags:

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)

subdir = g10

distdir: $(DISTFILES)
	@for file in $(DISTFILES); do \
	  d=$(srcdir); \
	  if test -d $$d/$$file; then \
	    cp -pr $$d/$$file $(distdir)/$$file; \
	  else \
	    test -f $(distdir)/$$file \
	    || ln $$d/$$file $(distdir)/$$file 2> /dev/null \
	    || cp -p $$d/$$file $(distdir)/$$file || :; \
	  fi; \
	done
armor.o: armor.c ../config.h ../g10defs.h ../include/errors.h \
	../include/iobuf.h ../include/types.h ../include/memory.h \
	../include/util.h ../include/mpi.h filter.h ../include/cipher.h \
	../include/../cipher/random.h packet.h options.h main.h keydb.h \
	status.h ../include/i18n.h
build-packet.o: build-packet.c ../config.h ../g10defs.h packet.h \
	../include/types.h ../include/iobuf.h ../include/mpi.h \
	../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h filter.h ../include/errors.h \
	../include/util.h options.h
caching.o: caching.c ../config.h ../g10defs.h options.h \
	../include/types.h packet.h ../include/iobuf.h ../include/mpi.h \
	../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h filter.h ../include/errors.h \
	keydb.h ../include/util.h main.h ../include/i18n.h
cipher.o: cipher.c ../config.h ../g10defs.h ../include/errors.h \
	../include/iobuf.h ../include/types.h ../include/memory.h \
	../include/util.h ../include/mpi.h filter.h ../include/cipher.h \
	../include/../cipher/random.h packet.h options.h main.h keydb.h \
	status.h
comment.o: comment.c ../config.h ../g10defs.h options.h \
	../include/types.h packet.h ../include/iobuf.h ../include/mpi.h \
	../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h filter.h ../include/errors.h \
	../include/util.h main.h keydb.h
compress.o: compress.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h packet.h \
	../include/cipher.h ../include/../cipher/random.h filter.h \
	options.h
dearmor.o: dearmor.c ../config.h ../g10defs.h ../include/errors.h \
	../include/iobuf.h ../include/types.h ../include/memory.h \
	../include/util.h ../include/mpi.h filter.h ../include/cipher.h \
	../include/../cipher/random.h packet.h options.h main.h keydb.h
decrypt.o: decrypt.c ../config.h ../g10defs.h options.h \
	../include/types.h packet.h ../include/iobuf.h ../include/mpi.h \
	../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h filter.h ../include/errors.h \
	keydb.h ../include/util.h main.h ../include/i18n.h
delkey.o: delkey.c ../config.h ../g10defs.h options.h ../include/types.h \
	packet.h ../include/iobuf.h ../include/mpi.h \
	../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h filter.h ../include/errors.h \
	keydb.h ../include/util.h main.h trustdb.h ../include/ttyio.h \
	status.h ../include/i18n.h
encode.o: encode.c ../config.h ../g10defs.h options.h ../include/types.h \
	packet.h ../include/iobuf.h ../include/mpi.h \
	../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h filter.h ../include/errors.h \
	keydb.h ../include/util.h main.h trustdb.h ../include/i18n.h \
	status.h
encr-data.o: encr-data.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h packet.h \
	../include/cipher.h ../include/../cipher/random.h filter.h \
	options.h ../include/i18n.h
export.o: export.c ../config.h ../g10defs.h options.h ../include/types.h \
	packet.h ../include/iobuf.h ../include/mpi.h \
	../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h filter.h ../include/errors.h \
	keydb.h ../include/util.h main.h ../include/i18n.h
free-packet.o: free-packet.c ../config.h ../g10defs.h packet.h \
	../include/types.h ../include/iobuf.h ../include/mpi.h \
	../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h filter.h ../include/util.h \
	../include/errors.h options.h
g10.o: g10.c ../config.h ../g10defs.h packet.h ../include/types.h \
	../include/iobuf.h ../include/mpi.h ../include/memory.h \
	../include/cipher.h ../include/../cipher/random.h filter.h \
	../include/util.h ../include/errors.h main.h keydb.h options.h \
	trustdb.h ../include/ttyio.h ../include/i18n.h status.h hkp.h
getkey.o: getkey.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h packet.h \
	../include/cipher.h ../include/../cipher/random.h filter.h \
	keydb.h options.h main.h trustdb.h ../include/i18n.h
gpgv.o: gpgv.c ../config.h ../g10defs.h packet.h ../include/types.h \
	../include/iobuf.h ../include/mpi.h ../include/memory.h \
	../include/cipher.h ../include/../cipher/random.h filter.h \
	../include/util.h ../include/errors.h main.h keydb.h options.h \
	trustdb.h ../include/ttyio.h ../include/i18n.h status.h hkp.h
helptext.o: helptext.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h ../include/ttyio.h \
	main.h ../include/cipher.h ../include/../cipher/random.h \
	keydb.h packet.h filter.h ../include/i18n.h
hkp.o: hkp.c ../config.h ../g10defs.h ../include/errors.h \
	../include/util.h ../include/types.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h ../include/ttyio.h \
	../include/i18n.h options.h filter.h ../include/cipher.h \
	../include/../cipher/random.h ../include/http.h main.h keydb.h \
	packet.h
import.o: import.c ../config.h ../g10defs.h options.h ../include/types.h \
	packet.h ../include/iobuf.h ../include/mpi.h \
	../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h filter.h ../include/errors.h \
	keydb.h ../include/util.h trustdb.h main.h ../include/i18n.h \
	status.h
kbnode.o: kbnode.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h packet.h \
	../include/cipher.h ../include/../cipher/random.h filter.h \
	keydb.h
keyedit.o: keyedit.c ../config.h ../g10defs.h options.h \
	../include/types.h packet.h ../include/iobuf.h ../include/mpi.h \
	../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h filter.h ../include/errors.h \
	keydb.h ../include/util.h main.h trustdb.h ../include/ttyio.h \
	status.h ../include/i18n.h
keygen.o: keygen.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h main.h \
	../include/cipher.h ../include/../cipher/random.h keydb.h \
	packet.h filter.h ../include/ttyio.h options.h status.h \
	../include/i18n.h
keyid.o: keyid.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h main.h \
	../include/cipher.h ../include/../cipher/random.h keydb.h \
	packet.h filter.h options.h ../include/i18n.h
keylist.o: keylist.c ../config.h ../g10defs.h options.h \
	../include/types.h packet.h ../include/iobuf.h ../include/mpi.h \
	../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h filter.h ../include/errors.h \
	keydb.h ../include/util.h trustdb.h main.h ../include/i18n.h
mainproc.o: mainproc.c ../config.h ../g10defs.h packet.h \
	../include/types.h ../include/iobuf.h ../include/mpi.h \
	../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h filter.h options.h \
	../include/util.h ../include/errors.h keydb.h main.h status.h \
	../include/i18n.h trustdb.h hkp.h
mdfilter.o: mdfilter.c ../config.h ../g10defs.h ../include/errors.h \
	../include/iobuf.h ../include/types.h ../include/memory.h \
	../include/util.h ../include/mpi.h filter.h ../include/cipher.h \
	../include/../cipher/random.h
misc.o: misc.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h main.h \
	../include/cipher.h ../include/../cipher/random.h keydb.h \
	packet.h filter.h options.h ../include/i18n.h
openfile.o: openfile.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h ../include/ttyio.h \
	options.h main.h ../include/cipher.h \
	../include/../cipher/random.h keydb.h packet.h filter.h \
	status.h ../include/i18n.h
parse-packet.o: parse-packet.c ../config.h ../g10defs.h packet.h \
	../include/types.h ../include/iobuf.h ../include/mpi.h \
	../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h filter.h ../include/util.h \
	../include/errors.h options.h main.h keydb.h ../include/i18n.h
passphrase.o: passphrase.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h options.h \
	../include/ttyio.h ../include/cipher.h \
	../include/../cipher/random.h keydb.h packet.h filter.h main.h \
	../include/i18n.h status.h
pipemode.o: pipemode.c ../config.h ../g10defs.h options.h \
	../include/types.h packet.h ../include/iobuf.h ../include/mpi.h \
	../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h filter.h ../include/errors.h \
	keydb.h ../include/util.h main.h status.h
pkclist.o: pkclist.c ../config.h ../g10defs.h options.h \
	../include/types.h packet.h ../include/iobuf.h ../include/mpi.h \
	../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h filter.h ../include/errors.h \
	keydb.h ../include/util.h trustdb.h ../include/ttyio.h status.h \
	../include/i18n.h
plaintext.o: plaintext.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h options.h packet.h \
	../include/cipher.h ../include/../cipher/random.h filter.h \
	../include/ttyio.h main.h keydb.h status.h ../include/i18n.h
pubkey-enc.o: pubkey-enc.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h packet.h \
	../include/cipher.h ../include/../cipher/random.h filter.h \
	keydb.h trustdb.h status.h options.h ../include/i18n.h
revoke.o: revoke.c ../config.h ../g10defs.h options.h ../include/types.h \
	packet.h ../include/iobuf.h ../include/mpi.h \
	../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h filter.h ../include/errors.h \
	keydb.h ../include/util.h main.h ../include/ttyio.h status.h \
	../include/i18n.h
ringedit.o: ringedit.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h packet.h \
	../include/cipher.h ../include/../cipher/random.h filter.h \
	keydb.h ../include/host2net.h options.h main.h \
	../include/i18n.h
seckey-cert.o: seckey-cert.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h packet.h \
	../include/cipher.h ../include/../cipher/random.h filter.h \
	keydb.h main.h options.h ../include/i18n.h status.h
seskey.o: seskey.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h main.h keydb.h packet.h filter.h \
	../include/i18n.h
sig-check.o: sig-check.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h packet.h \
	../include/cipher.h ../include/../cipher/random.h filter.h \
	keydb.h main.h status.h ../include/i18n.h options.h
sign.o: sign.c ../config.h ../g10defs.h options.h ../include/types.h \
	packet.h ../include/iobuf.h ../include/mpi.h \
	../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h filter.h ../include/errors.h \
	keydb.h ../include/util.h main.h ../include/ttyio.h trustdb.h \
	status.h ../include/i18n.h
signal.o: signal.c ../config.h ../g10defs.h options.h ../include/types.h \
	../include/errors.h ../include/memory.h ../include/util.h \
	../include/mpi.h ../include/iobuf.h main.h ../include/cipher.h \
	../include/../cipher/random.h keydb.h packet.h filter.h \
	../include/ttyio.h
skclist.o: skclist.c ../config.h ../g10defs.h options.h \
	../include/types.h packet.h ../include/iobuf.h ../include/mpi.h \
	../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h filter.h ../include/errors.h \
	keydb.h ../include/util.h ../include/i18n.h
status.o: status.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h status.h \
	../include/ttyio.h options.h main.h ../include/cipher.h \
	../include/../cipher/random.h keydb.h packet.h filter.h \
	../include/i18n.h
tdbdump.o: tdbdump.c ../config.h ../g10defs.h ../include/errors.h \
	../include/iobuf.h ../include/types.h keydb.h packet.h \
	../include/mpi.h ../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h filter.h ../include/util.h \
	trustdb.h options.h main.h ../include/i18n.h tdbio.h \
	../include/host2net.h
tdbio.o: tdbio.c ../config.h ../g10defs.h ../include/errors.h \
	../include/iobuf.h ../include/types.h ../include/memory.h \
	../include/util.h ../include/mpi.h options.h main.h \
	../include/cipher.h ../include/../cipher/random.h keydb.h \
	packet.h filter.h ../include/i18n.h trustdb.h tdbio.h \
	../include/host2net.h
textfilter.o: textfilter.c ../config.h ../g10defs.h ../include/errors.h \
	../include/iobuf.h ../include/types.h ../include/memory.h \
	../include/util.h ../include/mpi.h filter.h ../include/cipher.h \
	../include/../cipher/random.h ../include/i18n.h options.h
trustdb.o: trustdb.c ../config.h ../g10defs.h ../include/errors.h \
	../include/iobuf.h ../include/types.h keydb.h packet.h \
	../include/mpi.h ../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h filter.h ../include/util.h \
	trustdb.h options.h main.h ../include/i18n.h tdbio.h \
	../include/host2net.h ../include/ttyio.h
verify.o: verify.c ../config.h ../g10defs.h options.h ../include/types.h \
	packet.h ../include/iobuf.h ../include/mpi.h \
	../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h filter.h ../include/errors.h \
	keydb.h ../include/util.h main.h status.h ../include/ttyio.h \
	../include/i18n.h

info-am:
info: info-am
dvi-am:
dvi: dvi-am
check-am: all-am
check: check-am
installcheck-am:
installcheck: installcheck-am
install-exec-am: install-binPROGRAMS
install-exec: install-exec-am

install-data-am: install-data-local
install-data: install-data-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am
install: install-am
uninstall-am: uninstall-binPROGRAMS
uninstall: uninstall-am
all-am: Makefile $(PROGRAMS)
all-redirect: all-am
install-strip:
	$(MAKE) $(AM_MAKEFLAGS) AM_INSTALL_PROGRAM_FLAGS=-s install
installdirs:
	$(mkinstalldirs)  $(DESTDIR)$(bindir)


mostlyclean-generic:

clean-generic:

distclean-generic:
	-rm -f Makefile $(CONFIG_CLEAN_FILES)
	-rm -f config.cache config.log stamp-h stamp-h[0-9]*

maintainer-clean-generic:
mostlyclean-am:  mostlyclean-binPROGRAMS mostlyclean-compile \
		mostlyclean-tags mostlyclean-generic

mostlyclean: mostlyclean-am

clean-am:  clean-binPROGRAMS clean-compile clean-tags clean-generic \
		mostlyclean-am

clean: clean-am

distclean-am:  distclean-binPROGRAMS distclean-compile distclean-tags \
		distclean-generic clean-am

distclean: distclean-am

maintainer-clean-am:  maintainer-clean-binPROGRAMS \
		maintainer-clean-compile maintainer-clean-tags \
		maintainer-clean-generic distclean-am
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."

maintainer-clean: maintainer-clean-am

.PHONY: mostlyclean-binPROGRAMS distclean-binPROGRAMS clean-binPROGRAMS \
maintainer-clean-binPROGRAMS uninstall-binPROGRAMS install-binPROGRAMS \
mostlyclean-compile distclean-compile clean-compile \
maintainer-clean-compile tags mostlyclean-tags distclean-tags \
clean-tags maintainer-clean-tags distdir info-am info dvi-am dvi check \
check-am installcheck-am installcheck install-exec-am install-exec \
install-data-local install-data-am install-data install-am install \
uninstall-am uninstall all-redirect all-am all installdirs \
mostlyclean-generic distclean-generic clean-generic \
maintainer-clean-generic clean mostlyclean distclean maintainer-clean


$(PROGRAMS): $(needed_libs)

install-data-local:
	$(mkinstalldirs) $(DESTDIR)$(pkgdatadir)
	$(INSTALL_DATA) $(srcdir)/options.skel \
				$(DESTDIR)$(pkgdatadir)/options.skel
	@set -e;\
	 if test -f $(DESTDIR)$(bindir)/gpgm ; then \
	   echo "removing obsolete gpgm binary" ;   \
	   rm $(DESTDIR)$(bindir)/gpgm ;	    \
	 fi

# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
