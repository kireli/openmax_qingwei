limoicomponent_LTLIBRARIES = liblimoi-sdl-video-sink.la

liblimoi_sdl_video_sink_la_SOURCES = sdl.c

liblimoi_sdl_video_sink_la_CFLAGS = -Wall -Werror -fno-strict-aliasing \
	$(LIMOI_CFLAGS) $(LIMOIBASE_CFLAGS) $(SDL_CFLAGS) \
	-I$(top_srcdir)/include

liblimoi_sdl_video_sink_la_LIBADD = $(LIMOIBASE_LIBS) $(SDL_LIBS)

liblimoi_sdl_video_sink_la_LDFLAGS = $(limoicomponent_ldflags)
