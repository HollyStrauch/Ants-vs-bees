//
// Created by Holly Strauch on 11/11/2019.
//

#ifndef ANTS_VS_BEES_HARVESTER_H
#define ANTS_VS_BEES_HARVESTER_H


#include "Ant.h"

class Harvester : public Ant{
public:
    Harvester();
    virtual void takeTurn();
};


#endif //ANTS_VS_BEES_HARVESTER_H
