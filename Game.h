/**
 * Program: Ants-vs-bees
 * Author: Holly Strauch
 * Date: 11/15/19
 * File: Game.h
 *
 * Ants-vs-bees is a game on a 1D board.  The player runs the ants and their goal is to protect the queen on the 1st
 * space of the board.  They are being attacked by computer-generated bees that appear one per turn at the opposite
 * side of the board.  The player can choose from different kinds of ants and place them anywhere on the board.  Ants
 * cannot share a space with other ants unless otherwise specified.  The player wins if there are no bees left on the
 * board after a turn.  The computer wins if the bees reach the queen.
 *
 * Game controls the board and general gameplay.  Bees generate, user can place ants, and ants and bees attack or move.
 */

#ifndef ANTS_VS_BEES_GAME_H
#define ANTS_VS_BEES_GAME_H


#include <string>
#include <iostream>
#include <vector>
#include "Ant.h"
#include "Bee.h"
#include "Cell.h"

using namespace std;

class Game {

    Cell* gameBoard;

public:
    Game();
    ~Game();
    void intro();
    void finish();
    Cell* initGameBoard();
    void placeAnt(Ant* newAnt);
    int userInput(int lower, int upper);
    Ant* selectAnt(int type);
    void runGame();
    void generateBee();
    void generateAnt();
    void antAttack();
    void beeAttack();
    void printAntInfo();
    bool canPlaceAnt();
    bool checkQueen();
    void printBoard();
    bool inputYN();
    void placeBG(Ant *bg);

};


#endif //ANTS_VS_BEES_GAME_H
