#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Item
{
    private:
        string name;
        string unit;
        double qty;
        double pricePerUnit;
        double total;

    public:
        Item();
        Item(string, string, double, double);
        ~Item();

        
        void setUnit(string u);
        void setQty(int q);
        void setPrice(int p);
        void setTotal(int p, double q);

        string GetName();
        string GetUnit();
        double GetQty();
        double GetPrice();

        double GetTotal();

        void Print();
};

#endif