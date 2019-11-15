/**
 * Program: Ants-vs-bees
 * Author: Holly Strauch
 * Date: 11/15/19
 * File: LongThrower.h
 *
 * Ants-vs-bees is a game on a 1D board.  The player runs the ants and their goal is to protect the queen on the 1st
 * space of the board.  They are being attacked by computer-generated bees that appear one per turn at the opposite
 * side of the board.  The player can choose from different kinds of ants and place them anywhere on the board.  Ants
 * cannot share a space with other ants unless otherwise specified.  The player wins if there are no bees left on the
 * board after a turn.  The computer wins if the bees reach the queen.
 *
 * Type of ant that attacks the closest Bee that is 4 spaces away or further.
 */

#ifndef ANTS_VS_BEES_LONGTHROWER_H
#define ANTS_VS_BEES_LONGTHROWER_H


#include "Ant.h"

class LongThrower : public Ant {
public:
    LongThrower();
    virtual void takeTurn(Cell* gameboard, int currLoc);
};


#endif //ANTS_VS_BEES_LONGTHROWER_H
