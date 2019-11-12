//
// Created by Holly Strauch on 11/9/2019.
//

#include "Ant.h"

Ant::Ant(){
    this->armor = 1;
    this->cost = 2;
    this->range = 1;
    this->attack = 1;
}

int Ant::getRange() const {
    return this->range;
}

int Ant::getAttack() const {
    return this->attack;
}

void Ant::takeDamage(int damage) {
    this->armor -= damage;
}

int Ant::getArmor() const {
    return this->armor;
}

int Ant::getCost() const {
    return this->cost;
}

int Ant::getType() const {
    return this->type;
}