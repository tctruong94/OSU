#include <iostream>
#include "Product.hpp"
#include "Customer.hpp"

Customer::Customer(std::string n, std::string a, bool pm)       //Constructor
{
     name = n;
     accountID = a;
     premiumMember = pm;
}

std::string Customer::getAccountID()                                //getter for AccountID
{
     return accountID;
}


std::vector<std::string> Customer::getCart()                        //getter for Cart
{
     return cart;
}


void Customer::addProductToCart(std::string product)                //Add product to Cart
{
     cart.push_back(product);
}


bool Customer::isPremiumMember()                                    //Check if Customer is a premium member
{
    if(premiumMember==true)
        return true;
    else
        return false;
}

//function empty the cart
void Customer::emptyCart()                                          //Returns whether the cart is empty or not
{
     cart.empty();
}

