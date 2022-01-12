check_PROGRAMS = omx

omx_ffmpeg_LDADD = $(top_builddir)/src/libomx-ffmpeg.la
omx_ffmpeg_CFLAGS = -I$(top_srcdir)/include

omx_SOURCES = omx.c
omx_LDADD = $(omx_ffmpeg_LDADD)
omx_CFLAGS = $(omx_ffmpeg_CFLAGS)
