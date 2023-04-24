#ifndef WORLD_H
#define WORLD_H

#include "Level.h"

class World{

private:
    Mario* m_mario;
    Level** m_world;
    int m_numLevels;
    string m_inFile;
    string m_outFile;

    int m_numInputs;
    int* m_inputs;
    
public:
    World();
    World(string inFile, string outFile);
    ~World();
    void play();
    void initializeWorld();
    void readFile();


};

#endif
