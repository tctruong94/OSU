program: project3.o Barbarian.o Bluemen.o Harrypotter.o Medusa.o Vampire.o
	g++ project3.cpp Barbarian.cpp Bluemen.cpp Harrypotter.cpp Medusa.cpp Vampire.cpp -o program

project3.o: project3.cpp
	g++ -c project3.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp Creature.hpp
	g++ -c Barbarian.cpp

Bluemen.o: Bluemen.cpp Bluemen.hpp Creature.hpp
	g++ -c Bluemen.cpp

Harrypotter.o: Harrypotter.cpp Harrypotter.hpp Creature.hpp
	g++ -c Harrypotter.cpp

Medusa.o: Medusa.cpp Medusa.hpp Creature.hpp
	g++ -c Medusa.cpp

Vampire.o: Vampire.cpp Vampire.hpp Creature.hpp
	g++ -c Vampire.cpp
clean: 
	rm *.o pogram
