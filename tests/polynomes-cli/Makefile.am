## Process this file with automake to produce Makefile.in

## Created by Anjuta

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\"

AM_CFLAGS =\
	 -Wall

bin_PROGRAMS = polynomes_cli

polynomes_cli_SOURCES = polynomes-cli.c

polynomes_cli_LDADD = $(top_builddir)/src/polynome.o
