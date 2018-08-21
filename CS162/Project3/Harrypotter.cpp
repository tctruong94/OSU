#include "Harrypotter.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using std::string;
using std::cout;
using std::cin;
using std::endl;



Harrypotter::Harrypotter ()                             //Default construcotr
{
    creatureType = "Harry Potter";
    attk_Point = 0;
    def_Point = 0;
    arm_Point = 0;
    str_Point = 10;
    defeat = false;
}



Harrypotter::~Harrypotter ()                            //Deconstructor
{

}



string Harrypotter::get_Type ()                             //getter for creatureType
{
    return creatureType;
}


int Harrypotter::getArmor ()                                    //getter for armor points
{
    return arm_Point;
}


int Harrypotter::get_Str ()                           //getetr for strength points
{
    return str_Point;
}


bool Harrypotter::defeated ()                                   //bool for whether Harry Potter has been defeated or not
{
    return defeat;
}


int Harrypotter::attk ()                                //Harry Potter attack function
{
    attk_Point = attk_Roll ();
    cout << "Harry Potter uses " << attk_Point << " attack points!" << endl;
    return attk_Point;
}


void Harrypotter::defend (int d)                        //Harry Potter defense function
{
    int damage = d;
    bool hogwarts = true;
    def_Point = def_Roll ();
    
    if (damage == 100)
    {
        cout << "Harry Potter has succumb to Medusa's glare and turns into stone!" << endl;
        cout << "Strength Points: 0" << endl << endl;
        str_Point = 0;
        
        if (hogwarts == true)
        {
            cout << "Harry Potter activates his special ability Hogwarts!" << endl;
            cout << "Harry Potter is revived and returns with 20 strength points!" << endl;
            str_Point = 20;
            hogwarts = false;
            defeat = false;
        }
        else if (hogwarts == false)
        {
            cout << "Harry Potter attempts to use his special ability Hogwarts!" << endl;
            cout << "It seems as though he has failed his attempt." << endl;
            defeat = true;
        }
    }
    
    else
    {
        cout << "Harry Potter uses " << def_Point << " defense points!" << endl;
        damage = damage - def_Point;
    
        cout << "Harry Potter uses " << arm_Point << " armor." << endl;
        damage = damage - arm_Point;
    
        cout << "Harry Potter received " << damage << " points in damage." << endl;
   
        if (damage > 0)
        {
            str_Point = str_Point - damage;
        }
        else
        {
            str_Point = str_Point;
        }
 

        if (str_Point > 0)
        {
            cout << "Harry Potter is still alive!" << endl;
            cout << "Strength points remaining: " << str_Point << endl << endl;
        }
        else if ((str_Point <= 0) && (hogwarts == true))
        {
            cout << "Harry Potter is defeated." << endl;
            cout << "Strength points remaining: 0" << endl;
            cout << "Harry Potter activates his special ability Hogwarts!" << endl;
            cout << "Harry Potter is revived with 20 strength points!" << endl;
            str_Point = 20;
            cout << "Strength points remaining: 20" << endl << endl;
            defeat = false;
            hogwarts = false;
        }
        else if ((str_Point <= 0) && (hogwarts == false))
        {
            cout << "Harry Potter is defeated." << endl;
            cout << "Strength Points: 0" << endl << endl;
            defeat = true;
        }
    }
}



int Harrypotter::attk_Roll ()                                  //random generator for attack points
{
    int atk = rand () % 6 + 1;
    atk = atk + (rand () % 6 + 1);
    return atk;
}


int Harrypotter::def_Roll ()                                 //ranodm generator for defense points
{
    int def = rand () % 6 + 1;
    def = def + (rand () % 6 + 1);
    return def;
}



