/**
 * Program: Ants-vs-bees
 * Author: Holly Strauch
 * Date: 11/15/19
 * File: Ant.cpp
 *
 * Ants-vs-bees is a game on a 1D board.  The player runs the ants and their goal is to protect the queen on the 1st
 * space of the board.  They are being attacked by computer-generated bees that appear one per turn at the opposite
 * side of the board.  The player can choose from different kinds of ants and place them anywhere on the board.  Ants
 * cannot share a space with other ants unless otherwise specified.  The player wins if there are no bees left on the
 * board after a turn.  The computer wins if the bees reach the queen.
 *
 * Ant class inherits from Insect and is the parent class for all ant types.
 */

#ifndef ANTS_VS_BEES_ANT_H
#define ANTS_VS_BEES_ANT_H

#include <string>
#include <vector>
#include "Insect.h"
#include "Bee.h"
#include "Cell.h"

using namespace std;

class Ant : public Insect{
protected:
    int cost;
    int type;
    static int food;
public:
    Ant();
    virtual int getAttack() const;
    virtual void takeDamage(int damage);
    virtual int getRange() const;
    virtual int getArmor() const;
    int getType() const;
    int getCost() const;
    virtual void takeTurn(Cell* gameboard, int currLoc);
    static void addFood(int amount);
    static void removeFood(int amount);
    static int getFood();
    virtual string typeToString();
};


#endif //ANTS_VS_BEES_ANT_H
