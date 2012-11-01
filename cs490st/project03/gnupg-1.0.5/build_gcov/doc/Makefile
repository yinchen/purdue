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

srcdir = ../../doc
top_srcdir = ../..
VPATH = ../../doc
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

AUTOMAKE_OPTIONS = no-texinfo.tex

EXTRA_DIST = DETAILS gpg.sgml gpg.1 gpgv.sgml gpgv.1 faq.raw FAQ faq.html              HACKING OpenPGP README.W32 


man_MANS = gpg.1 gpgv.1

info_TEXINFOS = gpg.texi gpgv.texi

# Need this to avoid building of dvis with automake 1.4
DVIS = 

pkgdata_DATA = FAQ faq.html

BUILT_SOURCES = FAQ faq.html 
# we can't add gpg.texi gpgv.texi here because automake does not like them to
# be built files. 

CLEANFILES = faq.raw.xref gpg.xml gpgv.xml
mkinstalldirs = $(SHELL) $(top_srcdir)/scripts/mkinstalldirs
CONFIG_HEADER = ../config.h
CONFIG_CLEAN_FILES = 
TEXI2DVI = texi2dvi
TEXINFO_TEX = $(top_srcdir)/scripts/texinfo.tex
INFO_DEPS = gpg.info gpgv.info
TEXINFOS = gpg.texi gpgv.texi
man1dir = $(mandir)/man1
MANS = $(man_MANS)

NROFF = nroff
DATA =  $(pkgdata_DATA)

DIST_COMMON =  ChangeLog Makefile.am Makefile.in


DISTFILES = $(DIST_COMMON) $(SOURCES) $(HEADERS) $(TEXINFOS) $(EXTRA_DIST)

TAR = tar
GZIP_ENV = --best
all: all-redirect
.SUFFIXES:
.SUFFIXES: .dvi .info .ps .texi .texinfo .txi
$(srcdir)/Makefile.in: # Makefile.am $(top_srcdir)/configure.in $(ACLOCAL_M4) 
	cd $(top_srcdir) && $(AUTOMAKE) --gnu --include-deps doc/Makefile

Makefile: $(srcdir)/Makefile.in  $(top_builddir)/config.status
	cd $(top_builddir) \
	  && CONFIG_FILES=$(subdir)/$@ CONFIG_HEADERS= $(SHELL) ./config.status


gpg.info: gpg.texi
gpg.dvi: gpg.texi


gpgv.info: gpgv.texi
gpgv.dvi: gpgv.texi


DVIPS = dvips

.texi.info:
	@cd $(srcdir) && rm -f $@ $@-[0-9] $@-[0-9][0-9]
	cd $(srcdir) \
	  && $(MAKEINFO) `echo $< | sed 's,.*/,,'`

.texi.dvi:
	TEXINPUTS=$(top_srcdir)/scripts/texinfo.tex:$$TEXINPUTS \
	  MAKEINFO='$(MAKEINFO) -I $(srcdir)' $(TEXI2DVI) $<

.texi:
	@cd $(srcdir) && rm -f $@ $@-[0-9] $@-[0-9][0-9]
	cd $(srcdir) \
	  && $(MAKEINFO) `echo $< | sed 's,.*/,,'`

.texinfo.info:
	@cd $(srcdir) && rm -f $@ $@-[0-9] $@-[0-9][0-9]
	cd $(srcdir) \
	  && $(MAKEINFO) `echo $< | sed 's,.*/,,'`

.texinfo:
	@cd $(srcdir) && rm -f $@ $@-[0-9] $@-[0-9][0-9]
	cd $(srcdir) \
	  && $(MAKEINFO) `echo $< | sed 's,.*/,,'`

.texinfo.dvi:
	TEXINPUTS=$(top_srcdir)/scripts/texinfo.tex:$$TEXINPUTS \
	  MAKEINFO='$(MAKEINFO) -I $(srcdir)' $(TEXI2DVI) $<

.txi.info:
	@cd $(srcdir) && rm -f $@ $@-[0-9] $@-[0-9][0-9]
	cd $(srcdir) \
	  && $(MAKEINFO) `echo $< | sed 's,.*/,,'`

.txi.dvi:
	TEXINPUTS=$(top_srcdir)/scripts/texinfo.tex:$$TEXINPUTS \
	  MAKEINFO='$(MAKEINFO) -I $(srcdir)' $(TEXI2DVI) $<

.txi:
	@cd $(srcdir) && rm -f $@ $@-[0-9] $@-[0-9][0-9]
	cd $(srcdir) \
	  && $(MAKEINFO) `echo $< | sed 's,.*/,,'`
.dvi.ps:
	$(DVIPS) $< -o $@

install-info-am: $(INFO_DEPS)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(infodir)
	@list='$(INFO_DEPS)'; \
	for file in $$list; do \
	  d=$(srcdir); \
	  for ifile in `cd $$d && echo $$file $$file-[0-9] $$file-[0-9][0-9]`; do \
	    if test -f $$d/$$ifile; then \
	      echo " $(INSTALL_DATA) $$d/$$ifile $(DESTDIR)$(infodir)/$$ifile"; \
	      $(INSTALL_DATA) $$d/$$ifile $(DESTDIR)$(infodir)/$$ifile; \
	    else : ; fi; \
	  done; \
	done
	@$(POST_INSTALL)
	@if $(SHELL) -c 'install-info --version | sed 1q | fgrep -s -v -i debian' >/dev/null 2>&1; then \
	  list='$(INFO_DEPS)'; \
	  for file in $$list; do \
	    echo " install-info --info-dir=$(DESTDIR)$(infodir) $(DESTDIR)$(infodir)/$$file";\
	    install-info --info-dir=$(DESTDIR)$(infodir) $(DESTDIR)$(infodir)/$$file || :;\
	  done; \
	else : ; fi

uninstall-info:
	$(PRE_UNINSTALL)
	@if $(SHELL) -c 'install-info --version | sed 1q | fgrep -s -v -i debian' >/dev/null 2>&1; then \
	  ii=yes; \
	else ii=; fi; \
	list='$(INFO_DEPS)'; \
	for file in $$list; do \
	  test -z "$ii" \
	    || install-info --info-dir=$(DESTDIR)$(infodir) --remove $$file; \
	done
	@$(NORMAL_UNINSTALL)
	list='$(INFO_DEPS)'; \
	for file in $$list; do \
	  (cd $(DESTDIR)$(infodir) && rm -f $$file $$file-[0-9] $$file-[0-9][0-9]); \
	done

dist-info: $(INFO_DEPS)
	list='$(INFO_DEPS)'; \
	for base in $$list; do \
	  d=$(srcdir); \
	  for file in `cd $$d && eval echo $$base*`; do \
	    test -f $(distdir)/$$file \
	    || ln $$d/$$file $(distdir)/$$file 2> /dev/null \
	    || cp -p $$d/$$file $(distdir)/$$file; \
	  done; \
	done

mostlyclean-aminfo:
	-rm -f gpg.aux gpg.cp gpg.cps gpg.dvi gpg.fn gpg.fns gpg.ky gpg.kys \
	  gpg.ps gpg.log gpg.pg gpg.toc gpg.tp gpg.tps gpg.vr gpg.vrs \
	  gpg.op gpg.tr gpg.cv gpg.cn gpgv.aux gpgv.cp gpgv.cps \
	  gpgv.dvi gpgv.fn gpgv.fns gpgv.ky gpgv.kys gpgv.ps gpgv.log \
	  gpgv.pg gpgv.toc gpgv.tp gpgv.tps gpgv.vr gpgv.vrs gpgv.op \
	  gpgv.tr gpgv.cv gpgv.cn

clean-aminfo:

distclean-aminfo:

maintainer-clean-aminfo:
	cd $(srcdir) && for i in $(INFO_DEPS); do \
	  rm -f $$i; \
	  if test "`echo $$i-[0-9]*`" != "$$i-[0-9]*"; then \
	    rm -f $$i-[0-9]*; \
	  fi; \
	done

install-man1:
	$(mkinstalldirs) $(DESTDIR)$(man1dir)
	@list='$(man1_MANS)'; \
	l2='$(man_MANS)'; for i in $$l2; do \
	  case "$$i" in \
	    *.1*) list="$$list $$i" ;; \
	  esac; \
	done; \
	for i in $$list; do \
	  if test -f $(srcdir)/$$i; then file=$(srcdir)/$$i; \
	  else file=$$i; fi; \
	  ext=`echo $$i | sed -e 's/^.*\\.//'`; \
	  inst=`echo $$i | sed -e 's/\\.[0-9a-z]*$$//'`; \
	  inst=`echo $$inst | sed '$(transform)'`.$$ext; \
	  echo " $(INSTALL_DATA) $$file $(DESTDIR)$(man1dir)/$$inst"; \
	  $(INSTALL_DATA) $$file $(DESTDIR)$(man1dir)/$$inst; \
	done

uninstall-man1:
	@list='$(man1_MANS)'; \
	l2='$(man_MANS)'; for i in $$l2; do \
	  case "$$i" in \
	    *.1*) list="$$list $$i" ;; \
	  esac; \
	done; \
	for i in $$list; do \
	  ext=`echo $$i | sed -e 's/^.*\\.//'`; \
	  inst=`echo $$i | sed -e 's/\\.[0-9a-z]*$$//'`; \
	  inst=`echo $$inst | sed '$(transform)'`.$$ext; \
	  echo " rm -f $(DESTDIR)$(man1dir)/$$inst"; \
	  rm -f $(DESTDIR)$(man1dir)/$$inst; \
	done
install-man: $(MANS)
	@$(NORMAL_INSTALL)
	$(MAKE) $(AM_MAKEFLAGS) install-man1
uninstall-man:
	@$(NORMAL_UNINSTALL)
	$(MAKE) $(AM_MAKEFLAGS) uninstall-man1

install-pkgdataDATA: $(pkgdata_DATA)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(pkgdatadir)
	@list='$(pkgdata_DATA)'; for p in $$list; do \
	  if test -f $(srcdir)/$$p; then \
	    echo " $(INSTALL_DATA) $(srcdir)/$$p $(DESTDIR)$(pkgdatadir)/$$p"; \
	    $(INSTALL_DATA) $(srcdir)/$$p $(DESTDIR)$(pkgdatadir)/$$p; \
	  else if test -f $$p; then \
	    echo " $(INSTALL_DATA) $$p $(DESTDIR)$(pkgdatadir)/$$p"; \
	    $(INSTALL_DATA) $$p $(DESTDIR)$(pkgdatadir)/$$p; \
	  fi; fi; \
	done

uninstall-pkgdataDATA:
	@$(NORMAL_UNINSTALL)
	list='$(pkgdata_DATA)'; for p in $$list; do \
	  rm -f $(DESTDIR)$(pkgdatadir)/$$p; \
	done
tags: TAGS
TAGS:


distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)

subdir = doc

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
	$(MAKE) $(AM_MAKEFLAGS) top_distdir="$(top_distdir)" distdir="$(distdir)" dist-info
	$(MAKE) $(AM_MAKEFLAGS) top_distdir="$(top_distdir)" distdir="$(distdir)" dist-hook
info-am: $(INFO_DEPS)
info: info-am
dvi-am: $(DVIS)
dvi: dvi-am
check-am: all-am
check: check-am
installcheck-am:
installcheck: installcheck-am
install-exec-am:
install-exec: install-exec-am

install-data-am: install-info-am install-man install-pkgdataDATA
install-data: install-data-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am
install: install-am
uninstall-am: uninstall-info uninstall-man uninstall-pkgdataDATA
uninstall: uninstall-am
all-am: Makefile $(INFO_DEPS) $(MANS) $(DATA)
all-redirect: all-am
install-strip:
	$(MAKE) $(AM_MAKEFLAGS) AM_INSTALL_PROGRAM_FLAGS=-s install
installdirs:
	$(mkinstalldirs)  $(DESTDIR)$(infodir) $(DESTDIR)$(mandir)/man1 \
		$(DESTDIR)$(pkgdatadir)


mostlyclean-generic:

clean-generic:
	-test -z "$(CLEANFILES)" || rm -f $(CLEANFILES)

distclean-generic:
	-rm -f Makefile $(CONFIG_CLEAN_FILES)
	-rm -f config.cache config.log stamp-h stamp-h[0-9]*

maintainer-clean-generic:
	-test -z "$(BUILT_SOURCES)" || rm -f $(BUILT_SOURCES)
mostlyclean-am:  mostlyclean-aminfo mostlyclean-generic

mostlyclean: mostlyclean-am

clean-am:  clean-aminfo clean-generic mostlyclean-am

clean: clean-am

distclean-am:  distclean-aminfo distclean-generic clean-am

distclean: distclean-am

maintainer-clean-am:  maintainer-clean-aminfo maintainer-clean-generic \
		distclean-am
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."

maintainer-clean: maintainer-clean-am

.PHONY: install-info-am uninstall-info mostlyclean-aminfo \
distclean-aminfo clean-aminfo maintainer-clean-aminfo install-man1 \
uninstall-man1 install-man uninstall-man uninstall-pkgdataDATA \
install-pkgdataDATA tags distdir info-am info dvi-am dvi check check-am \
installcheck-am installcheck install-exec-am install-exec \
install-data-am install-data install-am install uninstall-am uninstall \
all-redirect all-am all installdirs mostlyclean-generic \
distclean-generic clean-generic maintainer-clean-generic clean \
mostlyclean distclean maintainer-clean


%.texi : %.xml
#	docbook2texi $< | sed 's,--,---,' >$@
	: Warning: missing docbook to texinfo tools, cannot make $@
	touch $@

%.xml : %.sgml
#	sgml2xml -x lower $< >$@
	: Warning: missing docbook to texinfo tools, cannot make $@
	touch $@

%.1 : %.sgml
#	docbook-to-man $<  >$@
	: Warning: missing docbook-to-man, cannot make $@
	echo ".TH $< 1"   >$@
	echo "No man page due to missing docbook-to-man" >>$@

FAQ : faq.raw
	$(FAQPROG) -f $<  $@ || $(FAQPROG) -f $< $@

faq.html : faq.raw
	$(FAQPROG) -h -f $< $@ 2>&1 || $(FAQPROG) -h -f $< $@

dist-hook:
	@if test `wc -c < gpg.1` -lt 200; then \
	    echo 'ERROR: dummy man page'; false; fi

# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
