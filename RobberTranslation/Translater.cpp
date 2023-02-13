#include <iostream>
#include "Translater.h"
#include "Model.h"
using namespace std;

Translater::Translater(){}
Translater::~Translater(){delete this}

string Translater::translateEnglishWord(string word){
    string newWord;
    for(int i = 0; i < word.length(); i++){
        char curChar = newWord.at(i);
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
                newWord += "A";
                newWord += translateStringVowel(curChar);
                break;
            default:
                newWord += translateSingleConstant(curChar);
        break;
        }
    }
}

string Translater::translateEnglishSentence(string sentence){
    string newSentence = "";
    for(int i = 0; i < sentence.length(); i++){
         string curWord = sentence.substr(0,sentence.indexOf(" "));
    }
}
