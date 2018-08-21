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
#ifndef TOOL_HPP
#define TOOL_HPP

class Tool 
{
	protected:
		int strength;
		char type;
	public:
		void SetStrength(int);
		int getStrength();
		char getType();
		virtual char fight(Tool*) = 0;
};
#endif
