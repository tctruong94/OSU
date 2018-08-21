#include "Bluemen.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using std::string;
using std::cout;
using std::cin;
using std::endl;



Bluemen::Bluemen ()                                 //Default Constructor
{
    creatureType = "Blue Men";
    attk_Point = 0;
    def_Point = 0;
    arm_Point = 3;
    str_Point = 12;
    defeat = false;
}


Bluemen::~Bluemen ()                                //Deconstructor
{

}


string Bluemen::get_Type ()                          //getter for creatureType
{
    return creatureType;
}


int Bluemen::getArmor ()                            //getter for armor points
{
    return arm_Point;
}


int Bluemen::get_Str ()                   //getter for strength points
{
    return str_Point;
}


bool Bluemen::defeated ()                           //bool for whether or not bluemen is defeated or not
{
    return defeat;
}



int Bluemen::attk ()                                //Blue men's attack function
{
    attk_Point = attk_Roll ();
    cout << "Blue Men attacks with " << attk_Point << " attack points!" << endl;
    return attk_Point;
}



void Bluemen::defend (int a)                        //Blue men's defense function
{
    int dmg = a;
    def_Point = def_Roll ();
    
    if (dmg == 100)
    {
        cout << "The Blue Men have succumb to Medusa's glare and turn into stone!" << endl;
        cout << "The Blue Mens strength points is now 0" << endl << endl;
        defeat = true;
    }
    else
    {
        cout << "Blue Men uses " << def_Point << " defense points!" << endl;
        dmg = dmg - def_Point;
    
        cout << "Blue Men uses " << arm_Point << " armor." << endl;
        dmg = dmg - arm_Point;
    
        cout << "Blue Men recieved " << dmg << " points in damage." << endl;
       
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
        cout << "Blue Men is still alive!" << endl;
        cout << "Strength Points remaining: " << str_Point << endl << endl;
    }
    else if (str_Point <= 0)
    {
        cout << "Blue Men is defeated." << endl;
        cout << "Strength Points: 0" << endl << endl;
        defeat = true;
    }
    }
}


int Bluemen::attk_Roll ()                                  //random generator for attack points
{
    int atk = rand () % 10 + 1;
    atk = atk + (rand () % 10 + 1);
    return atk;
}



int Bluemen::def_Roll ()                                 //random generator for defense points
{
    if ((str_Point <= 12) && (str_Point >=9))
    {
        cout << "*Mob: The Blue Men are all standing strong! Three defense dice used." << endl;
        int def = rand () % 6 + 1;
        def = def + (rand () % 6 + 1);
        def = def + (rand () % 6 + 1);
        return def;
    }
    else if ((str_Point <= 8) && (str_Point >= 5))
    {
        cout << "*Mob: One of the Blue Men has fallen! Lost One defense die." << endl;
        int def = rand () % 6 + 1;
        def = def + (rand () % 6 + 1);
        return def;
    }
    else if ((str_Point <= 4) && (str_Point >= 0))
    {
        cout << "*Mob: Two of the Blue Men has fallen! Lost Two defense die." << endl;
        int def = rand () % 6 + 1;
        return def;
    }
}

