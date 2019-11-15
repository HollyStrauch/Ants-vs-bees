/**
 * Program: Ants-vs-bees
 * Author: Holly Strauch
 * Date: 11/15/19
 * File: Thrower.cpp
 *
 * Ants-vs-bees is a game on a 1D board.  The player runs the ants and their goal is to protect the queen on the 1st
 * space of the board.  They are being attacked by computer-generated bees that appear one per turn at the opposite
 * side of the board.  The player can choose from different kinds of ants and place them anywhere on the board.  Ants
 * cannot share a space with other ants unless otherwise specified.  The player wins if there are no bees left on the
 * board after a turn.  The computer wins if the bees reach the queen.
 *
 * Type of ant that attacks a Bee in the same space as itself
 */

#include <iostream>
#include "Thrower.h"

///Constructor
Thrower::Thrower() : Ant() {
    this->type = 2;
    this->cost = 4;
    this->armor = 1;
    this->attack = 1;
}

/**
 * \brief Turn for Thrower attacks one bee in the same space as itl
 * @param gameboard The current gameboard
 * @param currLoc The position of the Thrower on the gameboard
 */
void Thrower::takeTurn(Cell* gameboard, int currLoc){
    if (gameboard[currLoc].bees->empty()) {
        return;
    }
    cout << "Thrower ant attacks!" << endl;
    gameboard[currLoc].bees->at(0)->takeDamage(this->attack);

    if (gameboard[currLoc].bees->at(0)->getArmor() == 0){
        Bee::killBee();
        gameboard[currLoc].bees->erase(gameboard[currLoc].bees->begin());
    }

}