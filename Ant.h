//
// Created by Holly Strauch on 11/9/2019.
//

#ifndef ANTS_VS_BEES_ANT_H
#define ANTS_VS_BEES_ANT_H

#include <string>
#include <vector>
#include "Insect.h"
#include "Bee.h"
using namespace std;

class Ant : public Insect{
protected:
    int cost;
    int type;
    static int food;
public:
    Ant();
    virtual int getAttack() const;
    virtual void takeDamage(int damage);
    virtual int getRange() const;
    virtual int getArmor() const;
    int getType() const;
    int getCost() const;
    virtual void takeTurn(vector<Bee>* attack);
    static void addFood(int amount);
    static void removeFood(int amount);
    static int getFood();
    string typeToString();
};


#endif //ANTS_VS_BEES_ANT_H
