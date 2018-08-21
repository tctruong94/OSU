#include "item.hpp"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

Item::Item()
{
    name = " ";
    unit = " ";
    qty = 0;
    pricePerUnit = 0;
}

Item::~Item()
{

}

Item::Item(string n, string u, double q, double price)
{
    this->name = n;
    this->unit = u;
    this->qty = q;
    this->pricePerUnit = price;
    this->total = price * static_cast<double>(qty);
}

void Item::setUnit(string u)
{
    unit = u;
}

void Item::setQty(int q)
{
    qty = q;
}

void Item::setPrice(int p)
 {
    pricePerUnit = p;
 }

 void Item::setTotal(int p, double q)
 {
    total = p * q;
 }

string Item::GetName()
{
    return name;
}

string Item::GetUnit()
{
    return unit;
}

double Item::GetQty()
{
    return qty;
}

double Item::GetPrice()
{
    return pricePerUnit;
}

double Item::GetTotal()
{
    return total;
}

void Item::Print()
{
    cout << "Name: " << name << endl;
    cout << "Unit: " << unit << endl;
    cout << "Quantity: " << qty << endl;
    cout << "Price Per Unit: $" << pricePerUnit << endl;
    cout << "Total: $" << total << endl;
}