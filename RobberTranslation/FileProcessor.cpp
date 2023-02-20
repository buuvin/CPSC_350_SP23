/** @author Bhuvan Balagar
 * @date 2/19/23
 * @file FileProcessor.cpp
 * @brief This class reads an input file and outputs the text and the text in robber lanauge into an html file
 * The class uses the Translator class to help convert the lines into robber language
 * The html file formats the text with the original text in bold and robber text in italics
*/


#include "FileProcessor.h"
#include "Translator.h"
#include <fstream>
#include <iostream>
using namespace std;

/** Default constructor */
FileProcessor::FileProcessor(){
   translator = new Translator();
}

/** Default destructor */
FileProcessor::~FileProcessor(){
    delete this;
    delete translator;
}

/**
 * reads the input file and converts the text into robber language
 * @param infName name of the input file
 * @param outfName name of the output  file
 */
void FileProcessor::processFile(string infName, string outfName){
    ifstream reader(infName);
    m_outfName = outfName;
    string nxtLine;
    if(reader.is_open()) {
        while(getline(reader, nxtLine)){
            originalString += "<p>" + nxtLine + "</p>";
            robbyString += "<p>" + translator->translateEnglishSentence(nxtLine) + "</p>";
        }
        reader.close();
    }else { 
        cout << "Unable to open file" << endl; 
    }
    writeToHTML();
}

/**
 * writes the original text and robber text into an html file
 */
void FileProcessor::writeToHTML(){
    ofstream writer(m_outfName);
    if(writer.is_open()){
        writer << "<!DOCTYPE html>" << endl;
        writer << "<html>" << endl;
        writer << "<body>" << endl;
        writer << "<b>\n" << originalString << "\n</b>\n"<< endl;
        writer << "<br>" << endl;
        writer << "<i>\n" << robbyString << "\n</i>\n"<< endl;
        writer << "</body>" << endl; 
        writer << "</html>" << endl;
    }
    writer.close();
}
