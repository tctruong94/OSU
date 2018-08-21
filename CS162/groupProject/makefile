CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp RPSGame.cpp scissors.cpp tool.cpp rock.cpp paper.cpp inputValidation.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=game

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm *o game


