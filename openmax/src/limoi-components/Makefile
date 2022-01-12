## LIMOI components top-level helper Makefile.


## LIMOI development tree ?
limoi_dev_tree := $(shell \
	if [ -e clock ]; then \
		echo "y"; else echo "n"; \
	fi)


.PHONY: usage
usage:
	@echo
	@echo "LIMOI OpenMAX Components Build Helper"
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
COMPS = clock alsa_sink ogg_dec mad_dec video_scheduler ffmpeg sdl


.PHONY: all clean distclean install dist $(COMPS)
all clean distclean install: $(COMPS)
$(COMPS):
	$(MAKE) -C $@* $(MAKECMDGOALS)


ifeq ($(limoi_dev_tree),y)
dist:
	@mkdir -p limoi-components
	@for ii in `echo $(COMPS)`; do \
		rm -f ./$$ii/*.gz ; \
		make -C $$ii $@; \
		cd limoi-components ; \
		tar xzf ../$$ii/*.gz ; \
		if [ -d limoi-$$ii* ] ; then \
		mv limoi-$$ii* `echo limoi-$$ii* | sed s/limoi-//` ;\
		fi ;\
		cd .. ; \
	done

	cp Makefile limoi-components
	cp -a osm limoi-components
	cp README limoi-components
	cp OSM_README limoi-components
	@tar -czf limoi-components.tar.gz limoi-components
	@echo
	@echo "created package: limoi-components.tar.gz"
	@echo
	@rm -rf limoi-components
endif
