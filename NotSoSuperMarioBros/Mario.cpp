#include "Mario.h"
using namespace std;

Mario::Mario(){
    m_numLives = 3;
    m_numCoins = 0;
    m_defeated = 0;
    m_pLevel = 0;
    m_probGoomba = 80;
    m_probKoopa = 65;
    m_probBoss = 50;
    m_numMoves = 0;

}
Mario::Mario(int numLives){
    m_numLives = numLives;
    m_numCoins = 0;
    m_defeated = 0;
    m_pLevel = 0;
    m_probGoomba = 80;
    m_probKoopa = 65;
    m_probBoss = 50;
    m_numMoves = 0;
}
Mario::~Mario(){
    delete this;
}
void Mario::addWallet(){
    m_numCoins = (m_numCoins + 1) % 30;
    if(m_numCoins == 0){ // if 
        this->addLife();
    }
}
void Mario::addLife(){
    m_numLives++;
}
void Mario::rmLife(){
    m_numLives--;
}
void Mario::addPLevel(){
    if(m_pLevel < 2) // max level is 2
        m_pLevel++;
}
void Mario::rmPLevel(){
    if(m_pLevel == 0)
        this->rmLife(); // if power level is 0, mario loses a life
    else m_pLevel--;
}
bool Mario::fightKoopa(){
    bool ifWin = false;
    int test = rand() % 100;
    ifWin = test <= m_probKoopa;

    checkFight(ifWin); //adds to defeated counter or loses level/life
    return ifWin;
}
bool Mario::fightGoomba(){
    bool ifWin = false;
    int test = (rand()/100) % 100;
    ifWin = test <= m_probKoopa;
    
    checkFight(ifWin); //adds to defeated counter or loses level/life
    return ifWin;
}
bool Mario::fightBoss(){
    bool ifWin = false;
    int test = (rand()/10000) % 100;
    ifWin = test <= m_probKoopa;

    checkFight(ifWin); //adds to defeated counter or loses level/life
    if(!ifWin && this->getLives() > 0) // fights the boss twice
        checkFight(ifWin);
    return ifWin;
}
void Mario::incMove(){
    m_numMoves++;
}
int Mario::getWallet(){
    return m_numCoins;
}
int Mario::getLives(){
    return m_numLives;
}
int Mario::getPLevel(){
    return m_pLevel;
}
void Mario::checkFight(bool result){
    if(result){
        m_defeated = (m_defeated + 1) % 7;
        if(m_defeated == 0){
            //cout << "Mario has gained an extra life through defeating enemies" << endl;
            this->addLife();
        }
    } else{
        this->rmPLevel();
        m_defeated = 0;
    }
}
int Mario::getMoves(){
    return m_numMoves;
}

