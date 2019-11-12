//
// Created by Holly Strauch on 11/9/2019.
//

#ifndef ANTS_VS_BEES_BEE_H
#define ANTS_VS_BEES_BEE_H


#include "Insect.h"

class Bee : public Insect {
public:
    Bee();
    virtual int getAttack() const;
    virtual void takeDamage(int damage);
    virtual int getRange() const;
    virtual int getArmor() const;
};


#endif //ANTS_VS_BEES_BEE_H
