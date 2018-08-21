#include "Vampire.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using std::string;
using std::cout;
using std::cin;
using std::endl;



Vampire::Vampire ()                                     //Default Construcotr
{
    creatureType = "Vampire";
    attk_Point = 0;
    def_Point = 0;
    arm_Point = 1;
    str_Point = 12;
    defeat = false;
}



Vampire::~Vampire ()                                    //Decontructor
{

}


string Vampire::get_Type ()                              //getter for creatureType
{
    return creatureType;
}


int Vampire::getArmor ()                                //getter for armor points
{
    return arm_Point;
}


int Vampire::get_Str ()                       //getter for strength points
{
    return str_Point;
}


bool Vampire::defeated ()                               //bool for whether vampire has been defeated or not
{
    return defeat;
}


int Vampire::attk ()                                    //Vampire attack function
{
    attk_Point = attk_Roll ();
    cout << "Vampire attacks with " << attk_Point << " attack points!" << endl;
    return attk_Point;
}


void Vampire::defend (int a)                            //Vampire defend function
{
    int dmg = a;
    def_Point = def_Roll ();
    
    int charmChance = rand () % 2 + 1;
    
    if ((dmg == 100) && (charmChance == 1))
    {
        cout << "The Vampire uses charm to keep Medusa from attacking." << endl;
        cout << "Strength Points: " << str_Point << endl;
        defeat = false;
    }
    
    else if ((dmg == 100) && (charmChance != 1))
    {
        cout << "The Vampire has succumb to Medusa's glare and turns into stone!" << endl;
        cout << "The Vampire's strength points is now 0" << endl;
        str_Point = 0;
        defeat = true;
    }
    
    else if ((dmg != 100) && (charmChance == 1))
    {
        cout << "Vampire uses its special ability Charm! Vampire's opponent cannot attack." << endl;
        cout << "Strength Points remaining: " << str_Point << endl << endl;
        dmg = 0;
    }
    
    else
    {
        cout << "Vampire uses " << def_Point << " defense points!" << endl;
        dmg = dmg - def_Point;
    
        cout << "Vampire uses " << arm_Point << " armor." << endl;
        dmg = dmg - arm_Point;
    
        cout << "Vampire received " << dmg << " points in damage." << endl;
   
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
            cout << "Vampire is still alive!!" << endl;
            cout << "Strength points remaining: " << str_Point << endl << endl;
        }
        else if (str_Point <= 0)
        {
            cout << "Vampire is defeated." << endl;
            cout << "Strength points: 0" << endl << endl;
            defeat = true;
        }
    }
}



int Vampire::attk_Roll ()                              //random generator for attack points
{
    int atk = rand () % 12 + 1;
    return atk;
}


int Vampire::def_Roll ()                             //random generator for defense points
{
    int def = rand () % 6 + 1;
    return def;
}



