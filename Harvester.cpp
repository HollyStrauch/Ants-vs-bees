//
// Created by Holly Strauch on 11/11/2019.
//

#include "Harvester.h"

Harvester::Harvester() {
    cost = 2;
    armor = 1;
    type = 1;
    range = 0;
    attack = 0;
}

void Harvester::takeTurn(vector<Bee>* curr){
    Ant::addFood(1);
}