limoicomponent_LTLIBRARIES = liblimoi-alsa-sink.la

liblimoi_alsa_sink_la_SOURCES = alsa.c

liblimoi_alsa_sink_la_CFLAGS = -Wall -Werror -fno-strict-aliasing \
	$(LIMOI_CFLAGS) $(LIMOIBASE_CFLAGS) $(ALSA_CFLAGS) \
	-I$(top_srcdir)/include

liblimoi_alsa_sink_la_LIBADD = $(LIMOIBASE_LIBS) $(ALSA_LIBS)

liblimoi_alsa_sink_la_LDFLAGS = $(limoicomponent_ldflags)

