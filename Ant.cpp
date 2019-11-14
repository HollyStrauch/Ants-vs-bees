//
// Created by Holly Strauch on 11/9/2019.
//

#include "Ant.h"

int Ant::food = 50;

Ant::Ant(){
    this->armor = 0;
    this->cost = 0;
    this->range = 0;
    this->attack = 0;
    this->type = 0;
}

void Ant::addFood(int amount){
    Ant::food += amount;
}

void Ant::removeFood(int amount){
    Ant::food -= amount;
}

int Ant::getFood(){
    return Ant::food;
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

string Ant::typeToString() {
    switch(this->type){
        case 1: return "H";
        case 2: return "T";
        case 3: return "F";
        case 4: return "L";
        case 5: return "S";
        case 6: return "N";
        case 7: return "B";

    }
    return "";
}

void Ant::takeTurn(vector<Bee>* attack){
    return;
}