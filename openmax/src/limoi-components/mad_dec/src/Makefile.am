limoicomponent_LTLIBRARIES = liblimoi-mad-dec.la

liblimoi_mad_dec_la_SOURCES = mad.c

liblimoi_mad_dec_la_CFLAGS = -Wall -Werror -fno-strict-aliasing \
	$(LIMOI_CFLAGS) $(LIMOIBASE_CFLAGS) $(MAD_CFLAGS) \
	-I$(top_srcdir)/include

liblimoi_mad_dec_la_LIBADD = $(LIMOIBASE_LIBS) $(MAD_LIBS)

liblimoi_mad_dec_la_LDFLAGS = $(limoicomponent_ldflags)

