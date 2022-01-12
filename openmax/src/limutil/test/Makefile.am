check_PROGRAMS = log qlist util

limutil_LDADD = $(top_builddir)/src/liblimutil.la -lpthread
limutil_CFLAGS = -I$(top_srcdir)/include

log_SOURCES = log.c
log_LDADD = $(limutil_LDADD)
log_CFLAGS = $(limutil_CFLAGS)

qlist_SOURCES = qlist.c
qlist_LDADD = $(limutil_LDADD)
qlist_CFLAGS = $(limutil_CFLAGS)

util_SOURCES = util.c
util_LDADD = $(limutil_LDADD)
util_CFLAGS = $(limutil_CFLAGS)
