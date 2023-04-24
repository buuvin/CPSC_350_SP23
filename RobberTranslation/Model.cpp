/** @author Bhuvan Balagar
 * @date 2/19/23
 * @file Model.cpp
 * @brief Class that translates a character into robber language. 
 * Consonants are translated to the consonant, then the character o, then the consonant again
 * Vowels are unchanged
*/
#include <iostream>
#include "Model.h"
using namespace std;


/** Default Constructor */
Model::Model(){}
/** Default Destructor */
Model::~Model(){
    delete this;
}

/**
 * translates a consonant into robber language
 * @param cons consonant that is being translated
 * @return string that represents the robber translation of the consonant
 */
string Model::translateSingleConsonant(char cons){
    if(isupper(cons))
        return string(1, cons) + "O" + string(1, cons);
    return string(1, cons) + "o" + string(1, cons);
}

/**
 * translates a vowel into robber language
 * @param vow vowel that is being translated
 * @return string that represents the robber translation of the vowel
 */
string Model::translateStringVowel(char vow){
    return string(1, vow);
}
