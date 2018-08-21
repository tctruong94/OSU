CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g

Die = Die.cpp
LoadedDie = LoadedDie.cpp
Game = Game.cpp
main = main.cpp
ALL = ${Die} ${LoadedDie} ${Game} ${main}

HEADER1 = Die.h
HEADER2 = LoadedDie.h
HEADER3 = Game.h
HEADERS = ${HEADER1} ${HEADER2} ${HEADER3}

PROG1 = diceGame
PROGS = ${PROG1}


all:
	${CXX} ${CXXFLAGS} ${ALL} -o ${PROG1}

clean: 
	rm -f ${PROGS} *.o *~