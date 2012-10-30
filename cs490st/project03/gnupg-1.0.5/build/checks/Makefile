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

srcdir = ../../checks
top_srcdir = ../..
VPATH = ../../checks
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

GPG_DEARMOR = ../g10/gpg --no-options --no-greeting --batch --quiet --yes --dearmor
GPG_IMPORT = ../g10/gpg --homedir . --quiet --yes --import

TESTS = version.test mds.test 	decrypt.test decrypt-dsa.test 	sigs.test sigs-dsa.test 	encrypt.test encrypt-dsa.test  	seat.test clearsig.test encryptp.test detach.test 	armsigs.test armencrypt.test armencryptp.test 	signencrypt.test signencrypt-dsa.test 	armsignencrypt.test armdetach.test 	armdetachm.test detachm.test genkey1024.test 	conventional.test conventional-mdc.test 	multisig.test


TEST_FILES = pubring.asc secring.asc plain-1o.asc plain-2o.asc plain-3o.asc 	     plain-1.asc plain-2.asc plain-3.asc plain-1-pgp.asc 	     pubring.pkr.asc secring.skr.asc secdemo.asc pubdemo.asc options.in


DATA_FILES = data-500 data-9000 data-32000 data-80000 plain-large

EXTRA_DIST = defs.inc run-gpg run-gpg.patterns $(TESTS) $(TEST_FILES) 	     mkdemodirs signdemokey

CLEANFILES = prepared.stamp x y yy z out err  $(DATA_FILES) 	     plain-1 plain-2 plain-3 options trustdb.gpg *.lock .\#lk* 	     pubring.gpg secring.gpg pubring.pkr secring.skr options

DISTCLEANFILES = pubring.gpg~
mkinstalldirs = $(SHELL) $(top_srcdir)/scripts/mkinstalldirs
CONFIG_HEADER = ../config.h
CONFIG_CLEAN_FILES = 
DIST_COMMON =  ChangeLog Makefile.am Makefile.in


DISTFILES = $(DIST_COMMON) $(SOURCES) $(HEADERS) $(TEXINFOS) $(EXTRA_DIST)

TAR = tar
GZIP_ENV = --best
all: all-redirect
.SUFFIXES:
$(srcdir)/Makefile.in: # Makefile.am $(top_srcdir)/configure.in $(ACLOCAL_M4) 
	cd $(top_srcdir) && $(AUTOMAKE) --gnu --include-deps checks/Makefile

Makefile: $(srcdir)/Makefile.in  $(top_builddir)/config.status
	cd $(top_builddir) \
	  && CONFIG_FILES=$(subdir)/$@ CONFIG_HEADERS= $(SHELL) ./config.status

tags: TAGS
TAGS:


distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)

subdir = checks

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
check-TESTS: $(TESTS)
	@failed=0; all=0; \
	srcdir=$(srcdir); export srcdir; \
	for tst in $(TESTS); do \
	  if test -f $$tst; then dir=.; \
	  else dir="$(srcdir)"; fi; \
	  if $(TESTS_ENVIRONMENT) $$dir/$$tst; then \
	    all=`expr $$all + 1`; \
	    echo "PASS: $$tst"; \
	  elif test $$? -ne 77; then \
	    all=`expr $$all + 1`; \
	    failed=`expr $$failed + 1`; \
	    echo "FAIL: $$tst"; \
	  fi; \
	done; \
	if test "$$failed" -eq 0; then \
	  banner="All $$all tests passed"; \
	else \
	  banner="$$failed of $$all tests failed"; \
	fi; \
	dashes=`echo "$$banner" | sed s/./=/g`; \
	echo "$$dashes"; \
	echo "$$banner"; \
	echo "$$dashes"; \
	test "$$failed" -eq 0
info-am:
info: info-am
dvi-am:
dvi: dvi-am
check-am: all-am
	$(MAKE) $(AM_MAKEFLAGS) check-TESTS
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
all-am: Makefile all-local
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
mostlyclean-am:  mostlyclean-generic

mostlyclean: mostlyclean-am

clean-am:  clean-generic mostlyclean-am

clean: clean-am

distclean-am:  distclean-generic clean-am distclean-local

distclean: distclean-am

maintainer-clean-am:  maintainer-clean-generic distclean-am
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."

maintainer-clean: maintainer-clean-am

.PHONY: tags distdir check-TESTS info-am info dvi-am dvi check check-am \
installcheck-am installcheck install-exec-am install-exec \
install-data-am install-data install-am install uninstall-am uninstall \
all-local all-redirect all-am all installdirs mostlyclean-generic \
distclean-generic clean-generic maintainer-clean-generic clean \
mostlyclean distclean maintainer-clean


all-local: prepared.stamp

distclean-local:
	./mkdemodirs --clean

prepared.stamp: ./pubring.gpg ./secring.gpg ./plain-1 ./plain-2 ./plain-3 \
		./pubring.pkr ./secring.skr ./options $(DATA_FILES)
	 $(GPG_IMPORT) $(srcdir)/pubdemo.asc	 
	 echo timestamp >./prepared.stamp

./options: $(srcdir)/options.in
	cat $(srcdir)/options.in >./options

./pubring.gpg: $(srcdir)/pubring.asc $(srcdir)/pubdemo.asc
	 $(GPG_DEARMOR) -o ./pubring.gpg $(srcdir)/pubring.asc

./secring.gpg: $(srcdir)/secring.asc
	 $(GPG_DEARMOR) -o ./secring.gpg $(srcdir)/secring.asc

./pubring.pkr: $(srcdir)/pubring.pkr.asc
	 $(GPG_DEARMOR) -o ./pubring.pkr $(srcdir)/pubring.pkr.asc

./secring.skr: $(srcdir)/secring.skr.asc
	 $(GPG_DEARMOR) -o ./secring.skr $(srcdir)/secring.skr.asc

./plain-1: $(srcdir)/plain-1o.asc
	 $(GPG_DEARMOR) -o ./plain-1 $(srcdir)/plain-1o.asc

./plain-2: $(srcdir)/plain-2o.asc
	 $(GPG_DEARMOR) -o ./plain-2 $(srcdir)/plain-2o.asc

./plain-3: $(srcdir)/plain-3o.asc
	 $(GPG_DEARMOR) -o ./plain-3 $(srcdir)/plain-3o.asc

data-500:
	../tools/mk-tdata   500  >data-500
data-9000:
	../tools/mk-tdata  9000  >data-9000
data-32000:
	../tools/mk-tdata 32000  >data-32000
data-80000:
	../tools/mk-tdata 80000  >data-80000
plain-large:
	cat $(srcdir)/../doc/HACKING \
	    $(srcdir)/../doc/DETAILS \
	    $(srcdir)/../doc/FAQ	 >plain-large

# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
