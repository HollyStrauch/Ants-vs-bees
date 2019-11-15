/**
 * Program: Ants-vs-bees
 * Author: Holly Strauch
 * Date: 11/15/19
 * File: Ant.cpp
 *
 * Ants-vs-bees is a game on a 1D board.  The player runs the ants and their goal is to protect the queen on the 1st
 * space of the board.  They are being attacked by computer-generated bees that appear one per turn at the opposite
 * side of the board.  The player can choose from different kinds of ants and place them anywhere on the board.  Ants
 * cannot share a space with other ants unless otherwise specified.  The player wins if there are no bees left on the
 * board after a turn.  The computer wins if the bees reach the queen.
 *
 * Ant class inherits from Insect and is the parent class for all ant types.
 */

#include "Ant.h"

///Initialize ant food stores to 50
int Ant::food = 50;

///Default constructor
Ant::Ant(){
    this->armor = 0;
    this->cost = 0;
    this->range = 0;
    this->attack = 0;
    this->type = 0;
}

/**
 * \brief Adds food to stores
 * @param amount, the amount of food to increase by
 */
void Ant::addFood(int amount){
    Ant::food += amount;
}

/**
 * \brief Removess food to stores
 * @param amount, the amount of food to decrease by
 */
void Ant::removeFood(int amount){
    Ant::food -= amount;
}

///Returns how much food the colony has available
int Ant::getFood(){
    return Ant::food;
}

///Returns the attack range of an ant
int Ant::getRange() const {
    return this->range;
}

///Returns the attacking power of an ant
int Ant::getAttack() const {
    return this->attack;
}

/**
 * \brief Decreases an ant's armor by the given amount
 * @param damage, the amount the decrease an ant's armor by
 */
void Ant::takeDamage(int damage) {
    this->armor -= damage;
}

/// Returns the current armor of an ant
int Ant::getArmor() const {
    return this->armor;
}

///Returns the cost of a type of ant
int Ant::getCost() const {
    return this->cost;
}

///Returns the integer representation of the ant type
int Ant::getType() const {
    return this->type;
}

///Returns the string representation of the ant type
string Ant::typeToString() {
    switch(this->type){
        case 1: return "H";
        case 2: return "T";
        case 3: return "F";
        case 4: return "L";
        case 5: return "S";
        case 6: return "W";
        case 7: return "N";
        case 8: return "B";
    }
    return "";
}

/**
 * \brief Dictates what an ant does on its turn
 * @param gameboard, the current gameboard passed in from Game
 * @param currLoc, the location on the board the ant is at.
 */
void Ant::takeTurn(Cell* gameboard, int currLoc){
}