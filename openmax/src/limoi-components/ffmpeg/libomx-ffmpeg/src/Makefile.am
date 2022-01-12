lib_LTLIBRARIES = libomx-ffmpeg.la

libomx_ffmpeg_la_SOURCES = \
	codec.c \
	mux.c

noinst_HEADERS =

libomx_ffmpeg_la_CFLAGS = -Wall -Werror -fno-strict-aliasing \
	$(LIMOI_CFLAGS) $(LIMOIBASE_CFLAGS) $(AVFORMAT_CFLAGS) \
	-I$(top_srcdir)/include

libomx_ffmpeg_la_LIBADD = $(LIMOI_LIBS) $(LIMOIBASE_LIBS) $(AVFORMAT_LIBS)

libomx_ffmpeg_la_LDFLAGS = -version-info @OMX_FFMPEG_SO_VERSION@ \
	 --no-allow-shlib-undefined
