# Adapted from https://gist.github.com/jakogut/1209260

CC = g++
LD = g++

CFLAGS = -pipe 
OFLAGS = -c -I/usr/include
LFLAGS = $(CFLAGS) -L/usr/lib/

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.c=.o)

DEBUG = no
PROFILE = no
PEDANTIC = no
OPTIMIZATION = -O3

ifeq ($(DEBUG), yes)
	CFLAGS += -g
	OPTIMIZATION = -O0
endif

ifeq ($(PROFILE), yes)
	CFLAGS += -pg
endif

CFLAGS += $(OPTIMIZATION)

# "make all" redirects to "make uni"
all: uni

# The main line that gets run in the Linux shell
uni: $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o uni

# "make clean"
clean:
	rm -rf *.o uni
