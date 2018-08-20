/******************************
** Author: Thanhbinh(Michael) Truong
** Date: March 8th 2017
** Description: The function declaration for TicTacToe
******************************/

#include <iostream>
#include "Board.hpp"
#include "TicTacToe.hpp"
#include <cctype>

using namespace std;

char startGame();

/*****************************
** Name: TicTacToe::TicTacToe
** Description: The default constructor that makes a board object.
******************************/
TicTacToe::TicTacToe() 
{
	Board board;
	player = 'x';
}

/*****************************
** Name: TicTacToe::play
** Description: Function is what controls the whole game.
** It will keep tract of the current player and make their moves.
******************************/

void TicTacToe::play() 
{
	char player;
	int a, 
        b;												

    player = startGame();				            // gets character value for current player

	while (board.gameState() == IN_PROGRESS)        // Repeats until there is a draw/winner
    {		
		cout << endl;								
		board.print();
		do 
        {											
			cout << endl;											
			cout << "Player " << player << ": make your move:\n";	
			cin >> a >> b;
		} 
        while (!board.makeMove(a, b, player));    // Repeats until legal move is made

		if (player == 'X') 
        {					    	
			player = 'O';
		} 
        else 
        {
			player = 'X';
		}
	}

	cout << endl;
	board.print();				// print final version of board before announcing game result
	cout << endl;

	if (board.gameState() == X_WINS) 
    {
		cout << "Player X wins!" << endl;
	} 
    else if (board.gameState() == O_WINS)
    {
		cout << "Player O wins!" << endl;
	} 
    else 
    {
		cout << "Its a Draw!" << endl;
	}
}

/*****************************
** Name: startGame()
** Description: Function is what controls the whole game.
** It will keep tract of the current player and make their moves.
******************************/
char startGame()
{
    char player; 
    cout << "Which player will go first, X or O?" << endl;
    do 
    {
	    cin >> player;

        if((toupper(player) == 'X') || (toupper(player) == 'O'))
        {
            break;
        }
        else   
        {
            cout << "Please enter X or O" << endl;
        }
    }
    while((toupper(player) != 'X') || (toupper(player) != 'O'));

    return toupper(player);
}

int main() 
{
	TicTacToe game;				// create TicTacToe game object
	game.play();				// play game

	return 0;
}

