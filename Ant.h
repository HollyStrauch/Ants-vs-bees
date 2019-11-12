//
// Created by Holly Strauch on 11/9/2019.
//

#ifndef ANTS_VS_BEES_ANT_H
#define ANTS_VS_BEES_ANT_H

#include "Insect.h"

class Ant : public Insect{
protected:
    int cost;
    int type;
public:
    Ant();
    virtual int getAttack() const;
    virtual void takeDamage(int damage);
    virtual int getRange() const;
    virtual int getArmor() const;
    int getType() const;
    int getCost() const;
    virtual void takeTurn() = 0;
};


#endif //ANTS_VS_BEES_ANT_H
