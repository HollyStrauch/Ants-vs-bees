//
// Created by Holly Strauch on 11/11/2019.
//

#include "Fire.h"
#include "Bee.h"

Fire::Fire(){
    this->type = 3;
    this->cost = 4;
    this->range = 0;
    this->attack = 3;
    this->armor = 1;
}

void Fire::takeTurn(vector<Bee>* curr){
    for (int i = 0; i < curr->size(); i++){
        curr->pop_back();
        Bee::killBee();
    }
}