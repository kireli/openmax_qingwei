check_PROGRAMS = engine player

limoa_LDADD = $(top_builddir)/src/frontend/liblimoa.la -lpthread $(LIMUTIL_LIBS)
limoa_CFLAGS = -I$(top_srcdir)/include

engine_SOURCES = \
	engine.c
engine_LDADD = $(limoa_LDADD)
engine_CFLAGS = $(limoa_CFLAGS)

player_SOURCES = \
	player.c
player_LDADD = $(limoa_LDADD)
player_CFLAGS = $(limoa_CFLAGS)
