SRCDIR := src
OBJDIR := obj
BINDIR := bin
LIBDIR := ../libs
PKGCNF := $(shell pkg-config --libs --cflags glu glfw3) -ldl
CFLAGS := -I$(GLAD_DIR) -Wall -Wextra -g

SRCS := $(shell find $(SRCDIR) -name *.c)
OBJS := $(subst src/,,$(SRCS:%=$(OBJDIR)/%.o))
LIBS := $(shell find $(LIBDIR) -name "glad.o")

.all: main

main: $(BINDIR)/main

$(BINDIR)/main: $(OBJS) $(LIBS)
	$(CC) $(OBJS) $(LIBS) -o $@ $(PKGCNF) $(CFLAGS)

$(OBJDIR)/%.c.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@ $(PKGCNF) $(CFLAGS)

.PHONY: clean

clean:
	$(RM) -r $(OBJDIR)/*
