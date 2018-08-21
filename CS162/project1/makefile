PROGS := main

all: $(PROGS)


main: main.o ant.o
	g++ -std=c++11 main.o ant.o -o main

main.o: main.cpp
	g++ -c main.cpp

Ant.o: ant.cpp ant.hpp
	g++ -c Ant.cpp

clean:
	rm -f $(PROGS) *.o