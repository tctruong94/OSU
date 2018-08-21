#include "Barbarian.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using std::string;
using std::cout;
using std::cin;
using std::endl;


Barbarian::Barbarian ()                             //Default Constructor
{
    creatureType = "Barbarian";
    attk_Point = 0;
    def_Point = 0;
    arm_Point = 0;
    str_Point = 12;
    defeat = false;
}


Barbarian::~Barbarian ()                            //Deconstructor
{
}


string Barbarian::get_Type ()                        //getter for the creatures type
{
    return creatureType;
}


int Barbarian::getArmor ()                          //getter for the armor points
{
    return arm_Point;
}


int Barbarian::get_Str ()                 //getter for strength points
{
    return str_Point;
}


bool Barbarian::defeated ()                         //bool for whether or not creature has been defeated or not
{
    return defeat;
}


int Barbarian::attk ()                            //attack function 
{
    attk_Point = attk_Roll ();
    cout << "The Barbarian uses " << attk_Point << " attack points!" << endl;
    return attk_Point;
}



void Barbarian::defend (int a)                      //defend function
{
    int dmg = a;

    def_Point = def_Roll();
    
    if (dmg == 100)
    {
        cout << "The Barbarian has succumb to Medusa's special ability,glare, and has turned into stone!" << endl;
        cout << "The baribarian's strength points is now 0." << endl;
        defeat = true;
    }
    else
    {
        cout << "The Barbarian uses " << def_Point << " defense points!" << endl;

        dmg = dmg - def_Point;
    
        cout << "The Barbarian uses " << arm_Point << " armor." << endl;

        dmg = dmg - arm_Point;
    
        cout << "The Barbarian recieved " << dmg << " points in damage." << endl;
   
        if (dmg > 0)
        {
            str_Point = str_Point - dmg;
        }
        else
        {
            str_Point = str_Point;
        }
 

        if (str_Point > 0)
        {
            cout << "The Barbarian is stil alive!" << endl;
            cout << "Strength points remaining: " << str_Point << endl << endl;
        }
        else if (str_Point <= 0)
        {
            cout << "Barbarian is defeated." << endl;
            cout << "Strength points remaining: 0" << endl << endl;
            defeat = true;
        }
    }
}



int Barbarian::attk_Roll ()                                        //Roll for attk amount
{
    int atk = rand () % 6 + 1;
    atk = atk + (rand () % 6 + 1);
    return atk;
}


int Barbarian::def_Roll ()                                       //Roll for def. amount
{
    int def = rand () % 6 + 1;
    def = def + (rand () % 6 + 1);
    return def;
}
