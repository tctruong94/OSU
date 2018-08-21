#ifndef LIST_HPP
#define LIST_HPP

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <limits>

using namespace std;



class node_List                                      //Declaration of node_List
{
    protected:
    struct node                                             //Declaration of a node
    {
        int info;
        node *next;
    };
    node *head;
    
    public:
        node* create_node(int);
        node_List()
        {
            head = NULL;
        }
        ~node_List();
        void addto_Front();
        void addto_Back();

        void delete_Front();
        void delete_End();

        void reverse_List();
        void display();

};
#endif

