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

srcdir = ../../mpi
top_srcdir = ../..
VPATH = ../../mpi
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

INCLUDES = -I$(top_srcdir)/include
CFLAGS = -g -O2 -Wall 
ASFLAGS = 

EXTRA_DIST = config.links
DISTCLEANFILES = mpi-asm-defs.h                  mpih-add1.S mpih-mul1.S mpih-mul2.S mpih-mul3.S  		 mpih-lshift.S mpih-rshift.S mpih-sub1.S asm-syntax.h sysdep.h

# Note: we only use .S files so we should delete all left over .s
CLEANFILES = _*.s

noinst_LIBRARIES = libmpi.a

# libmpi_a_LDFLAGS =
libmpi_a_SOURCES = longlong.h	  	      mpi-add.c      	      mpi-bit.c      	      mpi-cmp.c      	      mpi-div.c      	      mpi-gcd.c      	      mpi-internal.h 	      mpi-inline.h   	      mpi-inline.c   	      mpi-inv.c      	      mpi-mul.c      	      mpi-pow.c      	      mpi-mpow.c     	      mpi-scan.c     	      mpicoder.c     	      mpih-cmp.c     	      mpih-div.c     	      mpih-mul.c     	      mpiutil.c      	      g10m.c


# Note this objects are actually links, the sourcefiles are
# distributed by special code in dist-hook
common_asm_objects = mpih-mul1.o    		     mpih-mul2.o    		     mpih-mul3.o    		     mpih-add1.o    		     mpih-sub1.o    		     mpih-lshift.o  		     mpih-rshift.o


libmpi_a_DEPENDENCIES = $(common_asm_objects) 
libmpi_a_LIBADD = $(common_asm_objects) 
mkinstalldirs = $(SHELL) $(top_srcdir)/scripts/mkinstalldirs
CONFIG_HEADER = ../config.h
CONFIG_CLEAN_FILES = 
LIBRARIES =  $(noinst_LIBRARIES)


DEFS = -DHAVE_CONFIG_H -I. -I$(srcdir) -I..
CPPFLAGS = 
LDFLAGS = 
LIBS = -lnsl -lgdbm  -lnsl
libmpi_a_OBJECTS =  mpi-add.o mpi-bit.o mpi-cmp.o mpi-div.o mpi-gcd.o \
mpi-inline.o mpi-inv.o mpi-mul.o mpi-pow.o mpi-mpow.o mpi-scan.o \
mpicoder.o mpih-cmp.o mpih-div.o mpih-mul.o mpiutil.o g10m.o
AR = ar
COMPILE = $(CC) $(DEFS) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
CCLD = $(CC)
LINK = $(CCLD) $(AM_CFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
DIST_COMMON =  ChangeLog Makefile.am Makefile.in


DISTFILES = $(DIST_COMMON) $(SOURCES) $(HEADERS) $(TEXINFOS) $(EXTRA_DIST)

TAR = tar
GZIP_ENV = --best
SOURCES = $(libmpi_a_SOURCES)
OBJECTS = $(libmpi_a_OBJECTS)

all: all-redirect
.SUFFIXES:
.SUFFIXES: .S .c .o .s
$(srcdir)/Makefile.in: # Makefile.am $(top_srcdir)/configure.in $(ACLOCAL_M4) 
	cd $(top_srcdir) && $(AUTOMAKE) --gnu --include-deps mpi/Makefile

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

mostlyclean-compile:
	-rm -f *.o core *.core

clean-compile:

distclean-compile:
	-rm -f *.tab.c

maintainer-clean-compile:

libmpi.a: $(libmpi_a_OBJECTS) $(libmpi_a_DEPENDENCIES)
	-rm -f libmpi.a
	$(AR) cru libmpi.a $(libmpi_a_OBJECTS) $(libmpi_a_LIBADD)
	$(RANLIB) libmpi.a

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

subdir = mpi

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
g10m.o: g10m.c ../config.h ../g10defs.h ../include/mpi.h \
	../include/iobuf.h ../include/types.h ../include/memory.h \
	../include/util.h ../include/errors.h
mpi-add.o: mpi-add.c ../config.h ../g10defs.h mpi-internal.h \
	../include/mpi.h ../include/iobuf.h ../include/types.h \
	../include/memory.h mpi-inline.h
mpi-bit.o: mpi-bit.c ../config.h ../g10defs.h mpi-internal.h \
	../include/mpi.h ../include/iobuf.h ../include/types.h \
	../include/memory.h mpi-inline.h longlong.h
mpi-cmp.o: mpi-cmp.c ../config.h ../g10defs.h mpi-internal.h \
	../include/mpi.h ../include/iobuf.h ../include/types.h \
	../include/memory.h mpi-inline.h
mpi-div.o: mpi-div.c ../config.h ../g10defs.h mpi-internal.h \
	../include/mpi.h ../include/iobuf.h ../include/types.h \
	../include/memory.h mpi-inline.h longlong.h
mpi-gcd.o: mpi-gcd.c ../config.h ../g10defs.h mpi-internal.h \
	../include/mpi.h ../include/iobuf.h ../include/types.h \
	../include/memory.h mpi-inline.h
mpi-inline.o: mpi-inline.c ../config.h ../g10defs.h mpi-internal.h \
	../include/mpi.h ../include/iobuf.h ../include/types.h \
	../include/memory.h mpi-inline.h
mpi-inv.o: mpi-inv.c ../config.h ../g10defs.h mpi-internal.h \
	../include/mpi.h ../include/iobuf.h ../include/types.h \
	../include/memory.h mpi-inline.h
mpi-mpow.o: mpi-mpow.c ../config.h ../g10defs.h mpi-internal.h \
	../include/mpi.h ../include/iobuf.h ../include/types.h \
	../include/memory.h mpi-inline.h longlong.h
mpi-mul.o: mpi-mul.c ../config.h ../g10defs.h mpi-internal.h \
	../include/mpi.h ../include/iobuf.h ../include/types.h \
	../include/memory.h mpi-inline.h
mpi-pow.o: mpi-pow.c ../config.h ../g10defs.h mpi-internal.h \
	../include/mpi.h ../include/iobuf.h ../include/types.h \
	../include/memory.h mpi-inline.h longlong.h
mpi-scan.o: mpi-scan.c ../config.h ../g10defs.h mpi-internal.h \
	../include/mpi.h ../include/iobuf.h ../include/types.h \
	../include/memory.h mpi-inline.h longlong.h
mpicoder.o: mpicoder.c ../config.h ../g10defs.h ../include/mpi.h \
	../include/iobuf.h ../include/types.h ../include/memory.h \
	mpi-internal.h mpi-inline.h ../include/util.h \
	../include/errors.h
mpih-cmp.o: mpih-cmp.c ../config.h ../g10defs.h mpi-internal.h \
	../include/mpi.h ../include/iobuf.h ../include/types.h \
	../include/memory.h mpi-inline.h
mpih-div.o: mpih-div.c ../config.h ../g10defs.h mpi-internal.h \
	../include/mpi.h ../include/iobuf.h ../include/types.h \
	../include/memory.h mpi-inline.h longlong.h
mpih-mul.o: mpih-mul.c ../config.h ../g10defs.h mpi-internal.h \
	../include/mpi.h ../include/iobuf.h ../include/types.h \
	../include/memory.h mpi-inline.h longlong.h
mpiutil.o: mpiutil.c ../config.h ../g10defs.h ../include/mpi.h \
	../include/iobuf.h ../include/types.h ../include/memory.h \
	mpi-internal.h mpi-inline.h ../include/util.h \
	../include/errors.h

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
all-am: Makefile $(LIBRARIES)
all-redirect: all-am
install-strip:
	$(MAKE) $(AM_MAKEFLAGS) AM_INSTALL_PROGRAM_FLAGS=-s install
installdirs:


mostlyclean-generic:

clean-generic:
	-test -z "$(CLEANFILES)" || rm -f $(CLEANFILES)

distclean-generic:
	-rm -f Makefile $(CONFIG_CLEAN_FILES)
	-rm -f config.cache config.log stamp-h stamp-h[0-9]*
	-test -z "$(DISTCLEANFILES)" || rm -f $(DISTCLEANFILES)

maintainer-clean-generic:
mostlyclean-am:  mostlyclean-noinstLIBRARIES mostlyclean-compile \
		mostlyclean-tags mostlyclean-generic

mostlyclean: mostlyclean-am

clean-am:  clean-noinstLIBRARIES clean-compile clean-tags clean-generic \
		mostlyclean-am

clean: clean-am

distclean-am:  distclean-noinstLIBRARIES distclean-compile \
		distclean-tags distclean-generic clean-am

distclean: distclean-am

maintainer-clean-am:  maintainer-clean-noinstLIBRARIES \
		maintainer-clean-compile maintainer-clean-tags \
		maintainer-clean-generic distclean-am
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."

maintainer-clean: maintainer-clean-am

.PHONY: mostlyclean-noinstLIBRARIES distclean-noinstLIBRARIES \
clean-noinstLIBRARIES maintainer-clean-noinstLIBRARIES \
mostlyclean-compile distclean-compile clean-compile \
maintainer-clean-compile tags mostlyclean-tags distclean-tags \
clean-tags maintainer-clean-tags distdir info-am info dvi-am dvi check \
check-am installcheck-am installcheck install-exec-am install-exec \
install-data-am install-data install-am install uninstall-am uninstall \
all-redirect all-am all installdirs mostlyclean-generic \
distclean-generic clean-generic maintainer-clean-generic clean \
mostlyclean distclean maintainer-clean


# cancel the default rules used by libtool which do not really
# work and add one to cpp .S files
.S.o:
	 $(CPP) $(INCLUDES) $(DEFS) $< | grep -v '^#' > _$*.s
	 $(COMPILE) -c _$*.s
	 mv -f _$*.o $*.o

.S.lo:

# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
