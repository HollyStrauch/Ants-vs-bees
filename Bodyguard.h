//
// Created by Holly Strauch on 11/11/2019.
//

#ifndef ANTS_VS_BEES_BODYGUARD_H
#define ANTS_VS_BEES_BODYGUARD_H


#include "Ant.h"

class Bodyguard : public Ant{
public:
    Bodyguard();
    Bodyguard(Bodyguard &orig);
    virtual void takeTurn(vector<Bee>* curr);
};


#endif //ANTS_VS_BEES_BODYGUARD_H
