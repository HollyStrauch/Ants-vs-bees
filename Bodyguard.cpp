/**
 * Program: Ants-vs-bees
 * Author: Holly Strauch
 * Date: 11/15/19
 * File: Bodyguard.cpp
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

#include "Bodyguard.h"

///Constructor
Bodyguard::Bodyguard() : Ant() {
    this->type = 8;
    this->armor = 2;
    this->cost = 4;
}

/**
 * Copy constructor
 * @param orig
 */
Bodyguard::Bodyguard(Bodyguard &orig){
    this->armor = orig.armor;
    this->attack = orig.attack;
    this->range = orig.range;
    this->cost = orig.cost;
    this->type = orig.type;
}

///Bodyguard's turn.  Does nothing.
void Bodyguard::takeTurn(Cell* gameboard, int currLoc){

}
