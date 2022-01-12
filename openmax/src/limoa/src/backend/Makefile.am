if WITH_LIMOX
bin_PROGRAMS = limox
else
noinst_LTLIBRARIES = liblimox.la
endif

LIMOX_SRC = \
	parser.c \
	omxil-debug.c \
	./common/omxil-helper.c \
	./engine/eng-parser.c \
	./player/play-parser.c \
	./player/play-obj.c \
	./output-mix/omix-parser.c \
	./output-mix/omix-obj.c

LIMOX_CFLAGS = -Wall -Werror -fno-strict-aliasing \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/src/common \
	-I./common \
	-I./engine \
	-I./player \
	-I./output-mix \
	$(LIMUTIL_CFLAGS) $(OMXIL_CFLAGS)

if WITH_LIMOX
LIMOX_CFLAGS += -DLIMOX_ENABLED
else
LIMOX_CFLAGS += -I$(top_srcdir)/src/frontend/engine
endif

LIMOX_LIBS = $(LIMUTIL_LIBS) $(OMXIL_LIBS)

if WITH_LIMOX
limox_SOURCES = $(LIMOX_SRC) \
	main.c \
	session.c
else
liblimox_la_SOURCES = $(LIMOX_SRC) \
	session-stub.c
endif

noinst_HEADERS = \
	ox-main.h \
	ox-session.h \
	./common/common-be.h \
	./engine/engine-be.h \
	./player/player-be.h \
	./output-mix/output-mix-be.h

if WITH_LIMOX
limox_LDADD = ../common/liblimcommon.la
limox_LDFLAGS = $(LIMOX_LIBS)
limox_CFLAGS = $(LIMOX_CFLAGS)
else
liblimox_la_CFLAGS = $(LIMOX_CFLAGS)
liblimox_la_LIBADD = $(LIMOX_LIBS)
endif
