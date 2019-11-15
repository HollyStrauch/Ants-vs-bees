/**
 * Program: Ants-vs-bees
 * Author: Holly Strauch
 * Date: 11/15/19
 * File: Cell.h
 *
 * Ants-vs-bees is a game on a 1D board.  The player runs the ants and their goal is to protect the queen on the 1st
 * space of the board.  They are being attacked by computer-generated bees that appear one per turn at the opposite
 * side of the board.  The player can choose from different kinds of ants and place them anywhere on the board.  Ants
 * cannot share a space with other ants unless otherwise specified.  The player wins if there are no bees left on the
 * board after a turn.  The computer wins if the bees reach the queen.
 *
 * Cell is what the gameboard is comprised of.  Contains boolean flags for Bodyguard and Ninja ants, along with vectors
 * for holding ants and bees.
 */

#ifndef ANTS_VS_BEES_CELL_H
#define ANTS_VS_BEES_CELL_H
using namespace std;

#include <vector>
#include "Insect.h"

class Insect;
struct Cell {
    bool bg;
    bool nj;
    vector<Insect*>* bees;
    vector<Insect*>* ants;
};

#endif //ANTS_VS_BEES_CELL_H
