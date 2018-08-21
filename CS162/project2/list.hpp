#ifndef LIST_HPP
#define LIST_HPP

#include <fstream>
#include <string>
#include <vector>

#include "item.hpp"


class List
{
    private:
        Item **groceryList;
        int arrayCheck;
        int arraySize;
        int maximum;
        double totalCost;

    public:
        List();
        ~List();
        List(int n);
        void addItem();
        void removeAt(int ind);
        void deleteItem();
        void doubleSize();


        int getCount();
        Item getItem(int index);
        double getTotalCost();
        void printList();
};

#endif