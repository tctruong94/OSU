#include <iostream>
#include <cstdlib>
#include <limits>

#include "university.hpp"
#include "building.hpp"
#include "instructor.hpp"
#include "people.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    
    int choice;
    int choice2;
    bool valid = false;

    srand (time(NULL));

    University osu;
    osu.setUnivName("Oregon State University");

    osu.setBuilding1("Arnold Dining Center", 28577, "681 SW 26TH STREET CORVALLIS, OR 97331");
    osu.setBuilding2("Dixon Recreation Center", 173776, "425 SW 26TH STREET CORVALLIS, OR 97331");

    osu.setStudent("Wen Doe", 20);
    osu.setInstructor("Moe Lester", 49);

    cout << endl << "Welcome to the University of Oregon State Information System!" << endl << endl;

do
{
    cout << endl << "You can select from the following options: " << endl;
    cout << "1. Print Information of All Buildings" << endl;
    cout << "2. Print Information of Everybody in the University" << endl;
    cout << "3. Choose a Person To Do Work" << endl;
    cout << "4. Exit Program" << endl << endl;

    cin >> choice;
    while ((choice != 1)  && (choice != 2 && (choice != 3 && (choice !=4))))	
	{
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
        cout << "Please enter valid choice: ";
		cin >> choice;
	}

    switch(choice)
    {
        case 1:
        {
            osu.displayBuildings();
            break;
        }
        case 2:
        {
            osu.displayPeople();
            break;
        }
        case 3:
        {
            {
            cout << "Please select a student or instructor to do work: " << endl;
            cout << "1. Wen Doe (student)" << endl;
            cout << "2. Moe Lester (instructor)" << endl << endl;

            cin >> choice2;
            while (choice2 != 1 && choice2 != 2)
	        {
		        cin.clear();
		        cin.ignore(std::numeric_limits<int>::max(), '\n');
                cout << "Please enter valid choice: ";
		        cin >> choice2;
	        }

            switch(choice2)
            {
                case 1:
                {
                    osu.studentDoWork();
                    break;
                }
                case 2:
                {
                    osu.instructorDoWork();
                    break;
                }
            }
            }
        }
    }
    }
    while(choice != 4);

    return 0;
}