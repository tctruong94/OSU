#include "CreatureList.hpp"

#include <iostream>
#include <cstring>

using std::string;
using std::cout;
using std::endl;

void CreatureList::add(Creature *a, string b, string c)
{
    if (!head)
    {
        head = new node(a, b, c);
    }
    else
    {
        node *temp_Node, *node_Look;
        temp_Node = new node(a, b, c);

        node_Look = head;

        while (node_Look->next != NULL)
        {
            node_Look = node_Look->next;
        }

        node_Look->next = temp_Node;
    }
}



void CreatureList::remove()
{
    if (!head->next)
    {
        head = NULL;
    }
    else
    {
        node *temp_Node = head;
        head = head->next;

        delete temp_Node;                                               //delete memory allocation
    }
}



void CreatureList::printList()
{
    if (!head)
    {
        cout << "There are no active creatures." << endl;
    }
    else
    {
        node *readNode;
        readNode = head;

        int creat_Count = 1;

        do
        {
            cout << "Creature #" << creat_Count << ": " << endl;
            cout << readNode->name << "(" << readNode->type << ")" << endl;
            creat_Count++;

            readNode = readNode->next;

        }while (readNode);
    }
}



void CreatureList::moveNext()
{
    if (head->next == NULL)
    {
        return;
    }
    else
    {
        node *node_Look, *temp_Node;
        temp_Node = head;

        head = temp_Node->next;
        temp_Node->next = NULL;

        node_Look = head;

        while (node_Look->next != NULL)
        {
            node_Look = node_Look->next;
        }
        
        node_Look->next = temp_Node;
    }
}




void CreatureList::getName() 
{ 
    cout << head->name << " the " << head->type; 
}


string CreatureList::getID() 
{ 
    return head->name; 
}


string CreatureList::getType() 
{ 
    return head->type;
}