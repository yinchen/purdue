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

srcdir = ../../tools
top_srcdir = ../..
VPATH = ../../tools
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
DYNLINK_MOD_CFLAGS = -shared -fPIC
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

EXTRA_DIST = lspgpot ring-a-party mail-signed-keys
INCLUDES = -I$(top_srcdir)/include -I$(top_srcdir)/intl
needed_libs = ../cipher/libcipher.a  	      ../mpi/libmpi.a ../util/libutil.a 


noinst_PROGRAMS = mpicalc bftest clean-sat mk-tdata shmtest

mpicalc_SOURCES = mpicalc.c

bftest_SOURCES = bftest.c

clean_sat_SOURCES = clean-sat.c
mk_tdata_SOURCES = mk-tdata.c
shmtest_SOURCES = shmtest.c

mpicalc_LDADD = $(needed_libs)
bftest_LDADD = $(needed_libs)

shmtest_LDADD = $(needed_libs)
mkinstalldirs = $(SHELL) $(top_srcdir)/scripts/mkinstalldirs
CONFIG_HEADER = ../config.h
CONFIG_CLEAN_FILES = 
PROGRAMS =  $(noinst_PROGRAMS)


DEFS = -DHAVE_CONFIG_H -I. -I$(srcdir) -I..
CPPFLAGS = 
LDFLAGS = 
LIBS = -lz -ldl -lnsl -lgdbm  -lnsl
mpicalc_OBJECTS =  mpicalc.o
mpicalc_DEPENDENCIES =  ../cipher/libcipher.a ../mpi/libmpi.a \
../util/libutil.a
mpicalc_LDFLAGS = 
bftest_OBJECTS =  bftest.o
bftest_DEPENDENCIES =  ../cipher/libcipher.a ../mpi/libmpi.a \
../util/libutil.a
bftest_LDFLAGS = 
clean_sat_OBJECTS =  clean-sat.o
clean_sat_LDADD = $(LDADD)
clean_sat_DEPENDENCIES = 
clean_sat_LDFLAGS = 
mk_tdata_OBJECTS =  mk-tdata.o
mk_tdata_LDADD = $(LDADD)
mk_tdata_DEPENDENCIES = 
mk_tdata_LDFLAGS = 
shmtest_OBJECTS =  shmtest.o
shmtest_DEPENDENCIES =  ../cipher/libcipher.a ../mpi/libmpi.a \
../util/libutil.a
shmtest_LDFLAGS = 
CFLAGS = -fprofile-arcs -ftest-coverage -Wall
COMPILE = $(CC) $(DEFS) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
CCLD = $(CC)
LINK = $(CCLD) $(AM_CFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
DIST_COMMON =  ChangeLog Makefile.am Makefile.in


DISTFILES = $(DIST_COMMON) $(SOURCES) $(HEADERS) $(TEXINFOS) $(EXTRA_DIST)

TAR = tar
GZIP_ENV = --best
SOURCES = $(mpicalc_SOURCES) $(bftest_SOURCES) $(clean_sat_SOURCES) $(mk_tdata_SOURCES) $(shmtest_SOURCES)
OBJECTS = $(mpicalc_OBJECTS) $(bftest_OBJECTS) $(clean_sat_OBJECTS) $(mk_tdata_OBJECTS) $(shmtest_OBJECTS)

all: all-redirect
.SUFFIXES:
.SUFFIXES: .S .c .o .s
$(srcdir)/Makefile.in: # Makefile.am $(top_srcdir)/configure.in $(ACLOCAL_M4) 
	cd $(top_srcdir) && $(AUTOMAKE) --gnu --include-deps tools/Makefile

Makefile: $(srcdir)/Makefile.in  $(top_builddir)/config.status
	cd $(top_builddir) \
	  && CONFIG_FILES=$(subdir)/$@ CONFIG_HEADERS= $(SHELL) ./config.status


mostlyclean-noinstPROGRAMS:

clean-noinstPROGRAMS:
	-test -z "$(noinst_PROGRAMS)" || rm -f $(noinst_PROGRAMS)

distclean-noinstPROGRAMS:

maintainer-clean-noinstPROGRAMS:

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

mpicalc: $(mpicalc_OBJECTS) $(mpicalc_DEPENDENCIES)
	@rm -f mpicalc
	$(LINK) $(mpicalc_LDFLAGS) $(mpicalc_OBJECTS) $(mpicalc_LDADD) $(LIBS)

bftest: $(bftest_OBJECTS) $(bftest_DEPENDENCIES)
	@rm -f bftest
	$(LINK) $(bftest_LDFLAGS) $(bftest_OBJECTS) $(bftest_LDADD) $(LIBS)

clean-sat: $(clean_sat_OBJECTS) $(clean_sat_DEPENDENCIES)
	@rm -f clean-sat
	$(LINK) $(clean_sat_LDFLAGS) $(clean_sat_OBJECTS) $(clean_sat_LDADD) $(LIBS)

mk-tdata: $(mk_tdata_OBJECTS) $(mk_tdata_DEPENDENCIES)
	@rm -f mk-tdata
	$(LINK) $(mk_tdata_LDFLAGS) $(mk_tdata_OBJECTS) $(mk_tdata_LDADD) $(LIBS)

shmtest: $(shmtest_OBJECTS) $(shmtest_DEPENDENCIES)
	@rm -f shmtest
	$(LINK) $(shmtest_LDFLAGS) $(shmtest_OBJECTS) $(shmtest_LDADD) $(LIBS)

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

subdir = tools

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
bftest.o: bftest.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h ../include/cipher.h \
	../include/../cipher/random.h ../include/i18n.h
clean-sat.o: clean-sat.c
mk-tdata.o: mk-tdata.c ../config.h ../g10defs.h
mpicalc.o: mpicalc.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h ../include/i18n.h
shmtest.o: shmtest.c ../config.h ../g10defs.h ../include/util.h \
	../include/types.h ../include/errors.h ../include/mpi.h \
	../include/iobuf.h ../include/memory.h ../include/ttyio.h \
	../include/i18n.h

info-am:
info: info-am
dvi-am:
dvi: dvi-am
check-am: all-am
check: check-am
installcheck-am:
installcheck: installcheck-am
install-exec-am:
install-exec: install-exec-am

install-data-am:
install-data: install-data-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am
install: install-am
uninstall-am:
uninstall: uninstall-am
all-am: Makefile $(PROGRAMS)
all-redirect: all-am
install-strip:
	$(MAKE) $(AM_MAKEFLAGS) AM_INSTALL_PROGRAM_FLAGS=-s install
installdirs:


mostlyclean-generic:

clean-generic:

distclean-generic:
	-rm -f Makefile $(CONFIG_CLEAN_FILES)
	-rm -f config.cache config.log stamp-h stamp-h[0-9]*

maintainer-clean-generic:
mostlyclean-am:  mostlyclean-noinstPROGRAMS mostlyclean-compile \
		mostlyclean-tags mostlyclean-generic

mostlyclean: mostlyclean-am

clean-am:  clean-noinstPROGRAMS clean-compile clean-tags clean-generic \
		mostlyclean-am

clean: clean-am

distclean-am:  distclean-noinstPROGRAMS distclean-compile distclean-tags \
		distclean-generic clean-am

distclean: distclean-am

maintainer-clean-am:  maintainer-clean-noinstPROGRAMS \
		maintainer-clean-compile maintainer-clean-tags \
		maintainer-clean-generic distclean-am
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."

maintainer-clean: maintainer-clean-am

.PHONY: mostlyclean-noinstPROGRAMS distclean-noinstPROGRAMS \
clean-noinstPROGRAMS maintainer-clean-noinstPROGRAMS \
mostlyclean-compile distclean-compile clean-compile \
maintainer-clean-compile tags mostlyclean-tags distclean-tags \
clean-tags maintainer-clean-tags distdir info-am info dvi-am dvi check \
check-am installcheck-am installcheck install-exec-am install-exec \
install-data-am install-data install-am install uninstall-am uninstall \
all-redirect all-am all installdirs mostlyclean-generic \
distclean-generic clean-generic maintainer-clean-generic clean \
mostlyclean distclean maintainer-clean


mpicalc bftest shmtest: $(needed_libs)

# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
