check_PROGRAMS = core clock contentpipe demuxer metadata \
                 video_sink decode encode muxer

limoi_LDADD = $(top_builddir)/src/liblimoi-core.la -lpthread $(LIMUTIL_LIBS)
limoi_CFLAGS = -I$(top_srcdir)/include -Wall -Werror -fno-strict-aliasing \
	$(LIMUTIL_CFLAGS)

core_SOURCES = core.c
core_LDADD = $(limoi_LDADD)
core_CFLAGS = $(limoi_CFLAGS)

clock_SOURCES = clock.c
clock_LDADD = $(limoi_LDADD)
clock_CFLAGS = $(limoi_CFLAGS)

contentpipe_SOURCES = contentpipe.c
contentpipe_LDADD = $(limoi_LDADD)
contentpipe_CFLAGS = $(limoi_CFLAGS)

demuxer_SOURCES = demuxer.c
demuxer_LDADD = $(limoi_LDADD)
demuxer_CFLAGS = $(limoi_CFLAGS)

metadata_SOURCES = metadata.c
metadata_LDADD = $(limoi_LDADD)
metadata_CFLAGS = $(limoi_CFLAGS)

video_sink_SOURCES = video_sink.c
video_sink_LDADD = $(limoi_LDADD)
video_sink_CFLAGS = $(limoi_CFLAGS)

decode_SOURCES = decode.c
decode_LDADD = $(limoi_LDADD)
decode_CFLAGS = $(limoi_CFLAGS)

encode_SOURCES = encode.c
encode_LDADD = $(limoi_LDADD)
encode_CFLAGS = $(limoi_CFLAGS)

muxer_SOURCES = muxer.c
muxer_LDADD = $(limoi_LDADD)
muxer_CFLAGS = $(limoi_CFLAGS)
