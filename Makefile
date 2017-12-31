CC := g++
RM := rm -f

INCDIR := include
SRCDIR := src
TARGET := example.exe

CFLAGS := -I$(INCDIR)
LIBS := ""
MISCFLAGS := -std=c++14 -fdiagnostics-color=always

SRC := $(shell find $(SRCDIR) -type f -name *.cc)
SRC += util/example.cc
OBJ := $(SRC:.cc=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $^ -o $(TARGET) $(LIBS)

%.o: %.cc
	$(CC) $(CFLAGS) $(MISCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)
	$(RM) $(TARGET)
