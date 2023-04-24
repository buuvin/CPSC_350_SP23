/** @author Bhuvan Balagar
 * @date 2/19/23
 * @file FileProcessor.h
 * @brief header file for FileProcessor.cpp
*/

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H


#include <iostream>
#include "Translator.h"
using namespace std;

class FileProcessor{

public:
    /** Default constructor */
    FileProcessor();
    /** Default destructor */
    ~FileProcessor();

    /** reads the input file and stores the original text and the text in robber language */
    void processFile(string infName, string outfName);
    /** creates the html file with the original text in bold and robber text in italics */
    void writeToHTML();
private:
    /** translator class used to convert each line into robber language */
    Translator* translator;
    /** string where robber text is stored */
    string robbyString;
    /** string where original input text is stored */
    string originalString;
    /** string that stores the name of the output file */
    string m_outfName;

};

#endif