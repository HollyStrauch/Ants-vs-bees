//
// Created by Holly Strauch on 11/9/2019.
//

#include "Bee.h"

Bee::Bee(){
    this->range = 1;
    this->armor = 3;
    this->attack = 1;
}

int Bee::getAttack() const{
    return this->attack;
}

void Bee::takeDamage(int damage) {
    this->armor -= damage;
}

int Bee::getRange() const{
    return this->getRange();
}

int Bee::getArmor() const {
    return this->armor;
}