//
// Created by Holly Strauch on 11/9/2019.
//

#ifndef ANTS_VS_BEES_INSECT_H
#define ANTS_VS_BEES_INSECT_H


class Insect {
protected:
    int armor;
    int attack;
    int range;
public:
    virtual int getRange() const = 0;
    virtual int getAttack() const = 0;
    virtual int getArmor() const = 0;
    virtual void takeDamage(int damage) = 0;
};


#endif //ANTS_VS_BEES_INSECT_H
