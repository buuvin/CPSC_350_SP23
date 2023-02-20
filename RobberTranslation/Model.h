/** @author Bhuvan Balagar
 * @date 2/19/23
 * @file Model.h
 * @brief header class for Model.cpp
*/

#ifndef MODEL_H
#define MODEL_H

#include <iostream>
using namespace std;

class Model{

public:
    /** Default Constructor */
    Model();
    /** Default Destructor */
    ~Model();
    
    /** method to translate consonants */
    string translateSingleConsonant(char cons);
    /** method to translate vowels */
    string translateStringVowel(char cons);
};

#endif