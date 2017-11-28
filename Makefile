CC := g++

SRCDIR := src
TARGET := example.exe

CFLAGS := -I./argparse
LIBS := ""
MISCFLAGS := -std=c++14 -fdiagnostics-color=always

SRC := $(shell find $(SRCDIR) -type f -name *.cc)
SRC += util/example.cc
OBJ := $(SRC:.cc=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	@echo "   Linking..."
	@echo "   $(CC) $^ -o $(TARGET) $(LIBS)"; $(CC) $^ -o $(TARGET) $(LIBS)

%.o: %.cc
	@echo "   $(CC) $(CFLAGS) -c -o $@ $<"; $(CC) $(CFLAGS) $(MISCFLAGS) -c -o $@ $<

clean:
	@echo "   rm -f $(OBJ)"; rm -f $(OBJ)
	@echo "   rm -f $(TARGET)"; rm -f $(TARGET)
