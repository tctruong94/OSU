/********************************************************************
** Program Name: Rock, Paper, Scissors
** Author: Daniel Kim, Marisol Zamora, Patrick Spencer, Andrei Pestovski, Thanhbinh Truong
** Date: 5/15/17
** Description: This is the base class for the Rock, Paper, Scissors
** classes. The default strength is 1. Type is changed in the derived
** classes. The fight method is used to compare the strengths of the
** Tool with another Tool. It is a pure virtual function so a rock has
** an advantage over scissors, paper has an advantage over rock and
** scissors has an advantage over paper.
*********************************************************************/
#include "tool.hpp"

void Tool::SetStrength(int s) 
{
	this->strength = s;
}

int Tool::getStrength() 
{
	return this->strength;
}

char Tool::getType() 
{
	return this->type;
}
