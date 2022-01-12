limoicomponent_LTLIBRARIES = liblimoi-video-scheduler.la

liblimoi_video_scheduler_la_SOURCES = video-scheduler.c

liblimoi_video_scheduler_la_CFLAGS = -Wall -Werror -fno-strict-aliasing \
	$(LIMOI_CFLAGS) $(LIMOIBASE_CFLAGS) \
	-I$(top_srcdir)/include

liblimoi_video_scheduler_la_LIBADD = $(LIMOIBASE_LIBS)

liblimoi_video_scheduler_la_LDFLAGS = $(limoicomponent_ldflags)

