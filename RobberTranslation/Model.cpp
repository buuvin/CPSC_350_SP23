#include <iostream>
#include "Model.h"
using namespace std;



Model::Model(){}
Model::~Model(){delete this;}

string Model::translateSingleConsonant(char cons){
    return "" + cons + "o" + cons;
}

string Model::translateStringVowel(char vow){
    return "" + vow; 
}
