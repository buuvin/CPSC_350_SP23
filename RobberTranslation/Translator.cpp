/** @author Bhuvan Balagar
 * @date 2/19/23
 * @file Translator.cpp
 * @brief Class that can take in a word or sentence and translate it to robber language
 * This class uses Model.cpp to help translate words into robber language
*/

#include <iostream>
#include "Translator.h"
#include "Model.h"
using namespace std;

/** Default Constructor */
Translator::Translator(){
    model = new Model();
}
/** Default Destructor */
Translator::~Translator(){
    delete this;
}

/**
 * translates a word into robber language
 * @param word word that is being translated into robber language
 * @return string that represents the word in robber language
 */
string Translator::translateEnglishWord(string word){
    string newWord;

    for(int i = 0; i < word.length(); i++){
        char curChar = word.at(i);
        switch(curChar){
            case 'a':
            case 'e': 
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                newWord += model->translateStringVowel(curChar);
                break;
            default:
                newWord += model->translateSingleConsonant(curChar);
        break;
        }
    }
    return newWord;
}

/**
 * translates a sentence into robber language
 * @param sentence sentence that is being translated into robber language
 * @return string that represents the sentence in robber language
 */
string Translator::translateEnglishSentence(string sentence){
    string curWord = "";
    string newSentence = "";

    for(int i = 0; i < sentence.length(); i++){
        char curChar = sentence.at(i);

        if(curChar != ' ')
            curWord += string(1, curChar);
        else {
            newSentence += translateEnglishWord(curWord) + " ";
            curWord = "";
        }
    }
    newSentence += translateEnglishWord(curWord) + ".";
    return newSentence;
}
