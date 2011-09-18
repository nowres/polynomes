## Process this file with automake to produce Makefile.in
## Created by Anjuta

SUBDIRS = src 

libpolynomesdocdir = ${prefix}/doc/libpolynomes
libpolynomesdoc_DATA = \
	README\
	COPYING\
	AUTHORS\
	ChangeLog\
	INSTALL\
	NEWS


EXTRA_DIST = $(libpolynomesdoc_DATA)


# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(libpolynomesdocdir)
