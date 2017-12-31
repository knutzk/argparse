CC := g++
RM := rm -f

INCDIR := include
LIBDIR := lib
SRCDIR := src

LIBSO := $(LIBDIR)/libArgparse.so
TARGET := example.exe

CFLAGS := -I$(INCDIR)
LIBS := ""
MISCFLAGS := -std=c++14 -fdiagnostics-color=always

SRC := $(shell find $(SRCDIR) -type f -name *.cc)
SRC += util/example.cc
OBJ := $(SRC:.cc=.o)

all: $(TARGET)

$(TARGET): $(LIBSO)
	$(CC) $^ -o $(TARGET) $(LIBS)

$(LIBSO): $(OBJ)
	$(CC) $^ -shared -o $(LIBSO) $(LIBS)

%.o: %.cc
	$(CC) $(CFLAGS) $(MISCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)
	$(RM) $(TARGET)
