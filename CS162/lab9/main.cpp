/**********************************************
* Name: Thanhbinh Truong
* Description: stack and queue program that adds, removes on the queue, and stack to create a palindrome
* Email: truontha@oregonstate.edu
* Date: 6/4/17
***********************************************/

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <limits>

#include "queue.hpp"
#include "stack.hpp"

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main() 
{
	Queue queue;
	Stack stack;

	int choice = 0;
	int num = 0;

	srand(0);

	while (choice != 5) 
	{
		cout << "\nWelcome to the Stack and Queue program by Thanhbinh Truong" << endl << endl;

		cout << "Choose a selection from the following options:" << endl;
		cout << "1. Add a number to your buffer" << endl;
		cout << "2. Remove a number from your buffer" << endl;
		cout << "3. Create a palindrome" << endl;
		cout << "4. Test your palindrome" << endl;
		cout << "5. Exit the program" << endl;
		cout << "\nPlease enter choice: " << endl;
		cin >> choice;

        while ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4) && (choice!=5))
	    {
		    cin.clear();
		    cin.ignore(std::numeric_limits<int>::max(), '\n');
            cout << "Please enter a valid choice: ";
		    cin >> choice;
	    }
		
		switch (choice) 
		{
			case 1:
			{
				num = rand() % 100 + 1;
				queue.add(num);
				break;
			}
			case 2:
			{
				num = rand() % 100 + 1;  
				queue.remove(num);
				break;
			}
			case 3:
			{
				cout << "the palindrome is created" << endl;
				stack.make();
				break;
			}
			case 4:
			{
				stack.test();
				break;
			}
			case 5:
			{
				cout << "exiting program..." << endl;
				break;
			}
			default:
			{
				cout << "You did not choose a valid option, please choose again " << endl;
			}
		}
	}
	return 0;
}