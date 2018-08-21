#include "ant.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

void showMenu();

int main()
{
    int rowCount,
        colCount,
        row, 
        col,
        steps,
        choice;
    char startPos;
    bool position1 = true;
    bool position2 = true;

    showMenu();
    cin >> choice;

    if(choice == 1)
    {
    while (position1 == true)                                      //board rows
    {
        cout << "Enter the number of rows for the board size: ";
        cin >> rowCount;

        if (rowCount > 0)                                          //input validation
        {
            position1 = false;
        }
        else
        {
            cout << "Enter a number greater than 0" << endl;
            cin.clear();                                           //to clear input
            cin.ignore();                                          //to ignore spaces
        }
    }

    position1 = true;

    while (position1 == true)                                      //board columns
    {
        cout << "Enter the number of columns for the board size:";
        cin >> colCount;

        if (colCount > 0)                                          //input validation
        {
            position1 = false;
        }
        else
        {
            cout << "Enter a number greater than 0 " << endl;
            cin.clear();
            cin.ignore();
        }
    }

    position1 = true;                                              //steps

    while (position1 == true)
    {
        cout << "Steps for the ant to travel (ex. 50,100,150):";
        cin >> steps;
        if (steps > 0)                                             //input validation
        {
            position1 = false;
        }
        else
        {
            cout << "Enter a number greater than 0" << endl;
            cin.clear();
            cin.ignore();
        }
    }
    position1 = true;

    while (position2 == true)                                      //starting position
    {
        while (position1 == true)                                  //starting position(row)
        {
            cout << "Enter the starting position row:";
            cin >> row;

            if (row <= rowCount && row > 0)                        //input validation
            {
                row = row - 1;
                position1 = false;
            }
            else
            {
                cout << "Try again" << endl;
                cin.clear();
                cin.ignore();
            }
        }

        while (position1 == false)                                 //starting position(column)
        {
            cout << "Enter the starting position column:";
            cin >> col;

            if (col <= colCount && col > 0)                        //input validation
            {
                col = col - 1;
                position1 = true;
            }
            else
            {
                cout << "Try again" << endl;
                cin.clear();
            }
        }
        position2 = false;
    }


    Ant ant1(row, col);                                     //create Ant

    char **board = new char*[rowCount];                     //create board

    for (int i = 0; i < rowCount; i++)
    {
        board[i] = new char[colCount];
    }

    for (int i = 0; i < rowCount; i++)                    
    {
        for (int n = 0; n < colCount; n++)
        {
            board[i][n] = ' ';
        }
    }

    board[row][col] = '@';

    for (int i = 0; i < rowCount; i++)
    {
        for (int n = 0; n < colCount; n++)
        {
            cout << board[i][n];
        }
        cout << endl;
    }


    for (int i = steps; i > 0; i--)                             //Goes until reaches number of steps
    {
        if (ant1.getSpace() == ' ')
        {
            board[ant1.getRow1()][ant1.getColumn1()] = '#';     //to leave trail of ant

            if(ant1.getDirection() == north)
            {
                ant1.setDirection(east);
                col = ant1.getColumn2();
                col = col + 1;

                if (col >= colCount)
                {
                    col = 0;
                }

                ant1.setColumn2(col);

                if (board[ant1.getRow2()][ant1.getColumn2()] == ' ')
                {
                    ant1.setSpace(' ');
                }
                else
                {
                    ant1.setSpace('#');
                }

                board[ant1.getRow2()][ant1.getColumn2()] = '@';
            }
            else if(ant1.getDirection() == east)
            {
                ant1.setDirection(south);
                row = ant1.getRow2();
                row = row + 1;
                if (row >= rowCount)
                    row = 0;

                ant1.setRow2(row);

                if (board[ant1.getRow2()][ant1.getColumn2()] == ' ')
                {
                    ant1.setSpace(' ');
                }
                else
                {
                    ant1.setSpace('#');
                }

                board[ant1.getRow2()][ant1.getColumn2()] = '@';
            }
            else if(ant1.getDirection() == south)
            {
                ant1.setDirection(west);
                col = ant1.getColumn2();
                col = col - 1;

                if (col < 0)
                {
                    col = colCount - 1;
                }

                ant1.setColumn2(col);

                if (board[ant1.getRow2()][ant1.getColumn2()] == ' ')
                {
                    ant1.setSpace(' ');
                }
                else
                {
                    ant1.setSpace('#');
                }

                board[ant1.getRow2()][ant1.getColumn2()] = '@';

            }
            else if(ant1.getDirection() == west)
            {
                ant1.setDirection(north);
                row = ant1.getRow2();
                row = row - 1;

                if (row < 0)
                {
                    row = rowCount - 1;
                }

                ant1.setRow2(row);

                if (board[ant1.getRow2()][ant1.getColumn2()] == ' ')
                {
                    ant1.setSpace(' ');
                }
                else
                {
                    ant1.setSpace('#');
                }

                board[row][col] = '@';
            }
        }
        else if(ant1.getSpace() == '#')
        {
            board[row][col] = ' ';

            if(ant1.getDirection() == north)
            {
                ant1.setDirection(west);
                col = ant1.getColumn2();
                col = col - 1;

                if (col < 0)
                {
                    col = colCount - 1;
                }
                ant1.setColumn2(col);

                if (board[ant1.getRow2()][ant1.getColumn2()] == ' ')
                {
                    ant1.setSpace(' ');
                }
                else
                {
                    ant1.setSpace('#');
                }

                board[ant1.getRow2()][ant1.getColumn2()] = '@';
            }
            else if(ant1.getDirection() == east)
            {
                ant1.setDirection(north);
                row = ant1.getRow2();

                row = row - 1;

                if (row < 0)
                {
                    row = rowCount - 1;
                }
                ant1.setRow2(row);

                if (board[ant1.getRow2()][ant1.getColumn2()] == ' ')
                {
                    ant1.setSpace(' ');
                }
                else
                {
                    ant1.setSpace('#');
                }
                board[row][col] = '@';
            }
            else if(ant1.getDirection() == south)
            {
                ant1.setDirection(east);
                col = ant1.getColumn2();
                col = col + 1;
                if (col >= colCount)
                    col = 0;

                ant1.setColumn2(col);

                if (board[ant1.getRow2()][ant1.getColumn2()] == ' ')
                {
                    ant1.setSpace(' ');
                }
                else
                {
                    ant1.setSpace('#');
                }

                board[ant1.getRow2()][ant1.getColumn2()] = '@';

            }
            else if(ant1.getDirection() == west)
            {
                ant1.setDirection(south);
                row = ant1.getRow2();
                row = row + 1;

                if (row >= rowCount)
                    row = 0;
                ant1.setRow2(row);
                if (board[ant1.getRow2()][ant1.getColumn2()] == ' ')
                {
                    ant1.setSpace(' ');
                }
                else
                {
                    ant1.setSpace('#');
                }
                board[ant1.getRow2()][ant1.getColumn2()] = '@';
            }
        }

        for (int i=0; i<rowCount; i++)
        {
            for (int j=0; j<colCount; j++)
            {
                cout << board[i][j];
            }
            cout << endl;
        }

        ant1.setRow1(row);
        ant1.setColumn1(col);
    }

    for (int i=0; i<rowCount; i++)              //Deallocate
        delete [] board[i];
        delete [] board;

    cout << endl;
    return 0;
    }
    else if(choice == 2)
    {
        return 0;
    }
}
    
void showMenu()
{
    cout << endl;
    cout << "1. Start Program" << endl;
    cout << "2. Exit Program" << endl;
}



