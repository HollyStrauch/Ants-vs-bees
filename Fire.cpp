/**
 * Program: Ants-vs-bees
 * Author: Holly Strauch
 * Date: 11/15/19
 * File: Fire.cpp
 *
 * Ants-vs-bees is a game on a 1D board.  The player runs the ants and their goal is to protect the queen on the 1st
 * space of the board.  They are being attacked by computer-generated bees that appear one per turn at the opposite
 * side of the board.  The player can choose from different kinds of ants and place them anywhere on the board.  Ants
 * cannot share a space with other ants unless otherwise specified.  The player wins if there are no bees left on the
 * board after a turn.  The computer wins if the bees reach the queen.
 *
 * Fire is a type of ant that, upon dying, kills all bees occupying the same space as it.
 */

#include "Fire.h"
#include "Bee.h"

///Constructor
Fire::Fire(): Ant(){
    this->type = 3;
    this->cost = 4;
    this->attack = 3;
    this->armor = 1;
}

///Fire does nothing on its turn.  It activates when it dies.
void Fire::takeTurn(Cell* gameboard, int currLoc){

}