#include "Level.h"
#include <fstream>


Level::Level(){
}
Level::Level(string outFile, bool ifLast, int levelNum, int size, int pCoins, int pNothing, int pGoomba, int pKoopa, int pShrooms, Mario* mario){
    srand(time(NULL));
    m_outFile = outFile;
    m_levelNum = levelNum;
    m_size = size;
    m_grid = new char*[m_size];
    for(int i = 0; i < m_size; i++)
        m_grid[i] = new char[m_size];
    initializeGrid();

    //generates random coordinates for mario to hover over
    m_mario = mario;
    tie(m_marioR, m_marioC) = genRandCoords();
    placeItem(1, 'B');
    if(!ifLast) // makes sure the last level does not have a ward pipe
        placeItem(1, 'P');

    //determines amount of each object and places them for each thing
    m_pCoins = determineAmount(pCoins);
    placeItem(m_pCoins, 'c');

    m_pShrooms = determineAmount(pShrooms);
    placeItem(m_pShrooms, 's');

    m_pKoopa = determineAmount(pKoopa);
    placeItem(m_pKoopa, 'k');

    m_pGoomba = determineAmount(pGoomba);
    placeItem(m_pGoomba, 'g');

}
Level::~Level(){
    for(int i = 0; i < m_size; i++){
        delete m_grid[i];
    }
    delete m_grid;
    delete m_mario;
}

void Level::initializeGrid(){
    for(int i = 0; i < m_size; i++){
        for(int x = 0; x < m_size; x++){
            m_grid[i][x] = 'x';
        }
    }
}
void Level::printGrid(){
    ofstream writer(m_outFile, ios::app);
    // prints border of grid
    writer << "+ ";
    for(int i = 0; i < m_size; i++)
        writer << "- ";

    //prints contents of grid
    writer << "+" << endl;
    for(int i = 0; i < m_size; i++){
        writer << "| ";
        for(int x = 0; x < m_size; x++){
            if(i == m_marioR && x == m_marioC) // mario hovers over grid, only shown on the grid when printing
                writer << "H" << " ";
            else writer << m_grid[i][x] << " ";
        }
        writer << "|" << endl;
    }

    // prints border of grid
    writer << "+ "; 
    for(int i = 0; i < m_size; i++)
        writer << "- ";
    writer << "+ " << endl;

    writer.close();
}

int Level::determineAmount(int probability){
    return (probability / 100.0) * (pow(m_size, 2) - 1); // converts into decimal and multiplies by # of grid spaces to get actual value
}

void Level::placeItem(int amount, char item){
    for(int i = 0; i < amount; i++){
        int iRow = 0;
        int iColumn = 0;
        tie(iRow, iColumn) = genRandCoords(); // places object in random coordinates
        m_grid[iRow][iColumn] = item;
    }
}
tuple<int, int> Level::genRandCoords(){
    int rCoor = rand() % m_size; // initial random row coordinate generated
    int cCoor = rand() % m_size; // initial random column coordinate generated
    if(m_grid[rCoor][cCoor] != 'x' || (rCoor == m_marioR && cCoor == m_marioC)) // checks if random coordinate isn't empty
        while(m_grid[rCoor][cCoor] != 'x' || (rCoor == m_marioR && cCoor == m_marioC)){ // goes in a random direction until an empty spot is found
            tie(rCoor, cCoor) = genRandDirection(rCoor, cCoor);
        }
    return make_tuple(rCoor, cCoor);

}
tuple<int, int> Level::genRandDirection(int xCoor, int yCoor){
    int randX = xCoor;
    int randY = yCoor;

    if(rand() % 2 == 0) // determiens whether mario moves vertically or horizontally
        randX = (xCoor + (-1 + rand() % 3)) % m_size; // moves randomly up or down
    else 
        randY = (yCoor + (-1 + rand() % 3)) % m_size; // moves randomly right or left

    if(randX == -1) // case of mario wraps backwards
        randX = m_size + randX;
    if(randY == -1) // case of mario wraps backwards
        randY = m_size + randY;

    return make_tuple(randX, randY);
}
bool Level::play(){
    ofstream writer(m_outFile, ios::app);
    bool ifWin, ifPipe;
    int nextPosR, nextPosC;

    while(!ifWin && m_mario->getLives() != 0){
        m_mario->incMove();

        writer << "Current level: " << m_levelNum << endl;
        writer << "Mario's position: (" << m_marioR << ", " << m_marioC << ")" << endl;
        writer << "Mario's current power level: " << m_mario->getPLevel() << endl; 

        switch(m_grid[m_marioR][m_marioC]){ // checks marios move
            case 'x':
                writer << "The position is empty and Mario continues" << endl;
                break;
            case 'c':
                m_mario->addWallet();
                m_grid[m_marioR][m_marioC] = 'x';
                writer << "Mario has added a coin to his wallet" << endl;
                break;
            case 's':
                m_mario ->addPLevel();
                m_grid[m_marioR][m_marioC] = 'x';
                writer << "Mario has consumed a mushroom" << endl;
                break;
            case 'g':
                if(m_mario->fightGoomba()) {
                    writer << "Mario fought the goomba and won" << endl;
                    m_grid[m_marioR][m_marioC] = 'x';
                }
                else writer << "Mario fought the goomba and lost" << endl;
                break;
            case 'k':
                if(m_mario->fightKoopa()) {
                    m_grid[m_marioR][m_marioC] = 'x';
                    writer << "Mario fought the koopa and won" << endl;
                }
                else writer << "Mario fought the koopa and lost" << endl;
                break;
            case 'B':
                if(m_mario->fightBoss()) {
                    writer << "Mario fought the boss of the level and won!" << endl;
                    ifWin = true;
                }
                else if(m_mario->getLives() > 0 ){  // checks if mario has lost before fighting boss again
                    writer << "Mario fought the boss of the level and lost :(" << endl;
                    if(m_mario->fightBoss()){
                        ifWin = true;
                        writer << "Mario fought the boss again and won!" << endl;
                    }
                    else writer << "Mario fought the boss again and lost lmao" << endl;
                }
                else{
                    writer << "Mario fought the boss of the level and lost :(" << endl;
                }
                break;
            case 'P':
                ifPipe = true;
                writer << "Mario has entered the ward pipe" << endl;
                ifWin = true;
                break;
        }

        writer << "Lives: " << m_mario->getLives() << endl;
        writer << "Coins: " << m_mario->getWallet() << endl;
        //only prints marios next move if he will continue playing in the current level
        if(!ifPipe && !ifWin){
            writer << "Mario ";
            tie(nextPosR, nextPosC) = genRandDirection(m_marioR, m_marioC);

            if(nextPosR - m_marioR == 0){ // if mario moves horizontally
                if(nextPosC - m_marioC == 1 || nextPosC - m_marioC < -1)
                    writer << "moves right" << endl;
                else if(nextPosC - m_marioC == -1 || nextPosC - m_marioC > 1)
                    writer << "moves left" << endl;
                else
                    writer << "stays put" << endl;
            }
            else if(nextPosC -  m_marioC == 0){ // if mario moves vertically
                if(nextPosR - m_marioR == 1 || nextPosR - m_marioR < -1)
                    writer << "moves down" << endl;
                else if(nextPosR - m_marioR == -1 || nextPosR - m_marioR > 1)
                    writer << "moves up" << endl;
                else
                    writer << "stays put" << endl;
            }
        }
        this->printGrid();
        //updates marios position for next move
        m_marioR = nextPosR;
        m_marioC = nextPosC;
        writer << endl;
    }


    if(ifWin){
        writer << "Mario has completed the level" << endl;
    }
    else{
        writer << "Mario has run out of lives :(" << endl;
        return false;
    }

    writer.close();
    return true;
}

