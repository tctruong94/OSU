#include "people.hpp"
#include "student.hpp"
#include "instructor.hpp"
#include "building.hpp"
#include "university.hpp"

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

University::University ()                               //default constructor
{
}

University::~University()                               //default destructor
{
}

void University::setUnivName(std::string name)          //set name of University
{
    uName = name;
}

void University::displayBuildings()                     //display the buildings within university
{
    cout << "University Buildings: " << endl;
    build1.displayBuilding();
    build2.displayBuilding();
    
}

void University::displayPeople ()                       //display the staff and students of the unversity
{
    cout << "University Student: " << endl;
    stud1.display();
    cout << "university Instructor: " << endl;
    instruct1.display();

}

void University::setBuilding1(string name, int size, string address)    //set the name, size and address of building in the university
{
    build1.setBuildingName(name);
    build1.setBuildingSize(size);
    build1.setBuildingAddress(address);

}

void University::setBuilding2(string name, int size, string address)    //same as top but for building 2
{
    build2.setBuildingName(name);
    build2.setBuildingSize(size);
    build2.setBuildingAddress(address);

}

void University::setStudent(string n, int a)                            //set the name, age, and gpa of student in the university
{
    stud1.setValue(n,a);
    stud1.setGPA();    
}

void University::setInstructor(string n, int a)                         //set the name, age and rating of instructor in the university
{
    instruct1.setValue(n,a);
    instruct1.setRating();
}

void University::studentDoWork()                                        //generate number of hours student worked on homework
{
    stud1.doWork();
}
void University::instructorDoWork()                                     //generate number of hours instructor worked on grading homework
{
    instruct1.doWork();
}