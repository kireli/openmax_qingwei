noinst_LTLIBRARIES = liblimcommon.la

liblimcommon_la_SOURCES = \
	OpenMAXAL_IID.c \
	error.c \
	ipc.c \
	deep-copy.c

noinst_HEADERS = \
	limoa-log.h \
	limipc.h \
	limipc-id.h \
	limipc-id-callback.h \
	limipc-id-engine.h \
	limipc-id-player.h \
	limipc-id-output-mix.h \
	limdeepcopy.h

liblimcommon_la_CFLAGS = -Wall -Werror \
	-I$(top_srcdir)/include \
	$(LIMUTIL_CFLAGS)

liblimcommon_la_LIBADD = $(LIMUTIL_LIBS)
