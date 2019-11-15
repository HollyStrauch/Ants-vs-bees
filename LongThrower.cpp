/**
 * Program: Ants-vs-bees
 * Author: Holly Strauch
 * Date: 11/15/19
 * File: LongThrower.cpp
 *
 * Ants-vs-bees is a game on a 1D board.  The player runs the ants and their goal is to protect the queen on the 1st
 * space of the board.  They are being attacked by computer-generated bees that appear one per turn at the opposite
 * side of the board.  The player can choose from different kinds of ants and place them anywhere on the board.  Ants
 * cannot share a space with other ants unless otherwise specified.  The player wins if there are no bees left on the
 * board after a turn.  The computer wins if the bees reach the queen.
 *
 * Type of ant that attacks the closest Bee that is 4 spaces away or further.
 */

#include <iostream>
#include "LongThrower.h"

/// COnstructor
LongThrower ::LongThrower() : Ant() {
    this->type = 4;
    this->cost = 3;
    this->armor = 1;
    this->range = 4;
    this->attack = 1;
}

/**
 * \brief Turn looks for the closest Bee that is 4 spaces away or farther
 * @param gameboard The current gameboard
 * @param currLoc, The location of the LongThrower on the gameboard
 */
void LongThrower::takeTurn(Cell* gameboard, int currLoc){
    if (currLoc + 4 >= 10){
        return;
    }

    for (int i = currLoc + 4; i < 10; i++) {
        if (!gameboard[i].bees->empty()) {
            cout << "Long Thrower ant attacks space " << i + 1 << endl;
            gameboard[i].bees->at(0)->takeDamage(this->attack);

            if (gameboard[i].bees->at(0)->getArmor() == 0) {
                Bee::killBee();
                gameboard[i].bees->erase(gameboard[i].bees->begin());
            }
            break;
        }
    }
}