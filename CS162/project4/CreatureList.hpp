#ifndef CREATURELIST_HPP
#define CREATURELIST_HPP

#include "Creature.hpp"

#include <iostream>
#include <cstring>

using std::cin;
using std::endl;
using std::string;
using std::cout;

class CreatureList
{
    protected:
        struct node
        {
            string name;
            string type;
        
            Creature *creat;

            node *next;

            node(Creature *c, string t, string n, node *next1 = NULL)
            {
                creat = c;
                type = t;
                name = n;
                next = next1;
            }
        };
        node *head;

    public:
        CreatureList() 
        { 
            head = NULL; 
        };

        void add(Creature *c, string t, string n);
        void remove();
        void printList();
        void moveNext();
        
        string getID();
        string getType();
        void getName();

        node* getHead() 
        { 
            return head; 
        }
        Creature* getCurrent() 
        { 
            return head->creat;
        }

};

#endif