PROGS := main

all: $(PROGS)

main: main.o CreatureList.o LoserList.o Medusa.o Barbarian.o Vampire.o BlueMen.o HarryPotter.o
	g++ -std=c++11 main.o CreatureList.o LoserList.o Medusa.o Barbarian.o Vampire.o BlueMen.o HarryPotter.o -o project4

main.o: main.cpp Tournament.cpp
	g++ -c main.cpp

CreatureList.o: CreatureList.hpp CreatureList.cpp
	g++ -c CreatureList.cpp

Vampire.o: Vampire.hpp Vampire.cpp
	g++ -c Vampire.cpp

BlueMen.o: BlueMen.hpp BlueMen.cpp
	g++ -c BlueMen.cpp

LoserList.o: LoserList.hpp LoserList.cpp
	g++ -c LoserList.cpp

Medusa.o: Medusa.hpp Medusa.cpp
	g++ -c Medusa.cpp

HarryPotter.o: HarryPotter.hpp HarryPotter.cpp
	g++ -c HarryPotter.cpp

Barbarian.o: Barbarian.hpp Barbarian.cpp
	g++ -c Barbarian.cpp

clean:
	rm -f $(PROGS) *.o