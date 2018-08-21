#include "queue.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>


using std::cout;
using std::cin;
using std::endl;
using std::string;


queue::queue ()                                         //constructor
{

}


queue::~queue ()                                        //deconstructor
{
    struct node *temp;
    temp = front;
    
    while (temp != back)
    {
        back->nextNode = front->nextNode;
        front = front->nextNode;
        front->prevNode = back;
        free(temp);
        temp = front;
    }
    free(back);
}


int queue::getFront ()                                  //Function that returns the value at the front of the queue
{
    int temp_Front;
    
    if (front == NULL)
    {
        cout << "The front node is empty." << endl;
        return 0;
    }
    else
    {
        temp_Front = front->value;

        return temp_Front;
    }
}


void queue::removeFront ()                              //Function that removes the front item in the structure


{
    struct node *temp;
    temp = front;
    
    if (front == NULL)
    {
        cout << "Queue is empty." << endl;
    }
    
    if (front->nextNode == NULL)
    {
        front = NULL;
        back = front;

        back->nextNode = front->nextNode = NULL;
        back->prevNode = front->prevNode = NULL;

        free(temp);

        cout << "Front node removed. Queue is empty." << endl;
    }
    
    else
    {
        back->nextNode = front->nextNode;

        front = front->nextNode;
        front->prevNode = back;

        free(temp);

        cout << "Front node removed." << endl;
    }
}


void queue::addBack (int val)                           //Function that puts an item at the end of the queue
{
    int num = val;
    struct node *temp;

    temp = new (struct node);
    temp->value = num;
    temp->nextNode = NULL;
    temp->prevNode = NULL;
    
    if (back == NULL)
    {
        front = back = temp;

        front->nextNode = back->nextNode = NULL;
        front->prevNode = back->prevNode = NULL;
    }
    else
    {
        back->nextNode = temp;
        temp->prevNode = back;

        back = temp;

        front->prevNode = back;
        back->nextNode = front;
    }
}


void queue::displayNodes ()                             //Funcion that displays the nodes on the queue
{
    struct node *temp;
    temp = front->nextNode;
    
    if (front == NULL)
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        cout << endl << front->value << " -> ";
        
        while (temp != front)
        {
            cout << temp->value << " -> ";
            temp = temp->nextNode;
        }
        
        cout << front->value << "(First Node)" << endl;
        
    }
}
