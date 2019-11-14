//
// Created by Holly Strauch on 11/11/2019.
//

#ifndef ANTS_VS_BEES_NINJA_H
#define ANTS_VS_BEES_NINJA_H


#include "Ant.h"

class Ninja : public Ant {
public:
    Ninja();
    virtual void takeTurn(vector<Bee>* curr);
    virtual void takeDamage(int damage);
};


#endif //ANTS_VS_BEES_NINJA_H
