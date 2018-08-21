CXX = g++

CXXFLAGS = -std=c++0x

CXXFLAGS += -Wall

CXXFLAGS += -pedantic-errors
 
CXXFLAGS += -g

SRCS = main.cpp

PROGS := Lab10

all: 
	${CXX} ${CXXFLAGS} ${SRCS} -o $(PROGS)

clean:
	rm -f $(PROGS) *.o *~