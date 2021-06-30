SRCDIR := src
OBJDIR := obj
BINDIR := bin
GLAD_DIR := ../glad
PKGCNF := $(shell pkg-config --libs --cflags glu glfw3) -ldl -lm
CFLAGS := -I$(GLAD_DIR) -Wall -Wextra -g

SRCS := $(shell find $(SRCDIR) -name *.c)
OBJS := $(subst src/,,$(SRCS:%=$(OBJDIR)/%.o))

GLAD_OBJ := $(GLAD_DIR)/glad.o

.all: main

main: $(BINDIR)/main

$(BINDIR)/main: $(OBJS) $(GLAD_OBJ)
	$(CC) $(OBJS) $(GLAD_OBJ) -o $@ $(PKGCNF) $(CFLAGS)

$(OBJDIR)/%.c.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@ $(PKGCNF) $(CFLAGS)

.PHONY: clean

clean:
	$(RM) -r $(OBJDIR)/*
