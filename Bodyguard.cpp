//
// Created by Holly Strauch on 11/11/2019.
//

#include "Bodyguard.h"

Bodyguard::Bodyguard() : Ant() {
    this->type = 8;
    this->armor = 4;
    this->cost = 4;
}

Bodyguard::Bodyguard(Bodyguard &orig){
    this->armor = orig.armor;
    this->attack = orig.attack;
    this->range = orig.range;
    this->cost = orig.cost;
    this->type = orig.type;
}

void Bodyguard::takeTurn(vector<Bee>* curr){

}
