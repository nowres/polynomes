## Process this file with automake to produce Makefile.in

## Created by Anjuta
prefix=/usr

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" 

AM_CFLAGS =\
	 -Wall\
	 -g

lib_LTLIBRARIES = libpolynomes.la


libpolynomes_la_SOURCES = \
	monome.c               \
	monome.h               \
	polynome.c

libpolynomes_la_LDFLAGS = 

libpolynomes_la_LIBADD = 

include_HEADERS = \
	polynomes.h

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libpolynomes-0.1.pc

EXTRA_DIST = \
	libpolynomes-0.1.pc.in
