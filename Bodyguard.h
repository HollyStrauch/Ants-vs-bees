/**
 * Program: Ants-vs-bees
 * Author: Holly Strauch
 * Date: 11/15/19
 * File: Bodyguard.h
 *
 * Ants-vs-bees is a game on a 1D board.  The player runs the ants and their goal is to protect the queen on the 1st
 * space of the board.  They are being attacked by computer-generated bees that appear one per turn at the opposite
 * side of the board.  The player can choose from different kinds of ants and place them anywhere on the board.  Ants
 * cannot share a space with other ants unless otherwise specified.  The player wins if there are no bees left on the
 * board after a turn.  The computer wins if the bees reach the queen.
 *
 * Bodyguard is a type of ant that stands in one space and takes all damage from bees, protecting the other ant in its
 * space.  It is the only ant that can share a space with another ant.
 */

#ifndef ANTS_VS_BEES_BODYGUARD_H
#define ANTS_VS_BEES_BODYGUARD_H


#include "Ant.h"

class Bodyguard : public Ant{
public:
    Bodyguard();
    Bodyguard(Bodyguard &orig);
    virtual void takeTurn(Cell* gameboard, int currLoc);
};


#endif //ANTS_VS_BEES_BODYGUARD_H
