#include <iostream>
#include <string>
#include <limits>
#include "list.hpp"
#include "item.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    List groceryList;
    int choice;


    cout << endl << "Welcome to the grocery list program!" << endl;
    do
    {
        cout << endl << "1) Add list item" << endl;
        cout << "2) Delete last item" << endl;
        cout << "3) Print list" << endl;
        cout << "4) Exit" << endl;
        cout << "Choice: ";

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
            groceryList.addItem();
            break;
        }
        case 2:
        {
            groceryList.deleteItem();
            break;
        }
        case 3:
        {
            groceryList.printList();
            break;
        }
    }
    }
    while(choice != 4);


    return 0;
}