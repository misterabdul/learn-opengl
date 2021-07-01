SRCDIR := src
SHDDIR := shd
OBJDIR := obj
BINDIR := bin
LIBDIR := ../libs

PKGCNF := $(shell pkg-config --libs --cflags glu glfw3) -ldl -lm
CFLAGS := -I$(LIBDIR) -Wall -Wextra -g

SRCS := $(shell find $(SRCDIR) -name *.c)
OBJS := $(subst $(SRCDIR)/,,$(SRCS:%=$(OBJDIR)/%.o))
LIBS := $(shell find $(LIBDIR) -name "*.o")
VERTS := $(subst $(SHDDIR)/,$(BINDIR)/,$(shell find $(SHDDIR) -name *.vert))
FRAGS := $(subst $(SHDDIR)/,$(BINDIR)/,$(shell find $(SHDDIR) -name *.frag))


.all: main

main: $(BINDIR)/main $(VERTS) $(FRAGS)

$(BINDIR)/main: $(OBJS) $(LIBS)
	$(CC) $(OBJS) $(LIBS) -o $@ $(PKGCNF) $(CFLAGS)

$(OBJDIR)/%.c.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@ $(PKGCNF) $(CFLAGS)

$(BINDIR)/%.vert: $(SHDDIR)/%.vert
	cp $< $(BINDIR)/

$(BINDIR)/%.frag: $(SHDDIR)/%.frag
	cp $< $(BINDIR)/

.PHONY: clean

clean:
	$(RM) -r $(OBJDIR)/*
	$(RM) -r $(BINDIR)/*
