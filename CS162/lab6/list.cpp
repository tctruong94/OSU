#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <limits>
#include "list.hpp"

/*******************************************
* function name: addto_Front
* Description: add positive integer to the front of the node
*******************************************/
void node_List::addto_Front()
{
    int choice;
    cout << "Please enter a positive integer:" << endl;
    cin>>choice;

    while (choice < 0)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
        cout << "Please enter a positive integer: ";
		cin >> choice;
	}

    struct node *b, *a;
    b = new(struct node);
    b->info = choice;
    b->next = NULL; 
    
    if (head == NULL)
    {
        head = b;
        head->next = NULL;
    }
    else
    {
        a = head;
        head = b;
        head->next = a;
    }

    display();
}

/*******************************************
* function name: addto_Back
* Description: add positive integer to the back of the node
*******************************************/
void node_List::addto_Back()
{
    int choice;
    cout<<"Please enter a positive integer:"<<endl;
    cin>>choice;

    while (choice < 0)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
        cout << "Please enter a positive integer: ";
		cin >> choice;
	}


    struct node *b, *a;
    b = new(struct node);
    b->info = choice;
    b->next = NULL; 
    
    a = head;

    while (a->next != NULL)
    {   
        a = a->next;
    }

    b->next = NULL;
    a->next = b;

    display();

}

/*******************************************
* function name: delete_Front
* Description: delete the element at the front of the node
*******************************************/
void node_List::delete_Front()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    struct node *a;
    a = head;
    head = a->next;

    display();
  
}


/*******************************************
* function name: delete_End
* Description: delete the element at the end of the node
*******************************************/
void node_List::delete_End()
{
    if (head == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }

    struct node *a;
    a = head;

    if(a->next!=NULL)
    {
        while (a->next->next != NULL)
        {
            a = a->next;
        }
        if(a->next->next==NULL)
        {
           a->next=NULL;
        }
    }

    display();
}


/*******************************************
* function name: reverse_List
* Description: traverse the list reversely
*******************************************/
void node_List::reverse_List()
{
    struct node *position_1, *position_2, *position_3;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    if (head->next == NULL)
    {
        return;
    }

    position_1 = head;
    position_2 = position_1->next;
    position_3 = position_2->next;

    position_1->next = NULL;
    position_2->next = position_1;

    while (position_3 != NULL)
    {
        position_1 = position_2;
        position_2 = position_3;
        position_3 = position_3->next;
        position_2->next = position_1;   
    }
    head = position_2;

    display();
}

/*******************************************
* function name: display
* Description: Display the elements in the list
*******************************************/
void node_List::display()
{
    struct node *b;
    if (head == NULL)
        {
        cout << "The List is Empty" << endl;
        return;
        }

    b = head;
    cout << "Your linked list is: ";

    while (b != NULL)
    {
        cout << b->info << " ";
        b = b->next;
    }
}

/*******************************************
* function name: Destructor
* Description: deallocates the memory used by the list
*******************************************/
node_List::~node_List()
{
    node *nodePtr = head;
    while (nodePtr != NULL)
    {
        node *deallocate = nodePtr;
        nodePtr = nodePtr->next;
        delete deallocate;
    }
}