## LIMOI FFMPEG components top-level helper Makefile.


## LIMOI development tree ?
limoi_dev_tree := $(shell \
	if [ -e demux ]; then \
		echo "y"; else echo "n"; \
	fi)


.PHONY: usage
usage:
	@echo
	@echo "LIMOI OpenMAX FFMPEG Components Build Helper"
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
COMPS = libomx-ffmpeg demux mux decode encode

ifeq ($(limoi_dev_tree),y)
TREE_PREFIX = limoi-
endif

.PHONY: all clean distclean install dist FFMPEG $(COMPS)
all clean distclean install: $(COMPS)
$(COMPS): FFMPEG
	$(MAKE) -C $@* $(MAKECMDGOALS)

FFMPEG:
	$(MAKE) -C src $(MAKECMDGOALS) ;

ifeq ($(limoi_dev_tree),y)
dist:
	@mkdir -p $(TREE_PREFIX)ffmpeg
	@for ii in `echo $(COMPS)`; do \
		rm -f ./$$ii/*.gz ; \
		make -C $$ii $@; \
		cd $(TREE_PREFIX)ffmpeg ; \
		tar xzf ../$$ii/*.gz ; \
		if [ -d limoi-ffmpeg-$$ii* ] ; then \
		mv limoi-ffmpeg-$$ii* `echo limoi-ffmpeg-$$ii* | sed s/limoi-ffmpeg-//` ;\
		fi ;\
		cd .. ; \
	done

	cp -a patches $(TREE_PREFIX)ffmpeg
	cp Makefile $(TREE_PREFIX)ffmpeg
	cp -a osm $(TREE_PREFIX)ffmpeg
	@tar -czf $(TREE_PREFIX)ffmpeg.tar.gz $(TREE_PREFIX)ffmpeg
	@echo
	@echo "created package: $(TREE_PREFIX)ffmpeg.tar.gz"
	@echo
	@rm -rf $(TREE_PREFIX)ffmpeg
endif
