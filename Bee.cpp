//
// Created by Holly Strauch on 11/9/2019.
//

#include "Bee.h"

int Bee::beeCount = 0;

Bee::Bee(){
    this->range = 1;
    this->armor = 3;
    this->attack = 1;
}

/**
 * Assignment operator override
 * @param right
 * @return
 */
Bee& Bee::operator= (const Bee &right){

    if (&right == this)
        return (*this);

    this->armor = right.armor;
    this->attack = right.attack;
    this->range = right.range;

    return (*this);
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

void Bee::addBee() {
    beeCount++;
}

void Bee::killBee() {
    beeCount--;
}

int Bee::getCount(){
    return beeCount;
}