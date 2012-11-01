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

srcdir = ../../cipher
top_srcdir = ../..
VPATH = ../../cipher
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
CATALOGS =  da.gmo de.gmo eo.gmo es_ES.gmo et.gmo fr.gmo id.gmo it.gmo ja.gmo nl.gmo pl.gmo pt_BR.gmo pt_PT.gmo ru.gmo sv.gmo tr.gmo
CATOBJEXT = .gmo
CC = gcc
CPP = gcc -E
DATADIRNAME = share
DLLTOOL = @DLLTOOL@
DOCBOOK_TO_MAN = no
DOCBOOK_TO_TEXI = no
DYNAMIC_CIPHER_MODS =  rndunix rndegd tiger
DYNLINK_LDFLAGS = -Wl,-export-dynamic
FAQPROG = : 
GENCAT = 
GMOFILES =  da.gmo de.gmo eo.gmo es_ES.gmo et.gmo fr.gmo id.gmo it.gmo ja.gmo nl.gmo pl.gmo pt_BR.gmo pt_PT.gmo ru.gmo sv.gmo tr.gmo
GMSGFMT = /usr/bin/gmsgfmt
GT_NO = 
GT_YES = #YES#
INCLUDE_LOCALE_H = #include <locale.h>
INSTOBJEXT = .mo
INTLDEPS = 
INTLLIBS = 
INTLOBJS = 
MAINT = #
MAKEINFO = makeinfo
MKINSTALLDIRS = ../scripts/mkinstalldirs
MPI_EXTRA_ASM_OBJS = 
MPI_OPT_FLAGS = 
MPI_SFLAGS = 
MSGFMT = /usr/bin/msgfmt
NM = /usr/bin/nm -B
PACKAGE = gnupg
POFILES =  da.po de.po eo.po es_ES.po et.po fr.po id.po it.po ja.po nl.po pl.po pt_BR.po pt_PT.po ru.po sv.po tr.po
POSUB = po
RANLIB = ranlib
STATIC_CIPHER_NAMES =  rndlinux sha1 rmd160 md5
STATIC_CIPHER_OBJS =  rndlinux.o sha1.o rmd160.o md5.o
USE_INCLUDED_LIBINTL = no
USE_NLS = yes
VERSION = 1.0.5
ZLIBS = 
l = 

INCLUDES = -I$(top_srcdir)/include -I$(top_srcdir)/intl

noinst_LIBRARIES = libcipher.a

# The configure script greps the module names from the EXTRA_PROGRAMS line
EXTRA_PROGRAMS = rndlinux rndunix rndegd rndw32 sha1 rmd160 md5 tiger

EXTRA_rndlinux_SOURCES = rndlinux.c
EXTRA_rndunix_SOURCES = rndunix.c
EXTRA_rndegd_SOURCES = rndegd.c
EXTRA_rndw32_SOURCES = rndw32.c
EXTRA_md5_SOURCES = md5.c
EXTRA_rmd160_SOURCES = rmd160.c
EXTRA_sha1_SOURCES = sha1.c
EXTRA_tiger_SOURCES = tiger.c
pkglib_PROGRAMS =  rndunix rndegd tiger
#pkglib_PROGRAMS = 

DYNLINK_MOD_CFLAGS = -DIS_MODULE -shared -fPIC

#libcipher_a_LDFLAGS =
libcipher_a_SOURCES = cipher.c			 pubkey.c			 md.c				 dynload.c			 dynload.h			 bithelp.h			 des.c				 des.h				 twofish.c			 blowfish.c			 blowfish.h			 cast5.c			 cast5.h			 rijndael.c     		 elgamal.c			 elgamal.h			 rsa.c rsa.h    		 primegen.c			 random.h			 random.c			 rand-internal.h 		 rmd.h				 dsa.h				 dsa.c				 g10c.c 			 smallprime.c			 construct.c


# configure creates the constructor file
BUILT_SOURCES = construct.c

libcipher_a_DEPENDENCIES =  rndlinux.o sha1.o rmd160.o md5.o
libcipher_a_LIBADD =  rndlinux.o sha1.o rmd160.o md5.o
mkinstalldirs = $(SHELL) $(top_srcdir)/scripts/mkinstalldirs
CONFIG_HEADER = ../config.h
CONFIG_CLEAN_FILES = 
LIBRARIES =  $(noinst_LIBRARIES)


DEFS = -DHAVE_CONFIG_H -I. -I$(srcdir) -I..
CPPFLAGS = 
LDFLAGS = 
LIBS = -lz -ldl -lnsl -lgdbm  -lnsl
libcipher_a_OBJECTS =  cipher.o pubkey.o md.o dynload.o des.o twofish.o \
blowfish.o cast5.o rijndael.o elgamal.o rsa.o primegen.o random.o dsa.o \
g10c.o smallprime.o construct.o
AR = ar
PROGRAMS =  $(pkglib_PROGRAMS)

rndlinux_SOURCES = rndlinux.c
rndlinux_OBJECTS =  rndlinux.o
rndlinux_LDADD = $(LDADD)
rndlinux_DEPENDENCIES = 
rndlinux_LDFLAGS = 
rndunix_SOURCES = rndunix.c
rndunix_OBJECTS =  rndunix.o
rndunix_LDADD = $(LDADD)
rndunix_DEPENDENCIES = 
rndunix_LDFLAGS = 
rndegd_SOURCES = rndegd.c
rndegd_OBJECTS =  rndegd.o
rndegd_LDADD = $(LDADD)
rndegd_DEPENDENCIES = 
rndegd_LDFLAGS = 
rndw32_SOURCES = rndw32.c
rndw32_OBJECTS =  rndw32.o
rndw32_LDADD = $(LDADD)
rndw32_DEPENDENCIES = 
rndw32_LDFLAGS = 
sha1_SOURCES = sha1.c
sha1_OBJECTS =  sha1.o
sha1_LDADD = $(LDADD)
sha1_DEPENDENCIES = 
sha1_LDFLAGS = 
rmd160_SOURCES = rmd160.c
rmd160_OBJECTS =  rmd160.o
rmd160_LDADD = $(LDADD)
rmd160_DEPENDENCIES = 
rmd160_LDFLAGS = 
md5_SOURCES = md5.c
md5_OBJECTS =  md5.o
md5_LDADD = $(LDADD)
md5_DEPENDENCIES = 
md5_LDFLAGS = 
tiger_SOURCES = tiger.c
tiger_OBJECTS =  tiger.o
tiger_LDADD = $(LDADD)
tiger_DEPENDENCIES = 
tiger_LDFLAGS = 
CFLAGS = -fprofile-arcs -ftest-coverage -Wall
COMPILE = $(CC) $(DEFS) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
CCLD = $(CC)
LINK = $(CCLD) $(AM_CFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
DIST_COMMON =  ChangeLog Makefile.am Makefile.in


DISTFILES = $(DIST_COMMON) $(SOURCES) $(HEADERS) $(TEXINFOS) $(EXTRA_DIST)

TAR = tar
GZIP_ENV = --best
SOURCES = $(libcipher_a_SOURCES) rndlinux.c $(EXTRA_rndlinux_SOURCES) rndunix.c $(EXTRA_rndunix_SOURCES) rndegd.c $(EXTRA_rndegd_SOURCES) rndw32.c $(EXTRA_rndw32_SOURCES) sha1.c $(EXTRA_sha1_SOURCES) rmd160.c $(EXTRA_rmd160_SOURCES) md5.c $(EXTRA_md5_SOURCES) tiger.c $(EXTRA_tiger_SOURCES)
OBJECTS = $(libcipher_a_OBJECTS) rndlinux.o rndunix.o rndegd.o rndw32.o sha1.o rmd160.o md5.o tiger.o

all: all-redirect
.SUFFIXES:
.SUFFIXES: .S .c .o .s
$(srcdir)/Makefile.in: # Makefile.am $(top_srcdir)/configure.in $(ACLOCAL_M4) 
	cd $(top_srcdir) && $(AUTOMAKE) --gnu --include-deps cipher/Makefile

Makefile: $(srcdir)/Makefile.in  $(top_builddir)/config.status
	cd $(top_builddir) \
	  && CONFIG_FILES=$(subdir)/$@ CONFIG_HEADERS= $(SHELL) ./config.status


mostlyclean-noinstLIBRARIES:

clean-noinstLIBRARIES:
	-test -z "$(noinst_LIBRARIES)" || rm -f $(noinst_LIBRARIES)

distclean-noinstLIBRARIES:

maintainer-clean-noinstLIBRARIES:

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

libcipher.a: $(libcipher_a_OBJECTS) $(libcipher_a_DEPENDENCIES)
	-rm -f libcipher.a
	$(AR) cru libcipher.a $(libcipher_a_OBJECTS) $(libcipher_a_LIBADD)
	$(RANLIB) libcipher.a

mostlyclean-pkglibPROGRAMS:

clean-pkglibPROGRAMS:
	-test -z "$(pkglib_PROGRAMS)" || rm -f $(pkglib_PROGRAMS)

distclean-pkglibPROGRAMS:

maintainer-clean-pkglibPROGRAMS:

install-pkglibPROGRAMS: $(pkglib_PROGRAMS)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(pkglibdir)
	@list='$(pkglib_PROGRAMS)'; for p in $$list; do \
	  if test -f $$p; then \
	    echo "  $(INSTALL_PROGRAM) $$p $(DESTDIR)$(pkglibdir)/`echo $$p|sed 's/$(EXEEXT)$$//'|sed '$(transform)'|sed 's/$$/$(EXEEXT)/'`"; \
	     $(INSTALL_PROGRAM) $$p $(DESTDIR)$(pkglibdir)/`echo $$p|sed 's/$(EXEEXT)$$//'|sed '$(transform)'|sed 's/$$/$(EXEEXT)/'`; \
	  else :; fi; \
	done

uninstall-pkglibPROGRAMS:
	@$(NORMAL_UNINSTALL)
	list='$(pkglib_PROGRAMS)'; for p in $$list; do \
	  rm -f $(DESTDIR)$(pkglibdir)/`echo $$p|sed 's/$(EXEEXT)$$//'|sed '$(transform)'|sed 's/$$/$(EXEEXT)/'`; \
	done

rndw32: $(rndw32_OBJECTS) $(rndw32_DEPENDENCIES)
	@rm -f rndw32
	$(LINK) $(rndw32_LDFLAGS) $(rndw32_OBJECTS) $(rndw32_LDADD) $(LIBS)

sha1: $(sha1_OBJECTS) $(sha1_DEPENDENCIES)
	@rm -f sha1
	$(LINK) $(sha1_LDFLAGS) $(sha1_OBJECTS) $(sha1_LDADD) $(LIBS)

rmd160: $(rmd160_OBJECTS) $(rmd160_DEPENDENCIES)
	@rm -f rmd160
	$(LINK) $(rmd160_LDFLAGS) $(rmd160_OBJECTS) $(rmd160_LDADD) $(LIBS)

md5: $(md5_OBJECTS) $(md5_DEPENDENCIES)
	@rm -f md5
	$(LINK) $(md5_LDFLAGS) $(md5_OBJECTS) $(md5_LDADD) $(LIBS)

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

subdir = cipher

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
blowfish.o: blowfish.c ../config.h ../g10defs.h ../include/types.h \
	../include/errors.h blowfish.h dynload.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h
cast5.o: cast5.c ../config.h ../g10defs.h ../include/types.h \
	../include/errors.h cast5.h
cipher.o: cipher.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h des.h blowfish.h cast5.h \
	dynload.h
construct.o: construct.c
des.o: des.c ../config.h ../g10defs.h ../include/types.h \
	../include/errors.h des.h
dsa.o: dsa.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h dsa.h
dynload.o: dynload.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h dynload.h
elgamal.o: elgamal.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h elgamal.h
g10c.o: g10c.c ../config.h ../g10defs.h ../include/mpi.h \
	../include/iobuf.h ../include/types.h ../include/memory.h \
	random.h ../include/cipher.h ../include/../cipher/random.h
md.o: md.c ../config.h ../g10defs.h ../include/util.h ../include/types.h \
	../include/errors.h ../include/mpi.h ../include/iobuf.h \
	../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h dynload.h rmd.h
md5.o: md5.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h dynload.h bithelp.h
primegen.o: primegen.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h
pubkey.o: pubkey.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h elgamal.h dsa.h rsa.h dynload.h
random.o: random.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h rmd.h ../include/ttyio.h \
	../include/i18n.h random.h rand-internal.h dynload.h
rijndael.o: rijndael.c ../config.h ../g10defs.h ../include/types.h \
	../include/util.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h dynload.h
rmd160.o: rmd160.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h rmd.h \
	../include/cipher.h ../include/../cipher/random.h dynload.h \
	bithelp.h
rndlinux.o: rndlinux.c ../config.h ../g10defs.h ../include/types.h \
	../include/util.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h ../include/ttyio.h \
	dynload.h ../include/i18n.h
rndw32.o: rndw32.c ../config.h ../g10defs.h ../include/types.h \
	../include/util.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h dynload.h \
	../include/i18n.h
rsa.o: rsa.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h rsa.h
sha1.o: sha1.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h dynload.h bithelp.h
smallprime.o: smallprime.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h
twofish.o: twofish.c ../config.h ../g10defs.h ../include/types.h \
	../include/util.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h dynload.h

info-am:
info: info-am
dvi-am:
dvi: dvi-am
check-am: all-am
check: check-am
installcheck-am:
installcheck: installcheck-am
install-exec-am: install-pkglibPROGRAMS
install-exec: install-exec-am

install-data-am:
install-data: install-data-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am
install: install-am
uninstall-am: uninstall-pkglibPROGRAMS
uninstall: uninstall-am
all-am: Makefile $(LIBRARIES) $(PROGRAMS)
all-redirect: all-am
install-strip:
	$(MAKE) $(AM_MAKEFLAGS) AM_INSTALL_PROGRAM_FLAGS=-s install
installdirs:
	$(mkinstalldirs)  $(DESTDIR)$(pkglibdir)


mostlyclean-generic:

clean-generic:

distclean-generic:
	-rm -f Makefile $(CONFIG_CLEAN_FILES)
	-rm -f config.cache config.log stamp-h stamp-h[0-9]*

maintainer-clean-generic:
	-test -z "$(BUILT_SOURCES)" || rm -f $(BUILT_SOURCES)
mostlyclean-am:  mostlyclean-noinstLIBRARIES mostlyclean-compile \
		mostlyclean-pkglibPROGRAMS mostlyclean-tags \
		mostlyclean-generic

mostlyclean: mostlyclean-am

clean-am:  clean-noinstLIBRARIES clean-compile clean-pkglibPROGRAMS \
		clean-tags clean-generic mostlyclean-am

clean: clean-am

distclean-am:  distclean-noinstLIBRARIES distclean-compile \
		distclean-pkglibPROGRAMS distclean-tags \
		distclean-generic clean-am

distclean: distclean-am

maintainer-clean-am:  maintainer-clean-noinstLIBRARIES \
		maintainer-clean-compile \
		maintainer-clean-pkglibPROGRAMS maintainer-clean-tags \
		maintainer-clean-generic distclean-am
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."

maintainer-clean: maintainer-clean-am

.PHONY: mostlyclean-noinstLIBRARIES distclean-noinstLIBRARIES \
clean-noinstLIBRARIES maintainer-clean-noinstLIBRARIES \
mostlyclean-compile distclean-compile clean-compile \
maintainer-clean-compile mostlyclean-pkglibPROGRAMS \
distclean-pkglibPROGRAMS clean-pkglibPROGRAMS \
maintainer-clean-pkglibPROGRAMS uninstall-pkglibPROGRAMS \
install-pkglibPROGRAMS tags mostlyclean-tags distclean-tags clean-tags \
maintainer-clean-tags distdir info-am info dvi-am dvi check check-am \
installcheck-am installcheck install-exec-am install-exec \
install-data-am install-data install-am install uninstall-am uninstall \
all-redirect all-am all installdirs mostlyclean-generic \
distclean-generic clean-generic maintainer-clean-generic clean \
mostlyclean distclean maintainer-clean


# If I remember it correct, automake 1.4 has a feature to set
# fooFLAGS depending on the program.  So we should check it out.

tiger: $(srcdir)/tiger.c
	`echo $(COMPILE) $(DYNLINK_MOD_CFLAGS) -o tiger $(srcdir)/tiger.c | \
	    sed -e 's/-O[2-9s]*/-O/g' `

tiger.o: $(srcdir)/tiger.c
	`echo $(COMPILE) -c $(srcdir)/tiger.c | sed -e 's/-O[2-9s]*/-O1/g' `

#twofish: $(srcdir)/twofish.c
#	 `echo $(COMPILE) $(DYNLINK_MOD_CFLAGS) -o twofish $(srcdir)/twofish.c | \
#	     sed -e 's/-O[0-9s]*/  /g' `

twofish: $(srcdir)/twofish.c
	$(COMPILE) $(DYNLINK_MOD_CFLAGS) -o twofish $(srcdir)/twofish.c

#twofish.o: $(srcdir)/twofish.c
#	 `echo $(COMPILE) -c $(srcdir)/twofish.c | sed -e 's/-O[0-9s]*/  /g' `

rndunix: $(srcdir)/rndunix.c
	$(COMPILE) $(DYNLINK_MOD_CFLAGS) -o rndunix $(srcdir)/rndunix.c

rndlinux: $(srcdir)/rndlinux.c
	$(COMPILE) $(DYNLINK_MOD_CFLAGS) -o rndlinux $(srcdir)/rndlinux.c

rndegd: $(srcdir)/rndegd.c
	$(COMPILE) $(DYNLINK_MOD_CFLAGS) -o rndegd $(srcdir)/rndegd.c

# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
