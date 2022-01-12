lib_LTLIBRARIES = liblimoi-base.la

liblimoi_base_la_SOURCES = \
	debug.c \
	component.c \
	parameter.c \
	threads.c \
	command.c \
	port.c \
	role.c \
	state.c \
	event.c \
	tunnel.c \
	buffer-share.c \
	resource-manager.c \
	audio/decoder.c \
	audio/encoder.c \
	audio/renderer.c \
	video/vdecoder.c \
	video/vencoder.c \
	video/vrenderer.c \
	video/vscheduler.c \
	other/demuxer.c \
	other/muxer.c

noinst_HEADERS = component.h \
	audio/audio-priv.h \
	video/video-priv.h \
	other/other-priv.h

liblimoi_base_la_CFLAGS = -Wall -Werror -fno-strict-aliasing \
	$(LIMOI_CFLAGS) $(LIMUTIL_CFLAGS) \
	-I$(top_srcdir)/include \
	-Iaudio \
	-Ivideo \
	-Iother

liblimoi_base_la_LIBADD = $(LIMUTIL_LIBS)

liblimoi_base_la_LDFLAGS = -version-info @LIMOI_BASE_SO_VERSION@ \
	 --no-allow-shlib-undefined
