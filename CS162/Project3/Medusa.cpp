#include "Medusa.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using std::string;
using std::cout;
using std::cin;
using std::endl;


Medusa::Medusa ()                               //Default Constructor
{
    creatureType = "Medusa";

    attk_Point = 0;
    def_Point = 0;

    arm_Point = 3;
    str_Point = 8;

    defeat = false;
}


Medusa::~Medusa ()                              //Deconstructor
{

}


string Medusa::get_Type ()                      //getter for creatureType
{
    return creatureType;
}


int Medusa::getArmor ()                             //getter for armor points
{
    return arm_Point;
}


int Medusa::get_Str ()                    //getter for strength points
{
    return str_Point;
}


bool Medusa::defeated ()                            //bool for whether Medusa is defeated or not
{
    return defeat;
}



int Medusa::attk ()                             //Medusa's attack function
{
    attk_Point = attk_Roll ();
    if (attk_Point == 12)
    {
        cout << "Medusa has called upon her special ability to use glare and turn her opponent into stone!" << endl;
        return attk_Point = 100;
    }
    else
    {
        cout << "Medusa uses " << attk_Point << " attack points!" << endl;
        return attk_Point;
    }
}



void Medusa::defend (int a)                     //Medusa's defend function
{
    int dmg = a;
    def_Point = def_Roll ();
    
    if (dmg == 100)
    {
        cout << "The Medusa has succumb fallen to the other Medusa's glare and turns into stone!" << endl;
        cout << "Medusa's strength points is now 0" << endl << endl;
        defeat = true;
    }
    
    else
    {
        cout << "Medusa uses " << def_Point << " defense points!" << endl;
        dmg = dmg - def_Point;
    
        cout << "Medusa uses " << arm_Point << " armor." << endl;
        dmg = dmg - arm_Point;
    
        cout << "Medusa received " << dmg << " points in damage." << endl;
   
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
            cout << "Medusa is still alive!" << endl;
            cout << "Strength points remaining: " << str_Point << endl << endl;
        }
        else if (str_Point <= 0)
        {
            cout << "Medusa is defeated." << endl;
            cout << "Strength points remaining: 0" << endl << endl;
            defeat = true;
        }
    }
}


int Medusa::attk_Roll ()                           //random generator for attack value
{
    int atk = rand () % 6 + 1;
    atk = atk + (rand () % 6 + 1);
    return atk;
}


int Medusa::def_Roll ()                          //random generator for defense value
{
    int def = rand () % 6 + 1;
    return def;
}


