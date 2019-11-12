//
// Created by Holly Strauch on 11/11/2019.
//

#ifndef ANTS_VS_BEES_GAME_H
#define ANTS_VS_BEES_GAME_H


#include <string>
#include <iostream>
#include <vector>
#include "Ant.h"
#include "Bee.h"

using namespace std;

class Game {

    struct Cell {
        vector<Bee*>* bees;
        vector<Ant*>* ants;
    };

    int food;
    int beeCount;
    Cell* gameBoard;

public:
    Game();
    Cell* initGameBoard();
    Ant* createAnt();
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
    bool checkForAnt();
    Ant* fullBoard();
    int getFood() const;
    bool checkQueen();
    void printBoard();

};


#endif //ANTS_VS_BEES_GAME_H
