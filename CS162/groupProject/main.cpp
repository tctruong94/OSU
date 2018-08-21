/********************************************************************
** Program Name: main funciton
** Author: Daniel Kim, Marisol Zamora, Patrick Spencer, Andrei Pestovski, Thanhbinh Truong
** Date: 5/15/17
** Description: This simple main() cretes object of RPSGame and calls plyGame 
**function that hs game menu
*********************************************/

#include "RPSGame.hpp"

int main()
{
   //int option;
   RPSGame RPSGame;
	RPSGame.playGame();
   /*while (true){// this menu is redandant and not needed
      cout << "***********Menu**********" << endl;
       cout << "Enter 1 to play the game" << endl;
       cout << "Enter 2 to exit" << endl;
       cout << "Choose an option: " << endl;
       cin >> option;
       switch (option){
       case 1:
           RPSGame.playGame();
           break;
       case 2:
           return 0;
       default:
           cout << "Choose a valid option" << endl;
       }
   }*/
   return 0;
}
