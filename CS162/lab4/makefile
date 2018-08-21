lab4: main.o university.o student.o instructor.o building.o
	g++ main.cpp university.cpp student.cpp instructor.cpp building.cpp -o lab4

osuMain.o: main.cpp
	g++ -c main.cpp

university.o: university.cpp university.hpp
	g++ -c university.cpp

student.o: student.cpp student.hpp
	g++ -c student.cpp

instructor.o: instructor.cpp instructor.hpp
	g++ -c instructor.cpp

building.o: building.cpp building.hpp
	g++ -c building.cpp

clean: 
	rm *.o lab4