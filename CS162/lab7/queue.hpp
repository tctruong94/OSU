#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <cstdlib>
#include <cstdio>

struct node                                 //struct node declaration
{
    int value;
    node *prevNode;
    node *nextNode;
};

class queue                                 //class Queue declaration
{
    private:
        node *front = NULL;
        node *back = NULL;
        
    public:
        queue ();
        ~queue ();

        int getFront ();
        void removeFront ();

        void addBack (int val);

        void displayNodes ();
};

#endif
