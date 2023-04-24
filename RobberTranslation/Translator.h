/** @author Bhuvan Balagar
 * @date 2/19/23
 * @file Translator.h
 * @brief header file for Translator.cpp
*/

#ifndef TRANSLATOR_H
#define TRANSLATOR_H


#include "Model.h"
#include <iostream>
using namespace std;

class Translator{

private:
    /** Model object used to translate characters into robber language */
    Model* model;
public:
    /** Default constructor */
    Translator();
    /** Default destructor */
    ~Translator();

    /** translate word into robber language */
    string translateEnglishWord(string word);
    /** translate sentence into robber language */
    string translateEnglishSentence(string sentence);
};

#endif