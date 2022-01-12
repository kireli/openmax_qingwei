lib_LTLIBRARIES = liblimutil.la

liblimutil_la_SOURCES = \
	log.c \
	memory.c \
	qlist.c \
	thread.c \
	time.c \
	dir.c

noinst_HEADERS =

liblimutil_la_CFLAGS = -Wall -Werror \
	-I$(top_srcdir)/include

liblimutil_la_LDFLAGS = -version-info @LIMUTIL_SO_VERSION@ \
	 --no-allow-shlib-undefined
