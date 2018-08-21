/*******************************************
* Author: Thanhbinh Truong
* Description: This program will illustrate the use of a doubly-linked circular structure.
* User will be able to add a value to the queue, display the first node of the queue,
* remove the first node of the queue,and display the queues contents.
********************************************/

#include "queue.hpp"
#include <iostream>
#include<cstdio>
#include<cstdlib>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    int choice;
    
    queue var;
    
    cout << "Welcome to the Doubly-linked Circular Structure Program" << endl;
    
    bool end = false;
    while (end == false)
    {
        cout << endl << "Please select an option: " << endl;
        cout << "1. Enter a value to be added to the queue" << endl;
        cout << "2. Display first node (front) value" << endl;
        cout << "3. Remove first node (front) value" << endl;
        cout << "4. Display the queue contents" << endl;
        cout << "5. Exit." << endl;
        
        cin >> choice;
        
        while ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4) && (choice != 5))
	    {
		    cin.clear();
		    cin.ignore(std::numeric_limits<int>::max(), '\n');
            cout << "Please enter a positive integer: ";
		    cin >> choice;
	    }

        switch (choice)
        {
            case 1:
            {
                int a;
                
                cout << "\nEnter an integer to add to the back of the queue: ";
                cin >> a;
                
                var.addBack(a);
                break;
            }
            case 2:
            {
                cout << endl << "The first node (front) value: ";
                cout << var.getFront() << endl;
                break;
            }
            case 3:
            {
                var.removeFront();
                break;
            }
            case 4:
            {
                var.displayNodes();
                break;
            }
            case 5:
            {
                cout << "Exiting program..." << endl;
                end = true;
                break;
            }
        }
    }
}
