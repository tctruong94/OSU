#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "item.hpp"
#include "list.hpp"

using std::cout;
using std::cin;
using std::endl;

List::List() 
{
    arrayCheck = 0;
    arraySize = 4;
    totalCost = 0;
    groceryList = new Item*[4];
}

List::~List()
{

}

void List::addItem()
{
    string name1, unit1;
    int num1;
    char update;
    double price1;
    bool truth = true;

    if (arrayCheck == arraySize)
    {
        doubleSize();
    }

    cout << "\nEnter Item Name: ";
    cin >> name1;


    cout << "Enter unit(box, pounds, ounces): ";
    cin >> unit1;
     while ((unit1 != "box") && (unit1 != "pounds") && (unit1 != "ounces"))	
	    {
		cin.clear();
		cin.ignore();
		cout << "\nPlese enter either box, pounds, or ounces: ";
		cin >> num1;
	    }


    cout << "How many " << name1 << "s do you want to buy: ";
    cin >> num1;
    while (cin.fail())	
	    {
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cout << "How many " << name1 << "'s do you want to buy: ";
		cin >> num1;
	    }


    cout << "Unit price: ";
    cin >> price1;
    while (cin.fail())	
	    {
		cin.clear();
		cin.ignore(std::numeric_limits<double>::max(), '\n');
		cout << "Unit price: ";
		cin >> price1;
	    }


    for (int i = 0; i < arrayCheck ; ++i)
    {
        if((groceryList[i])-> GetName() == name1)
        {
            cout << "Item is already in cart. " << endl;
            cout << "Would you like to update the item? (y/n): ";
            cin >> update;
            
            if((update == 'Y') || (update == 'y'))
            {
            groceryList[i]->setUnit(unit1);
            groceryList[i]->setQty(num1);
            groceryList[i]->setPrice(price1);
            groceryList[i]->setTotal(price1,num1);
            truth = false;
            break;
            }
            else
            {
                return;
            }
        }
    }
    
    if (truth == true)
    {
    groceryList[arrayCheck] = new Item(name1, unit1, num1, price1);
    totalCost += (price1 * num1);
    arrayCheck++;
    }
    
}

void List::doubleSize()

{

     arraySize *= 2;

     Item **newGroceryList = new Item*[arraySize];

     for (int i = 0; i < arrayCheck; ++i)

     {

          newGroceryList[i] = groceryList[i];

     }

     groceryList = newGroceryList;

}

void List::removeAt(int ind)
{
    for(int i = ind; i < arrayCheck; ++i)
    {
        groceryList[i] = groceryList[i + 1];
    }
}


void List::deleteItem()
{
    cout << "Which item do you want removed: ";
    string name;
    cin >> name;
    for (int i = 0; i < arrayCheck ; ++i)
    {
        if((groceryList[i])-> GetName() == name)
        {
            removeAt(i);
        }
    }
    arrayCheck--;
}


double List::getTotalCost()
{
    double total = 0;

    for(int i = 0; i < (arrayCheck); i++)
    {
        total += groceryList[i]->GetTotal();
    }

    return total;
}

void List::printList()
{
    for(int i = 0; i < arrayCheck; i++)
    {
        cout <<endl << "Item " << i+1 << ":" << endl;
        groceryList[i]->Print();
        cout << endl << endl;
    }
    cout << "The list total is: $" << getTotalCost() << endl;

}