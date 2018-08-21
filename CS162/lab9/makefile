CXX = g++

CXXFLAGS = -std=c++0x

CXXFLAGS += -Wall

CXXFLAGS += -pedantic-errors
 
CXXFLAGS += -g

SRCS = main.cpp
SRCS +=stack.cpp
SRCS += queue.cpp


HEADERS = queue.hpp stack.hpp
PROGS := Lab9

all: 
	${CXX} ${CXXFLAGS} ${SRCS} -o $(PROGS)

clean:
	rm -f $(PROGS) *.o *~