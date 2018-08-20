/******************************* 
Author: Thanhbinh(Michael) Truong
** Date: March 8th 2017
** Description:  The class declaration for Board 
********************************/
#include <iostream>

using namespace std;

#ifndef BOARD_HPP
#define BOARD_HPP

enum GameState {X_WINS, O_WINS, DRAW, IN_PROGRESS};	 // Indicate if a player has won, has reach a draw,
													 // or if game is still in progress 										
class Board 
{
	private:
		char layout[3][3];		        //Stores the gameboard
	public:
		Board();				        // default constructor
		bool makeMove(int, int, char);						
		GameState gameState();								
		void print();				
};

#endif