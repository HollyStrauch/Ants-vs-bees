//
// Created by Holly Strauch on 11/11/2019.
//

#ifndef ANTS_VS_BEES_FIRE_H
#define ANTS_VS_BEES_FIRE_H


#include "Ant.h"
#include "Game.h"

class Fire : public Ant{
public:
    Fire();
    virtual void takeTurn(vector<Bee>* curr);
};


#endif //ANTS_VS_BEES_FIRE_H
