/**
 * Program: Ants-vs-bees
 * Author: Holly Strauch
 * Date: 11/15/19
 * File: Game.cpp
 *
 * Ants-vs-bees is a game on a 1D board.  The player runs the ants and their goal is to protect the queen on the 1st
 * space of the board.  They are being attacked by computer-generated bees that appear one per turn at the opposite
 * side of the board.  The player can choose from different kinds of ants and place them anywhere on the board.  Ants
 * cannot share a space with other ants unless otherwise specified.  The player wins if there are no bees left on the
 * board after a turn.  The computer wins if the bees reach the queen.
 *
 * Game controls the board and general gameplay.  Bees generate, user can place ants, and ants and bees attack or move.
 */

#include "Game.h"
#include "Ant.h"
#include "Harvester.h"
#include "Thrower.h"
#include "Fire.h"
#include "LongThrower.h"
#include "ShortThrower.h"
#include "Wall.h"
#include "Ninja.h"
#include "Bodyguard.h"

///Constructor
Game::Game(){
    gameBoard = initGameBoard();
}

///Destructor
Game::~Game(){
    for (int i = 0; i < 10; i++){
        gameBoard[i].bees->clear();
        gameBoard[i].ants->clear();
        delete gameBoard[i].bees;
        delete gameBoard[i].ants;
    }
    delete [] gameBoard;
}


///Initializes the gameboard of Cells
Cell* Game::initGameBoard(){
    Cell* gameBoard = new Cell[10];
    for (int i = 0; i < 10; i++){
        gameBoard[i].bg = false;
        gameBoard[i].nj = false;
        gameBoard[i].bees = new vector<Insect*>;
        gameBoard[i].ants = new vector<Insect*>;
    }

    return gameBoard;
}

/// Runs the main game play: generate Bee, place Ant, then have ants then bees attack left to right.
void Game::runGame(){

    intro();
    do {
        generateBee();
        cout << "Would you like to place a new ant? Current food: " << Ant::getFood() << endl;
        if (inputYN()) {
            generateAnt();
        }
        printBoard();
        cout << "\nANTS ATTACK" << endl;
        antAttack();
        cout << "\nBEES ATTACK" << endl;
        beeAttack();
    }while(Bee::getCount() != 0 && checkQueen());

    finish();
}

///Prints out an introduction to the game
void Game::intro(){

    cout << "#############################################################################" << endl;
    cout << "\nWELCOME TO ANTS VS BEES!\n\nYou are the ants.  I am the bees." << endl;
    cout << "Your goal is to wipe my kind off the board. My goal is to reach your queen." << endl;
    cout << "\n\nCome at me.\n" << endl;
    cout << "#############################################################################\n\n" << endl;

}

///Prints out the closing text after the game has ended
void Game::finish(){
    cout << "\n\n#############################################################################" << endl;
    if (Bee::getCount() == 0){
        cout << "You have bested me! Congratulations." << endl;
    } else {
        cout << "I have won! Your queen is mine.\nWe are going to another castle. Ha Ha Ha." << endl;
    }

    cout << "#############################################################################" << endl;
}

/***
 * \brief checks to see if a bee has reached the queen
 * @return true if there are no bees in the same space as the queen
 */
bool Game::checkQueen() {
    return this->gameBoard[0].bees->empty();
}

/**
 * \brief Creates a new Bee and adds it to the gameboard at Cell 9
 */
void Game::generateBee() {
    cout << "A NEW BEE HAS LEFT THE HIVE" << endl;
    Bee* newBee = new Bee();
    this->gameBoard[9].bees->push_back(newBee);
    Bee::addBee();
}

/**
 * \brief Allows user to pick and place a new Ant onto the board
 */
void Game::generateAnt() {
    while (true) {
        printAntInfo();
        int type = userInput(1, 8);
        Ant *ant = selectAnt(type);

        if (ant->getCost() > Ant::getFood()){
            cout << "You cannot afford that ant";
            delete ant;
            ant = nullptr;
        } else if (type == 8) {
            placeBG(ant);
            return;
        } else if (!canPlaceAnt()) {
            cout << "Board is full, cannot place ant" << endl;
            delete ant;
            ant = nullptr;
        }else {
            placeAnt(ant);
            return;
        }
    }
}

/**
 * \brief places a Bodyguard ant on the board, flipping the boolean flag
 * @param bg A pointer to a Bodyguard Ant
 */
void Game::placeBG(Ant *bg) {
    cout << "Enter the position on the board you would like to place the bodyguard, or 0 to exit" << endl;
    cout << "\t[Q 1|2|3|4|5|6|7|8|9|10]" << endl;

    while ( true ){
        int pos = userInput(0, 10) - 1;
        if (pos == -1){
            break;
        }
        if (!gameBoard[pos].bg){
            gameBoard[pos].ants->push_back(bg);
            gameBoard[pos].bg = true;
            Ant::removeFood(bg->getCost());
            break;
        }
        cout << "There is already a body guard in that space.  Please select a new space, or enter 0 to exit";
    }
}

/// Prints out all the info for each ant type
void Game::printAntInfo() {
    cout << "Enter the NUMBER for the type of ant you'd like: \nNum\tType\t\tCost\tArmor\tDescription" << endl;
    cout << "1:\tHarvester\t2\t1\tAdds 1 food to colony each turn." << endl;
    cout << "2:\tThrower\t\t4\t1\tDelivers 1 damage to bee in the same square." << endl;
    cout << "3:\tFire\t\t4\t1\tEliminates all bees in the same square upon dying." << endl;
    cout << "4:\tLong Thrower\t3\t1\tInflicts 1 damage on each bee which is closest, but at least 4 squares away." << endl;
    cout << "5:\tShort Thrower\t3\t1\tInflicts damage on each bee which is closest, but no more than 2 squares away." << endl;
    cout << "6:\tWall\t\t4\t4\tBlocks bees from advancing." << endl;
    cout << "7:\tNinja\t\t6\t1\tCannot block bees or be attacked. Delivers 1 damage to each bee it passes." << endl;
    cout << "8:\tBodyguard\t4\t2\tShares the space with other ants and takes all damage from bees. One per square." << endl;
}

/**
 * \brief Prints out the current state of the game board vertically
 */
void Game::printBoard() {
    cout << "******************\n" << "\tQ" << endl;

    for (int i = 0; i < 10; i++){
        cout << "\t" << i + 1 << endl;
        for (int j = 0; j < gameBoard[i].ants->size(); j++){
            cout << gameBoard[i].ants->at(j)->typeToString() << " ";
        }
        cout << endl;
        for (int j = 0; j < gameBoard[i].bees->size(); j++){
            cout << "Bee" << " ";
        }

        cout << "\n******************" << endl;
    }
}

/**
 * \brief checks to see if an ant can be placed on the board at all
 * @return true if there is an empty spot on the board
 */
bool Game::canPlaceAnt(){

    for (int i = 0; i < 10; i++){
        if ( this->gameBoard[i].ants->empty() || (this->gameBoard[i].ants->size() == 1 && this->gameBoard[i].bg)){
            return true;
        }
    }
    return false;
}

/**
 * \brief selects a type of ant based on user input
 * @param type the numberical representation of an ant type
 * @return a pointer to the type of Ant
 */
Ant* Game::selectAnt(int type) {
    Ant* newAnt;
    switch(type){
        case 1: newAnt = new Harvester();
            break;
        case 2: newAnt = new Thrower();
            break;
        case 3: newAnt = new Fire();
            break;
        case 4: newAnt = new LongThrower();
            break;
        case 5: newAnt = new ShortThrower();
            break;
        case 6: newAnt = new Wall();
            break;
        case 7: newAnt = new Ninja();
            break;
        case 8: newAnt = new Bodyguard();
            break;
    }
    return newAnt;
}

/**
 * \brief places an ant on the board
 * @param newAnt, and ant pointer to the new ant that will be placed
 */
void Game::placeAnt(Ant* newAnt){
    cout << "Enter the location on the board where you would like to place the ant" << endl;
    cout << "\t[Q 1|2|3|4|5|6|7|8|9|10]" << endl;

    while (true) {
        int loc = userInput(1, 10) - 1;

        if (gameBoard[loc].ants->empty() || (gameBoard[loc].ants->size() == 1 && gameBoard[loc].bg)) {
            if (newAnt->getType() == 7){
                gameBoard[loc].nj = true;
            }
            gameBoard[loc].ants->push_back(newAnt);
            Ant::removeFood(newAnt->getCost());
            break;
        }
        cout << "Space is occupied, please chose a different spot: " << endl;
    }
}

/**
 * \brief prompt user to enter y or n;
 * @return true if y, false if n;
 */
bool Game::inputYN(){
    cout << "Enter y/n: " << endl;
    while (true){
        string in;
        getline(cin, in);

        if(in == "y" || in == "Y"){
            return true;

        }else if(in == "n" || in == "N"){
            return false;
        }
        cout << "?? What was that? Please enter y or n. I believe in you." << endl;
    }
}


/**
 * \brief Gets user input for a range of numbers
 * @param lower, the lowest number accepted
 * @param upper, the greatest number accepted
 * @return a valid integer
 */
int Game::userInput(int lower, int upper) {

    while (true) {
        string input;
        getline(cin, input);

        try {
            int num = stod(input);
            if (num >= lower && num <= upper) {
                return num;
            }
        } catch (invalid_argument const &e) {
            cout << "Invalid entry, please try again: " << endl;
        }
    }
}

void Game::antAttack() {
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < gameBoard[i].ants->size(); j++){
           gameBoard[i].ants->at(j)->takeTurn(gameBoard, i);
        }
    }
}


/**
 * \brief Iterates through all Bees from left to right and either attacks or moves if there are no ants in the cell;
 */
void Game::beeAttack() {
    for (int i = 0; i < 10; i ++){
        for (int j = 0; j < gameBoard[i].bees->size(); j++){

            if (gameBoard[i].ants->empty() || (gameBoard[i].ants->size() == 1 && gameBoard[i].nj)) {
                Bee::moveBees(gameBoard, i, j);
                break;
            }

            gameBoard[i].bees->at(j)->takeTurn(gameBoard, i);

        }
    }
}



