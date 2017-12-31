CC := g++
RM := rm -f

INCDIR := include
LIBDIR := lib
SRCDIR := src
UTILDIR := util

LIBSO := $(LIBDIR)/libArgparse.so
TARGET := example.exe

CFLAGS := -I$(INCDIR)
LIBS := -L$(LIBDIR)
MISCFLAGS := -std=c++14 -Wall -pedantic-errors -fdiagnostics-color=always

SRC := $(shell find $(SRCDIR) -type f -name *.cc)
OBJ := $(SRC:.cc=.o)

EXSRC := $(UTILDIR)/example.cc
EXOBJ := $(EXSRC:.cc=.o)

.PHONY: all

all: $(TARGET)

$(TARGET): $(EXOBJ) $(LIBSO)
	$(CC) $(LIBS) -lArgparse -o $@ $<

$(LIBSO): $(OBJ)
	$(CC) -shared -o $@ $^

%.o: %.cc
	$(CC) $(MISCFLAGS) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	$(RM) $(OBJ) $(EXOBJ)
	$(RM) $(LIBSO)
	$(RM) $(TARGET)
