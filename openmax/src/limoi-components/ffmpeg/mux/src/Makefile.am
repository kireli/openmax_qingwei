limoicomponent_LTLIBRARIES = liblimoi-ffmpeg-mux.la

liblimoi_ffmpeg_mux_la_SOURCES = mux.c

liblimoi_ffmpeg_mux_la_CFLAGS = -Wall -Werror -fno-strict-aliasing \
	$(LIMOI_CFLAGS) $(LIMOIBASE_CFLAGS) $(AVFORMAT_CFLAGS) \
	$(OMX_FFMPEG_CFLAGS) -I$(top_srcdir)/include

liblimoi_ffmpeg_mux_la_LIBADD = $(LIMOIBASE_LIBS) $(AVFORMAT_LIBS) \
	$(OMX_FFMPEG_LIBS)

liblimoi_ffmpeg_mux_la_LDFLAGS = $(limoicomponent_ldflags)

