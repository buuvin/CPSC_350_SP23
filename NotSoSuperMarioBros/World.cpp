#include "World.h"
#include <fstream>
using namespace std;


World::World(){
    m_numLevels = 5;
    m_world = new Level*[m_numLevels];
    m_numInputs = 8;
    m_inputs = new int[m_numInputs];
    m_inFile = "input.txt";
    
}
World::World(string inFile, string outFile){
    m_outFile = outFile;
    //resets file before writing new game
    ofstream writer(m_outFile);
    writer.close();

    m_inFile = inFile;
    m_outFile = outFile;
    m_numInputs = 8;
    m_inputs = new int[m_numInputs];
    readFile();
}
World::~World(){
    delete m_mario;
    for(int i = 0; i < m_numLevels; i++){
        delete m_world[i];
    }
    delete m_world;
    delete m_inputs;
}

void World::play(){
    ofstream writer(m_outFile, ios::app);
    for(int i = 0; i < m_numLevels; i++){
        Level* curLevel = m_world[i];
        if(curLevel->play()){
            if(i == m_numLevels - 1)
                writer << "Mario has beat Bowser and saved the princess." << " It took " << m_mario->getMoves() << " moves" << endl;
            else writer << "Mario has advanced to the next level." << endl;
        }
        else {
            writer << "Mario took a fat L and lost the game. What a loser" << " It took " << m_mario->getMoves() << " moves" << endl;
            break;
        }
        writer << endl;
    }
    writer.close();
}

void World::initializeWorld(){
    m_numLevels = m_inputs[0];
    m_world = new Level*[m_numLevels];
    m_mario = new Mario(m_inputs[2]);

    for(int i = 0; i < m_numLevels; i++){
        if(i == m_numLevels - 1)
            m_world[i] = new Level(m_outFile, true, i, m_inputs[1], m_inputs[3], m_inputs[4], m_inputs[5], m_inputs[6], m_inputs[7], m_mario);
        else   
            m_world[i] = new Level(m_outFile, false, i, m_inputs[1], m_inputs[3], m_inputs[4], m_inputs[5], m_inputs[6], m_inputs[7], m_mario);
    }
}

void World::readFile(){
    ifstream reader(m_inFile);
    string nxtLine = "";
    int i = 0;
    if(reader.is_open()){
        while(getline(reader, nxtLine)){
            m_inputs[i++] = stoi(nxtLine); // stoi converts each line into an integer
        }
        reader.close();
    }
    initializeWorld();
}