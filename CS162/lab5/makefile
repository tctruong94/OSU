CC = g++
DEBUG = -g
CFLAGS =  $(DEBUG) -std=c++0x
PROGS = glist
MAKEFLAGS = -k

all: $(PROGS)

glist:
	$(CC) $(CFLAGS) main.cpp -o recursive
clean:
	rm -f *.o glist