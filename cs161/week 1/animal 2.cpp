/*********************************************************************
** Author: Thanhbinh(Michael) Truong
** Date: January 11th 2017
** Description: This program will ask for your favorite animal and reitterate it back to you
*********************************************************************/

#include <iostream>
#include <string>

// a simple example program
int main()
{
    std::string faveAnimal;
    std::cout << "Please enter your favorite animal." << std::endl;
    std::cin >> faveAnimal;
    std::cout << "Your favorite animal is the " << faveAnimal;
    std::cout << "." << std::endl;    
    
    return 0;
}

