/** @author Bhuvan Balagar
 * @date 2/19/23
 * @file main.cpp
 * @brief This class runs the program
*/

#include "FileProcessor.h"
#include <iostream>
using namespace std;


int main(){
    string inputfName = "input.txt";
    string outputfName = "output.html";
    FileProcessor* myObj = new FileProcessor();
    myObj->processFile(inputfName, outputfName);

    // Model* myModel = new Model();
    // cout << myModel->translateSingleConsonant('t') << endl;
    // cout << myModel->translateStringVowel('o') << endl;

    // Translator* translator = new Translator();
    // cout << translator->translateEnglishWord("tengen") << endl;
    // cout << translator->translateEnglishSentence("tengen uzui is my daddy") << endl;

}