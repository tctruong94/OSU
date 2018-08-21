#include <iostream>
#include "Product.hpp"

Product:: Product(std::string id, std::string t, std::string d, double p, int qa) //Constructor
{
    idCode = id;
    title = t;
    description = d;
    price = p;
    quantityAvailable = qa;
}


std::string Product::getIdCode()                  //get ID code of product
{
    return idCode;
}

std::string Product::getTitle()                   //get the product's' title
{
    return title;
}

std::string Product::getDescription()             //get the description of the product
{
    return description;
}

double Product::getPrice()                        //get the price of the product
{
    return price;
}

int Product::getQuantityAvailable()               //return the quantity available of product
{
    return quantityAvailable;
}

void Product::decreaseQuantity()                  //decrease quantity of product by 1
{
    quantityAvailable -= 1;
}