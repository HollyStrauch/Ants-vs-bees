//
// Created by Holly Strauch on 11/9/2019.
//

#ifndef ANTS_VS_BEES_BEE_H
#define ANTS_VS_BEES_BEE_H


#include "Insect.h"

class Bee : public Insect {
    static int beeCount;
public:
    Bee();
    Bee &operator= (const Bee &right);
    virtual int getAttack() const;
    virtual void takeDamage(int damage);
    virtual int getRange() const;
    virtual int getArmor() const;
    static void addBee();
    static void killBee();
    static int getCount();
};


#endif //ANTS_VS_BEES_BEE_H
