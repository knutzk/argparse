CC := g++
RM := rm -f

INCDIR := include
LIBDIR := lib
SRCDIR := src

LIBSO := $(LIBDIR)/libArgparse.so
TARGET := example.exe

CFLAGS := -I$(INCDIR)
MISCFLAGS := -std=c++14 -Wall -pedantic-errors -fdiagnostics-color=always

SRC := $(shell find $(SRCDIR) -type f -name *.cc)
SRC += util/example.cc
OBJ := $(SRC:.cc=.o)

.PHONY: all

all: $(TARGET)

$(TARGET): $(LIBSO)
	$(CC) $(LIBS) -o $@ $^

$(LIBSO): $(OBJ)
	$(CC) -shared -o $@ $^

%.o: %.cc
	$(CC) $(MISCFLAGS) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	$(RM) $(OBJ)
	$(RM) $(TARGET)
