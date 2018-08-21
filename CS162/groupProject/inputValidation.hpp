/******************************************************
** Program Name: Rock, Paper, Scissors
** Author: Daniel Kim, Marisol Zamora, Patrick Spencer, Andrei Pestovski, Thanhbinh Truong
** Date: 5/15/17
** Description:  This class is used for getting input
from the user and making sure it is valid.
*******************************************************/
#ifndef INPUTVALIDATION_HPP
#define INPUTVALIDATION_HPP

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class InputValidation 
{
	public:
		int getOption();
		int getPosInt();
		bool getYN();
		char getRPS();
		//string getString();
		//int getInt();
};

#endif