check_PROGRAMS = base

limoi_base_LDADD = $(top_builddir)/src/liblimoi-base.la -lpthread \
	$(LIMUTIL_LIBS) $(LIMOI_LIBS)
limoi_base_CFLAGS = -I$(top_srcdir)/include \
	$(LIMOI_CFLAGS) $(LIMUTIL_CFLAGS)

base_SOURCES = base.c
base_LDADD = $(limoi_base_LDADD)
base_CFLAGS = $(limoi_base_CFLAGS)
