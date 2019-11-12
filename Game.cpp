//
// Created by Holly Strauch on 11/11/2019.
//

#include "Game.h"
#include "Harvester.h"
#include "Thrower.h"
#include "Fire.h"
#include "LongThrower.h"
#include "ShortThrower.h"
#include "Wall.h"
#include "Ninja.h"
#include "Bodyguard.h"


Game::Game(){
    beeCount = 0;
    food = 50;
    gameBoard = initGameBoard();
}

Game::Cell* Game::initGameBoard(){
    Cell* gameBoard = new Cell[10];
    for (int i = 0; i < 10; i++){
        gameBoard[i].bees = new vector<Bee*>;
        gameBoard[i].ants = new vector<Ant*>;
    }

    return gameBoard;
}

void Game::runGame(){

    do {
        generateBee();
        generateAnt();
        antAttack();
        beeAttack();
    }while(beeCount != 0 && checkQueen());

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
    Bee* newBee = new Bee();
    this->gameBoard[9].bees->push_back(newBee);
    beeCount++;
}

void Game::generateAnt() {
    cout << "Would you like to place a new ant? Current food: " << getFood() << endl;

    while (true){
        string in;
        getline(cin, in);

        if(in == "y" || in == "Y"){
            Ant* ant = createAnt();
            placeAnt(ant);
            return;

        }else if(in == "n" || in == "N"){
            return;
        }

        cout << "?? What was that? Please enter y or n. I believe in you." << endl;
    }
}

void Game::printAntInfo() {
    cout << "Enter the number for the type of ant you'd like: \nNum\tType\t\tCost\tArmor\tDescription" << endl;
    cout << "1:\tHarvester\t2\t1\tAdds 1 food to colony each turn" << endl;
    cout << "2:\tThrower\t\t4\t1\tDelivers 1 damage to bee in the same square" << endl;
    cout << "3:\tFire\t\t4\t1\tEliminates all bees in the same square upon dying" << endl;
    cout << "4:\tLong Thrower\t3\t1\tInflicts 1 damage on each bee which is closest to it but at least 4 squares away." << endl;
    cout << "5:\tShort Thrower\t3\t1\tInflicts damage on each bee which is closest to it but no more than 2 squares away" << endl;
    cout << "6:\tWall\t\t4\t4\tBlocks bees from advancing" << endl;
    cout << "7:\tNinja\t\t6\t1\tCannot block bees or be attacked. Delivers 1 damage to each bee it passes." << endl;
    cout << "8:\tBodyguard\t4\t2\tShares the space with other ants and takes all damage from bees. One per square." << endl;

}

Ant* Game::fullBoard() {
    cout << "Board is full. Bodyguard is the only available ant. Enter 1 to purchase or 0 to exit." << endl;

    int type = userInput(0, 1);

    if (type == 0) {
        return nullptr;
    }

    Ant *newAnt = new Bodyguard();
    if (newAnt->getCost() > this->food) {
        cout << "You cannot afford that ant. There are no more option to select from;" << endl;
        return nullptr;
    }

    this->food -= newAnt->getCost();
    return new Bodyguard();
}


/**
 *
 * @return
 */
Ant* Game::createAnt(){
    printAntInfo();

    if (!canPlaceAnt()){
        return fullBoard();
    }
    while(true) {
        int type = userInput(0, 8);

        if (type == 0) {
            return nullptr;
        }
        Ant *newAnt = selectAnt(type);
        if (newAnt->getCost() > this->food) {
            cout << "you cannot afford that ant. Please select again or enter 0 to exit" << endl;
            continue;
        }
        this->food -= newAnt->getCost();
        return newAnt;
    }
}

bool Game::canPlaceAnt(){

    for (int i = 0; i < 10; i++){
        if ( this->gameBoard[i].ants->size() == 0){
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

    int loc = userInput( 1, 10 );
    //Todo check if space is empty OR if bodyguard, check if any other bodyguards
    //TODO put ant on board
}

bool Game::checkForAnt() {

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
            cout << "Invalid entry, please try again" << endl;
        }
    }
}

void Game::antAttack() {
    //todo attack left to right\
    //todo check for dead bees
}

void Game::beeAttack() {
    //todo attack left to right
    //todo check if move or attack
}

int Game::getFood() const {
    return this->food;
}