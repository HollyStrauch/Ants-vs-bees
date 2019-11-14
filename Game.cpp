//
// Created by Holly Strauch on 11/11/2019.
//

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


Game::Game(){
    gameBoard = initGameBoard();
}

Game::Cell* Game::initGameBoard(){
    Cell* gameBoard = new Cell[10];
    for (int i = 0; i < 10; i++){
        gameBoard[i].bg = false;
        gameBoard[i].nj = false;
        gameBoard[i].bees = new vector<Bee>;
        gameBoard[i].ants = new vector<Ant>;
    }

    return gameBoard;
}

void Game::runGame(){

    do {
        generateBee();
        cout << "Would you like to place a new ant? Current food: " << Ant::getFood() << endl;
        if (inputYN()) {
            generateAnt();
        }
    //    antAttack();
    //    beeAttack();
        printBoard();
    }while(Bee::getCount() != 0 && checkQueen());

}

bool Game::checkQueen() {
    if (this->gameBoard[0].bees->size() > 0){
        return false;
    }
    return true;
}

/**
 * \brief Creates a new Bee and adds it to the gameboard at Cell 9
 */
void Game::generateBee() {
    cout << "A NEW BEE HAS LEFT THE HIVE" << endl;
    Bee newBee = Bee();
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
            continue;
        }
        if (type == 8) {
            placeBG(ant);
        } else if (!canPlaceAnt()) {
            cout << "Board is full, cannot place ant" << endl;
            continue;
        }else {
            placeAnt(ant);
            return;
        }
    }
}

void Game::placeBG(Ant *bg) {
    cout << "Enter the position on the board you would like to place the bodyguard, or -1 to exit" << endl;
    while ( true ){
        int pos = userInput(-1, 9);
        if (pos == -1){
            break;
        }
        if (!gameBoard[pos].bg){
            gameBoard[pos].ants->push_back(*bg);
            gameBoard[pos].bg = true;
            Ant::removeFood(bg->getCost());
            break;
        }
        cout << "There is already a body guard in that space.  Please select a new space, or enter -1 to exit";
    }
}

void Game::printAntInfo() {
    cout << "Enter the number for the type of ant you'd like: \nNum\tType\t\tCost\tArmor\tDescription" << endl;
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
        for (int j = 0; j < gameBoard[i].ants->size(); j++){
            cout << gameBoard[i].ants->at(j).typeToString() << " ";
        }
        cout << "\n" << endl;
        for (int j = 0; j < gameBoard[i].bees->size(); j++){
            cout << "Bee" << " ";
        }

        cout << "\n******************" << endl;
    }
}

bool Game::canPlaceAnt(){

    for (int i = 0; i < 10; i++){
        if ( this->gameBoard[i].ants->empty() || (this->gameBoard[i].ants->size() == 1 && this->gameBoard[i].bg)){
            return true;
        }
    }
    return false;
}

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

void Game::placeAnt(Ant* newAnt){
    cout << "Enter the location on the board where you would like to place the ant" << endl;
    cout << "\t[1|2|3|4|5|6|7|8|9|10]" << endl;

    while (true) {
        int loc = userInput(1, 10) - 1;

        if (gameBoard[loc].ants->empty() || (gameBoard[loc].ants->size() == 1 && gameBoard[loc].bg)) {
            if (newAnt->getType() == 7){
                gameBoard[loc].nj = true;
            }
            gameBoard[loc].ants->push_back(*newAnt);
            Ant::removeFood(newAnt->getCost());
            break;
        }
        cout << "Space is occupied, please chose a different spot: " << endl;
    }
}

bool Game::checkForAnt() {
    return false;
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


//check for out of bound values
int Game::userInput(int lower, int upper) {

    while (true) {
        string input;
        getline(cin, input);

        try {
            int num = stod(input);
            if (num >= lower || num <= upper) {
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
            gameBoard[i].ants->at(j).takeTurn(gameBoard[i].bees);
        }
    }
    //todo attack left to right\
    //todo check for dead bees
}

/**
 * \brief finds the location of a bodyguard ant, returns 0 if none. Does not pose issue with indexing, bees will attack
 *  first space if no bodyguard exists.
 * @param currCell
 * @return
 */
int Game::findBG(int currCell) {
    for ( int i = 0; i < gameBoard[currCell].ants->size(); i++){
        if (gameBoard[i].ants->at(i).getType() == 8) {
            return i;
        }
    }
    return 0;
}

/**
 * \brief Iterates through all Bees from left to right and either attacks or moves if there are no ants in the cell;
 */
void Game::beeAttack() {
    for (int i = 0; i < 10; i ++){
        for (int j = 0; j < gameBoard[i].bees->size(); j++){
            if (gameBoard[i].ants->empty() || (gameBoard[i].ants->size() == 1 && gameBoard[i].nj)) {
                //todo check for ninja
                moveBees(i, j);
                break;
            }
            int bInd = findBG(i);

            gameBoard[i].ants->at(bInd).takeDamage(1);
            if (gameBoard[i].ants->at(bInd).getArmor() <= 0) {

                gameBoard[i].ants->erase(gameBoard[i].ants->begin() + bInd);
                //todo check for fire ant
            }
        }
    }
}

/**
 * \brief Method moves all bees from the startBee on in a cell to the next cell.  Bees receive damage if a ninja is was
 *  present
 * @param currCell, the cell the bees are moving from
 * @param startBee, the first bee in the current cell bee vector that is moving
 */
void Game::moveBees(int currCell, int startBee) {

    for (int i = gameBoard[currCell].bees->size(); i >= startBee; i--){
        gameBoard[currCell - 1].bees[i] = gameBoard[currCell].bees[i];

        if (gameBoard[currCell].nj){
            gameBoard[currCell - 1].bees->at(i).takeDamage(1);
        }
        gameBoard[currCell].bees->pop_back();
    }
}
