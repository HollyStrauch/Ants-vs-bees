/**
 * Program: Ants-vs-bees
 * Author: Holly Strauch
 * Date: 11/15/19
 * File: Harvester.cpp
 *
 * Ants-vs-bees is a game on a 1D board.  The player runs the ants and their goal is to protect the queen on the 1st
 * space of the board.  They are being attacked by computer-generated bees that appear one per turn at the opposite
 * side of the board.  The player can choose from different kinds of ants and place them anywhere on the board.  Ants
 * cannot share a space with other ants unless otherwise specified.  The player wins if there are no bees left on the
 * board after a turn.  The computer wins if the bees reach the queen.
 *
 * Type of ant that increases the Ant food count by one every turn
 */

#include <iostream>
#include "Harvester.h"

///Constructor
Harvester::Harvester() : Ant() {
    cost = 2;
    armor = 1;
    type = 1;
}

/**
 * \brief Runs the turn for a Harvester Ant.  Does not attack, adds 1 food to Ant food stores
 * @param gameboard The current gameboard
 * @param currLoc, The position of the Harvester on the gameboard
 */
void Harvester::takeTurn(Cell* gameboard, int currLoc){
    cout << "Harvester Ant adds 1 food to the stash" << endl;
    Ant::addFood(1);
}