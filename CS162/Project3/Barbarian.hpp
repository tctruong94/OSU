#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Creature.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>


using std::string;
using std::cout;
using std::cin;
using std::endl;

class Barbarian: public Creature                //Barbarian Class
{
    public:
    Barbarian ();
    ~Barbarian ();

    string get_Type ();

    int getArmor ();
    int get_Str ();

    int attk ();
    void defend (int damage);

    int attk_Roll ();
    int def_Roll ();

    bool defeated ();
};

#endif
