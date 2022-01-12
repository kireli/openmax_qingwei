## LIMOI plugins top-level helper Makefile.


.PHONY: usage
usage:
	@echo
	@echo "LIMOI OpenMAX Plugins Build Helper"
	@echo
	@echo "    make all            : build everything"
	@echo "    make clean          : clean everything"
	@echo "    make distclean      : deep distribution clean"
	@echo "    make install        : install everything"
	@echo


## plugins
PLUGINS = resource_managers


.PHONY: all clean distclean install $(PLUGINS)
all clean distclean install: $(PLUGINS)
$(PLUGINS):
	$(MAKE) -C $@* $(MAKECMDGOALS)
