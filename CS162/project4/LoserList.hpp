#ifndef LOSERLIST_HPP
#define LOSERLIST_HPP
#include <iostream>
#include <cstring>
#include "Creature.hpp"
using std::string;
using std::cout;

class LoserList
{
    protected:
        struct LoserNode
        {
            string name;
            string type;

            Creature *creat;
            LoserNode *next;

            LoserNode(Creature *c, string t, string n, LoserNode *next1 = NULL)
            {
                creat = c;
                type = t;
                name = n;
                next = next1;
            }
        };
        LoserNode *head;

    public:
        LoserList() { head = NULL; };    // constructor

        void add(Creature *c, string t, string n);
        void remove();

        void printList();
        void moveNext();

        void getName();
        string getID();
        string getType();

        LoserNode* getHead() 
        { 
            return head; 
            }
        Creature* getCurrent() 
        { 
            return head->creat; 
            }
};

#endif