/**
 * Program: Ants-vs-bees
 * Author: Holly Strauch
 * Date: 11/15/19
 * File: Bee.h
 *
 * Ants-vs-bees is a game on a 1D board.  The player runs the ants and their goal is to protect the queen on the 1st
 * space of the board.  They are being attacked by computer-generated bees that appear one per turn at the opposite
 * side of the board.  The player can choose from different kinds of ants and place them anywhere on the board.  Ants
 * cannot share a space with other ants unless otherwise specified.  The player wins if there are no bees left on the
 * board after a turn.  The computer wins if the bees reach the queen.
 *
 * Bee class inherits from Insect.  Bees are the computer run objects in the game, spawning every turn and attacking ants
 */

#ifndef ANTS_VS_BEES_BEE_H
#define ANTS_VS_BEES_BEE_H


#include "Insect.h"

class Bee : public Insect {
    static int beeCount;
public:
    Bee();
    Bee &operator= (const Bee &right);
    virtual int getAttack() const;
    virtual void takeDamage(int damage);
    virtual int getRange() const;
    virtual int getArmor() const;
    virtual string typeToString();
    virtual int getType() const;
    static void addBee();
    static void killBee();
    static int getCount();
    virtual void takeTurn(Cell* gameboard, int currLoc);
    void detonateFireAnt(Cell* gameBoard, int loc);
    int findBG(Cell* gameBoard, int currCell);
    static void moveBees(Cell* gameBoard, int currCell, int startBee);
};


#endif //ANTS_VS_BEES_BEE_H
