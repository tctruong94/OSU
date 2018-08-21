#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include <iostream>
#include <string>

#include "people.hpp"
#include "student.hpp"
#include "instructor.hpp"
#include "building.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class University 
{
    private:
        string uName;
        Building build1, build2;
        Instructor instruct1;
        Student stud1;

    public:
        University();                        
        ~University();                         
        void setUnivName (string name);        
        void displayBuildings ();
        void displayPeople ();

        void setBuilding1(string name, int size, string address);
        void setBuilding2(string name, int size, string address);
        void setStudent(string n, int a);
        void setInstructor(string n, int a);

        void studentDoWork();
        void instructorDoWork();
     

};

#endif
