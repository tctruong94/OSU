/*******************************************
* Main Program
*******************************************/

#include<iostream>
#include <limits>
#include "list.hpp"

using namespace std;


int main()
{
    int choice;
    node_List list;

    cout << "\nWelcome to my linked list! " << endl;
    do
    {
        cout << "\nChoose from following options:"<<endl;
        cout<<"1. Add a new node to the head"<<endl;
        cout<<"2. Add a new node to the tail"<<endl;
        cout<<"3. Delete from head (the first node in the list)"<<endl;
        cout<<"4. Delete from tail (the last node in the list"<<endl;
        cout<<"5. Traverse the list reversely."<<endl;
        cout<<"6. Exit."<<endl;

    cout << "Enter your choice : ";

    cin >> choice;

        while ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4) && (choice != 5) && (choice != 6) )
	{
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
        cout << "Please enter a valid choice: ";
		cin >> choice;
    }


    switch(choice)
    {
    case 1:  
        list.addto_Front();
        cout << endl;
        break;
    case 2:
        list.addto_Back();
        cout << endl;
        break;
    case 3:
        list.delete_Front();
        cout << endl;
        break;
    case 4:
        list.delete_End();
        cout << endl;
        break;
    case 5:
        list.reverse_List();
        cout << endl;
        break;
    }   
    }while(choice != 6);
    return 0;
};
