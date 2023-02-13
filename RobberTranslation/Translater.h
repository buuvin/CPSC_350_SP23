#if !DEFINED 
    #define TRANSLATER_H
#endif

#include <iostream>
using namespace std;

class Translater{

public:
    Translater();
    ~Translater();

    string translateEnglishWord(string word);
    string translateEnglishSentence(string sentence);
};