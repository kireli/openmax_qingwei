## LIM resource managers top-level helper Makefile.


## LIMOI development tree ?
limoi_dev_tree := $(shell \
	if [ -e demo ]; then \
		echo "y"; else echo "n"; \
	fi)


.PHONY: usage
usage:
	@echo
	@echo "LIMOI OpenMAX Resource Managers Build Helper"
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
MANAGERS = demo

ifeq ($(limoi_dev_tree),y)
TREE_PREFIX = limoi-
endif

.PHONY: all clean distclean install dist $(MANAGERS)
all clean distclean install: $(MANAGERS)
$(MANAGERS):
	$(MAKE) -C $@* $(MAKECMDGOALS)


ifeq ($(limoi_dev_tree),y)
dist:
	@mkdir -p $(TREE_PREFIX)resource_managers
	@for ii in `echo $(MANAGERS)`; do \
		rm -f ./$$ii/*.gz ; \
		make -C $$ii $@; \
		cd $(TREE_PREFIX)resource_managers ; \
		tar xzf ../$$ii/*.gz ; \
		if [ -d limoi-resource_managers-$$ii* ] ; then \
		mv limoi-resource_managers-$$ii* \
			`echo limoi-resource_managers-$$ii* |\
			 sed s/limoi-resource_managers-//` ;\
		fi ;\
		cd .. ; \
	done

	cp -a patches $(TREE_PREFIX)resource_managers
	cp Makefile $(TREE_PREFIX)resource_managers
	cp -a osm $(TREE_PREFIX)resource_managers
	@tar -czf $(TREE_PREFIX)resource_managers.tar.gz \
		$(TREE_PREFIX)resource_managers
	@echo
	@echo "created package: $(TREE_PREFIX)resource_managers.tar.gz"
	@echo
	@rm -rf $(TREE_PREFIX)resource_managers
endif
