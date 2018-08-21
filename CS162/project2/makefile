CC = g++
DEBUG = -g
CFLAGS =  $(DEBUG) -std=c++0x
PROGS = glist
MAKEFLAGS = -k

all: $(PROGS)

glist:
	$(CC) $(CFLAGS) item.cpp list.cpp main.cpp -o glist
clean:
	rm -f *.o glist