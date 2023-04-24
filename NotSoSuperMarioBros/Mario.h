#ifndef MARIO_H
#define MARIO_H

#include <iostream>
#include <random>
#include <string>


class Mario{

private:
    int m_numLives;
    int m_numCoins;
    int m_defeated;
    int m_pLevel;
    int m_probKoopa;
    int m_probGoomba;
    int m_probBoss;
    int m_numMoves;

public:
    Mario();
    Mario(int numLives);
    ~Mario();
    //action functions
    void addWallet();
    void addLife();
    void rmLife();
    void addPLevel();
    void rmPLevel();
    bool fightKoopa();
    bool fightGoomba();
    bool fightBoss();
    void incMove();
    //helper functions
    int getWallet();
    int getLives();
    int getPLevel();
    void checkFight(bool result);
    int getMoves();

};

#endif