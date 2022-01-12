lib_LTLIBRARIES = liblimoi-core.la

liblimoi_core_la_SOURCES = \
	contentpipe.c \
	cp-file.c \
	handle.c \
	init.c \
	role.c \
	tunnel.c \
	static-linking.c

noinst_HEADERS = \
	core.h \
	contentpipe.h

liblimoi_core_la_CFLAGS = -Wall -Werror \
	-Dcomponentsdir=\"@libdir@/limoi/component\" \
	-Dloadersdir=\"@libdir@/limoi/loader\" \
	-Dothercoresdir=\"@libdir@/limoi/other-core\" \
	-I$(top_srcdir)/include \
	$(LIMUTIL_CFLAGS)

if WITH_RESOURCE_MANAGER
liblimoi_core_la_SOURCES += resource-manager.c
noinst_HEADERS += resource-manager.h
liblimoi_core_la_CFLAGS += \
	-DRESOURCE_MANAGER_ENABLED \
	-Dresourcemanagersdir=\"@libdir@/limoi/resource-manager\"
endif

liblimoi_core_la_LIBADD = $(LIMUTIL_LIBS)

liblimoi_core_la_LDFLAGS = -version-info @LIMOI_CORE_SO_VERSION@ \
	 --no-allow-shlib-undefined -ldl
