limoicomponent_LTLIBRARIES = liblimoi-ffmpeg-encode-audio.la \
                             liblimoi-ffmpeg-encode-video.la

liblimoi_ffmpeg_encode_CFLAGS = -Wall -Werror -fno-strict-aliasing \
	$(LIMOI_CFLAGS) $(LIMOIBASE_CFLAGS) $(AVCODEC_CFLAGS) \
	$(OMX_FFMPEG_CFLAGS) -I$(top_srcdir)/include
liblimoi_ffmpeg_encode_LIBADD = $(LIMOIBASE_LIBS) $(AVCODEC_LIBS) \
	$(OMX_FFMPEG_LIBS)


liblimoi_ffmpeg_encode_audio_la_SOURCES = encode-audio.c

liblimoi_ffmpeg_encode_audio_la_CFLAGS = $(liblimoi_ffmpeg_encode_CFLAGS)

liblimoi_ffmpeg_encode_audio_la_LIBADD = $(liblimoi_ffmpeg_encode_LIBADD)

liblimoi_ffmpeg_encode_audio_la_LDFLAGS = $(limoicomponent_ldflags)


liblimoi_ffmpeg_encode_video_la_SOURCES = encode-video.c

liblimoi_ffmpeg_encode_video_la_CFLAGS = $(liblimoi_ffmpeg_encode_CFLAGS) \
	$(SWSCALE_CFLAGS)

liblimoi_ffmpeg_encode_video_la_LIBADD = $(liblimoi_ffmpeg_encode_LIBADD) \
	$(SWSCALE_LIBS)

liblimoi_ffmpeg_encode_video_la_LDFLAGS = $(limoicomponent_ldflags)

