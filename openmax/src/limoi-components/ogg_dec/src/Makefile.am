limoicomponent_LTLIBRARIES = liblimoi-ogg-dec.la

liblimoi_ogg_dec_la_SOURCES = ogg.c

liblimoi_ogg_dec_la_CFLAGS = -Wall -Werror -fno-strict-aliasing \
	$(LIMOI_CFLAGS) $(LIMOIBASE_CFLAGS) $(VORBIS_CFLAGS) \
	-I$(top_srcdir)/include

liblimoi_ogg_dec_la_LIBADD = $(LIMOIBASE_LIBS) $(VORBIS_LIBS)

liblimoi_ogg_dec_la_LDFLAGS = $(limoicomponent_ldflags)

