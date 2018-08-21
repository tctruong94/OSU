#include "LoserList.hpp"
#include <iostream>
#include <cstring>
using std::string;
using std::cout;
using std::endl;

void LoserList::add(Creature *a, string b, string c)                //add creature to loser list
{

    if (!head)
    {
        head = new LoserNode(a, b, c);
    }

    else                                        
    {
        LoserNode *tempNode;
        tempNode = new LoserNode(a, b, c);

        tempNode->next = head;
        head = tempNode;
    }
}

void LoserList::printList()
{
    if (!head)
    {
        cout << "There are currently no creatures." << endl;
    }
    else
    {
        LoserNode *readNode;
        readNode = head;
        int count = 1;

        do
        {
            cout << "creature #" << count << ": " << "\t" << readNode->name << " the " << readNode->type << "." << endl;
            count++;
            readNode = readNode->next;
        } while (readNode);
    }
}

void LoserList::moveNext()
{
    if (head->next == NULL)
        return;
    else
    {
        LoserNode *searchNode, *tempNode;
        tempNode = head;
        head = tempNode->next;
        tempNode->next = NULL;

        searchNode = head;
        while (searchNode->next != NULL)
            searchNode = searchNode->next;
        searchNode->next = tempNode;
    }
}

void LoserList::getName() 
{ 
    cout << head->name << " the " << head->type; 
}


string LoserList::getID() 
{ 
    return head->name;
}


string LoserList::getType() 
{ 
    return head->type;
}