## LIMOI SDL components top-level helper Makefile.


## LIMOI development tree ?
limoi_dev_tree := $(shell \
	if [ -e video_sink ]; then \
		echo "y"; else echo "n"; \
	fi)


.PHONY: usage
usage:
	@echo
	@echo "LIMOI OpenMAX SDL Components Build Helper"
	@echo
	@echo "    make all            : build everything"
	@echo "    make clean          : clean everything"
	@echo "    make distclean      : deep distribution clean"
	@echo "    make install        : install everything"
ifeq ($(limoi_dev_tree),y)
	@echo "    make dist           : distribution creation"
endif
	@echo


## components
COMPS = video_sink

ifeq ($(limoi_dev_tree),y)
TREE_PREFIX = limoi-
endif

.PHONY: all clean distclean install dist $(COMPS)
all clean distclean install: $(COMPS)
$(COMPS):
	$(MAKE) -C $@* $(MAKECMDGOALS)


ifeq ($(limoi_dev_tree),y)
dist:
	@mkdir -p $(TREE_PREFIX)sdl
	@for ii in `echo $(COMPS)`; do \
		rm -f ./$$ii/*.gz ; \
		make -C $$ii $@; \
		cd $(TREE_PREFIX)sdl ; \
		tar xzf ../$$ii/*.gz ; \
		if [ -d limoi-sdl-$$ii* ] ; then \
		mv limoi-sdl-$$ii* `echo limoi-sdl-$$ii* | sed s/limoi-sdl-//` ;\
		fi ;\
		cd .. ; \
	done

	cp Makefile $(TREE_PREFIX)sdl
	cp -a osm $(TREE_PREFIX)sdl
	@tar -czf $(TREE_PREFIX)sdl.tar.gz $(TREE_PREFIX)sdl
	@echo
	@echo "created package: $(TREE_PREFIX)sdl.tar.gz"
	@echo
	@rm -rf $(TREE_PREFIX)sdl
endif
