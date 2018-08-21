/******************************
** Author: Thanhbinh(Michael) Truong
** Date: March 8th 2017
** Description: The class declaration for TicTacToe
******************************/

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

class TicTacToe {
	private:
		Board board;			// 3x3 game board
		char player;			

	public:
		TicTacToe();			// Default constructor that creates a 3x3 board
		void play();			// Game controller
};

#endif