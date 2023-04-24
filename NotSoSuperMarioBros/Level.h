#ifndef LEVEL_H
#define LEVEL_H

#include <tuple>
#include "Mario.h"
using namespace std;

class Level{

private:
    char** m_grid;
    Mario* m_mario;
    string m_outFile;
    
    int m_size, m_levelNum, m_pCoins, m_pNothing, m_pShrooms, m_pKoopa, m_pGoomba, m_marioR, m_marioC;

public:
    Level();
    Level(string outFile, bool ifLast, int levelNum, int size, int pCoins, int pNothing, int pGoomba, int pKoopa, int pShrooms, Mario* mario);
    ~Level();

    //functions to set up Level
    void initializeGrid();
    void placeItem(int amount, char item); // places amount of item on grid
    int determineAmount(int probability);//converts percentage into actual value depending on grid size
    //core functions for playing level
    bool play();
    void printGrid();
    tuple<int, int> genRandCoords();
    tuple<int, int> genRandDirection(int xCoor, int yCoor); // takes in two coordinates and returns coordinates 1 space in random direciton
};

#endif