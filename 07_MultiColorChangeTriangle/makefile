SRCDIR := src
SHDDIR := shd
OBJDIR := obj
BINDIR := bin
GLAD_DIR := ../glad
PKGCNF := $(shell pkg-config --libs --cflags glu glfw3) -ldl -lm
CFLAGS := -I$(GLAD_DIR) -Wall -Wextra -g

SRCS := $(shell find $(SRCDIR) -name *.c)
OBJS := $(subst $(SRCDIR)/,,$(SRCS:%=$(OBJDIR)/%.o))
VERTS := $(subst $(SHDDIR)/,$(BINDIR)/,$(shell find $(SHDDIR) -name *.vert))
FRAGS := $(subst $(SHDDIR)/,$(BINDIR)/,$(shell find $(SHDDIR) -name *.frag))

GLAD_OBJ := $(GLAD_DIR)/glad.o

.all: main

main: $(BINDIR)/main $(VERTS) $(FRAGS)

$(BINDIR)/main: $(OBJS) $(GLAD_OBJ)
	$(CC) $(OBJS) $(GLAD_OBJ) -o $@ $(PKGCNF) $(CFLAGS)

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
