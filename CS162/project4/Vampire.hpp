#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Creature.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>


class Vampire: public Creature                      //Vampire Class declaration
{
    public:
        Vampire (int a, int s)
            : Creature(a,s) {
            }

        virtual bool attack (Creature* defender, std::string def);
        virtual int defend(int att);
};

#endif

