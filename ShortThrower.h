//
// Created by Holly Strauch on 11/11/2019.
//

#ifndef ANTS_VS_BEES_SHORTTHROWER_H
#define ANTS_VS_BEES_SHORTTHROWER_H


#include "Ant.h"

class ShortThrower : public Ant{
public:
    virtual void takeTurn(vector<Bee>* attack);
};


#endif //ANTS_VS_BEES_SHORTTHROWER_H
