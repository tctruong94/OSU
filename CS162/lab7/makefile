CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g


OBJS = main.o queue.o
SRCS = main.cpp queue.cpp
HEADERS = queue.hpp
RPSGame: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o lab7

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: ${CLEAN}
	rm -f *.o
	rm -f a.out
	rm -f lab7

