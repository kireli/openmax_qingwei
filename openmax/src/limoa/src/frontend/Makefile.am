lib_LTLIBRARIES = liblimoa.la

if WITH_LIMOX
LIMOX_CFLAGS = -DLIMOX_ENABLED
else
LIMOX_LIBS = $(top_srcdir)/src/backend/liblimox.la
LIMOX_CFLAGS = -I$(top_srcdir)/src/backend
endif

if WITH_LIMOX
LIMOX_SRC = ./engine/eng-ipc.c
else
LIMOX_SRC = ./engine/eng-ipc-stub.c
endif

liblimoa_la_SOURCES = main.c $(LIMOX_SRC) \
	./engine/eng-obj.c \
	./engine/eng-callback.c \
	./engine/eng-itf.c \
	./player/player-obj.c \
	./player/play-itf.c \
	./player/seek-itf.c \
	./output-mix/omix-obj.c

noinst_HEADERS = \
	./common/common-fe.h \
	./engine/engine-fe.h \
	./player/player-fe.h \
	./output-mix/output-mix-fe.h

liblimoa_la_LIBADD = $(top_srcdir)/src/common/liblimcommon.la \
	$(LIMOX_LIBS) \
	$(LIMUTIL_LIBS)

liblimoa_la_CFLAGS = -Wall -Werror -fno-strict-aliasing \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/src/common \
	-I$(top_srcdir)/src/backend \
	-I./common \
	-I./engine \
	-I./player \
	-I./output-mix \
	$(LIMOX_CFLAGS) \
	$(LIMUTIL_CFLAGS)

liblimoa_la_LDFLAGS = -version-info @LIMOA_SO_VERSION@ \
	 --no-allow-shlib-undefined
