limresourcemanager_LTLIBRARIES = liblim-demo-resource-manager.la

liblim_demo_resource_manager_la_SOURCES = demo.c

liblim_demo_resource_manager_la_CFLAGS = -Wall -Werror -fno-strict-aliasing \
	$(LIMOI_CFLAGS) $(LIMOIBASE_CFLAGS) \
	-I$(top_srcdir)/include

liblim_demo_resource_manager_la_LIBADD = $(LIMOIBASE_LIBS)

liblim_demo_resource_manager_la_LDFLAGS = $(limresourcemanager_ldflags)
