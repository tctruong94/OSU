lab6: main.o list.o
	g++ main.cpp list.cpp -o lab6

main.o: main.cpp
	g++ -c main.cpp

list.o: list.cpp list.hpp
	g++ -c list.cpp

clean:
	rm *.o lab6