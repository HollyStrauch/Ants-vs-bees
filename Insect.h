/**
 * Program: Ants-vs-bees
 * Author: Holly Strauch
 * Date: 11/15/19
 * File: Insect.h
 *
 * Ants-vs-bees is a game on a 1D board.  The player runs the ants and their goal is to protect the queen on the 1st
 * space of the board.  They are being attacked by computer-generated bees that appear one per turn at the opposite
 * side of the board.  The player can choose from different kinds of ants and place them anywhere on the board.  Ants
 * cannot share a space with other ants unless otherwise specified.  The player wins if there are no bees left on the
 * board after a turn.  The computer wins if the bees reach the queen.
 *
 * Virtual class which is the parent class for Bees and Ants
 */


#ifndef ANTS_VS_BEES_INSECT_H
#define ANTS_VS_BEES_INSECT_H

#include "Cell.h"

using namespace std;

struct Cell;

class Insect {
protected:
    int armor;
    int attack;
    int range;
public:
    virtual int getRange() const = 0;
    virtual int getAttack() const = 0;
    virtual int getArmor() const = 0;
    virtual int getType() const = 0;
    virtual void takeDamage(int damage) = 0;
    virtual string typeToString() = 0;
    virtual void takeTurn(Cell* gameboard, int currLoc) = 0;
};


#endif //ANTS_VS_BEES_INSECT_H
