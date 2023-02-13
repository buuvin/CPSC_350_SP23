#if !DEFINED 
    #define MODEL_H
#endif

#include <iostream>
using namespace std;

class Model{

public:
    Model();
    ~Model();

    string translateSingleConsonant(char cons);
    string translateStringVowel(char cons);
};