# Run make in each directory
# Reference : https://stackoverflow.com/questions/17834582/run-make-in-each-subdirectory/17845120#17845120

SUBDIRS := $(wildcard */.)

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

.PHONY: all $(SUBDIRS)
