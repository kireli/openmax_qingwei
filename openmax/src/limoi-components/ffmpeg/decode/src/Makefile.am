limoicomponent_LTLIBRARIES = liblimoi-ffmpeg-decode-audio.la \
                             liblimoi-ffmpeg-decode-video.la

liblimoi_ffmpeg_decode_CFLAGS = -Wall -Werror \
	$(LIMOI_CFLAGS) $(LIMOIBASE_CFLAGS) $(AVCODEC_CFLAGS) \
	$(OMX_FFMPEG_CFLAGS) -I$(top_srcdir)/include
liblimoi_ffmpeg_decode_LIBADD = $(LIMOIBASE_LIBS) $(AVCODEC_LIBS) \
	$(OMX_FFMPEG_LIBS)


liblimoi_ffmpeg_decode_audio_la_SOURCES = decode-audio.c

liblimoi_ffmpeg_decode_audio_la_CFLAGS = $(liblimoi_ffmpeg_decode_CFLAGS)

liblimoi_ffmpeg_decode_audio_la_LIBADD = $(liblimoi_ffmpeg_decode_LIBADD)

liblimoi_ffmpeg_decode_audio_la_LDFLAGS = $(limoicomponent_ldflags)


liblimoi_ffmpeg_decode_video_la_SOURCES = decode-video.c

liblimoi_ffmpeg_decode_video_la_CFLAGS = $(liblimoi_ffmpeg_decode_CFLAGS) \
	$(SWSCALE_CFLAGS)

liblimoi_ffmpeg_decode_video_la_LIBADD = $(liblimoi_ffmpeg_decode_LIBADD) \
	$(SWSCALE_LIBS)

liblimoi_ffmpeg_decode_video_la_LDFLAGS = $(limoicomponent_ldflags)

