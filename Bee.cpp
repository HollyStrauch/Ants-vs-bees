/**
 * Program: Ants-vs-bees
 * Author: Holly Strauch
 * Date: 11/15/19
 * File: Bee.cpp
 *
 * Ants-vs-bees is a game on a 1D board.  The player runs the ants and their goal is to protect the queen on the 1st
 * space of the board.  They are being attacked by computer-generated bees that appear one per turn at the opposite
 * side of the board.  The player can choose from different kinds of ants and place them anywhere on the board.  Ants
 * cannot share a space with other ants unless otherwise specified.  The player wins if there are no bees left on the
 * board after a turn.  The computer wins if the bees reach the queen.
 *
 * Bee class inherits from Insect.  Bees are the computer run objects in the game, spawning every turn and attacking ants
 */

#include <iostream>
#include "Bee.h"
using namespace std;

/// Initializes beeCount to 0;
int Bee::beeCount = 0;

/**
 * Constructor
 */
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

///Returns how much damage the bee will do
int Bee::getAttack() const{
    return this->attack;
}

/**
 * \brief decreases the Bee's armor by the given amount
 * @param damage how much to deduct from the bee's armor
 */
void Bee::takeDamage(int damage) {
    this->armor -= damage;
}

///returns how many spaces away the Bee can attack
int Bee::getRange() const{
    return this->range;
}

///Returns the current armor of the Bee
int Bee::getArmor() const {
    return this->armor;
}

///Increments beeCount by 1
void Bee::addBee() {
    beeCount++;
}

///Decrements beeCount by 1 and prints to console
void Bee::killBee() {
    cout << "You have vanquished a Bee!" << endl;
    beeCount--;
}

///Returns current beeCount
int Bee::getCount(){
    return beeCount;
}

///Returns a string representation for Bee object
string Bee::typeToString(){
    return "Bee";
}

/**
 * \brief Method moves all bees from the startBee on in a cell to the next cell.  Bees receive damage if a ninja is was
 *  present
 * @param gameBoard, The current 1D game board
 * @param currCell, the cell the bees are moving from
 * @param startBee, the first bee in the current cell bee vector that is moving
 */
void Bee::moveBees(Cell* gameBoard, int currCell, int startBee) {
    for (int i = gameBoard[currCell].bees->size() - 1; i >= startBee; i--)
    {
        cout << "Bee advances to space " << currCell << endl;
        if (gameBoard[currCell].nj){
            cout << "Ninja cuts a Bee up for 1 damage" << endl;
            gameBoard[currCell].bees->at(i)->takeDamage(1);
        }

        if (gameBoard[currCell].bees->at(i)->getArmor() > 0) {
            gameBoard[currCell - 1].bees->push_back(gameBoard[currCell].bees->at(i));
        } else {
            Bee::killBee();
        }
        gameBoard[currCell].bees->pop_back();
    }
}

/**
 * \brief Bee attacks an ant on the same space. Bees will attack a bodyguard first, and may set off a fire ant.
 * @param gameBoard, The current 1D game board
 * @param currLoc, the cell of the gameboard the bee is in.
 */
void Bee::takeTurn(Cell* gameBoard, int currLoc){
    int bInd = findBG(gameBoard, currLoc);
    cout << "Bee attacks " << gameBoard[currLoc].ants->at(bInd)->typeToString() << " for 1 damage" << endl;
    gameBoard[currLoc].ants->at(bInd)->takeDamage(1);

    if (gameBoard[currLoc].ants->at(bInd)->getArmor() <= 0) {
        cout << "Ant " << gameBoard[currLoc].ants->at(bInd)->typeToString() << " has been killed in space " << currLoc + 1 << ". RIP." << endl;
        if (  gameBoard[currLoc].ants->at(bInd)->getType() == 3) {
            detonateFireAnt(gameBoard, currLoc);
        }
        gameBoard[currLoc].bg = false;
        gameBoard[currLoc].ants->erase(gameBoard[currLoc].ants->begin() + bInd);
    }
}

/**
 * \brief finds the location of a bodyguard ant, returns 0 if none. Does not pose issue with indexing, bees will attack
 *  first space if no bodyguard exists.
 * @param gameBoard, The current 1D game board
 * @param currCell, The cell of the gameboard the bee is in
 * @return
 */
int Bee::findBG(Cell* gameBoard, int currCell) {
    for ( int i = 0; i < gameBoard[currCell].ants->size(); i++){
        if (gameBoard[currCell].ants->at(i)->getType() == 8) {
            return i;
        }
    }
    return 0;
}

/**
 * \brief Method activates when a fire ant dies, killing all bees in the same space
 * @param gameBoard, The current 1D game board
 * @param loc the current space on the game board
 */
void Bee::detonateFireAnt(Cell* gameBoard, int loc) {

    cout << "Fire ant detonates!" << endl;
    int size = gameBoard[loc].bees->size();
    for (int i = 0; i < size; i++){
        gameBoard[loc].bees->pop_back();
        Bee::killBee();
    }
}

///Returns integer representation for Bee object
int Bee::getType() const {
    return -1;
}