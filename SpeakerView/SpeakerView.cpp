#include "SpeakerView.h"
#include <fstream>

SpeakerView::SpeakerView(string inFile){
    m_inFile = inFile;
    ifstream reader(m_inFile);

    string inLine;
    getline(reader, inLine);
    while(inLine.find(" ") != -1){ //determine number of columns 
        m_numCols++;
        inLine = inLine.substr(inLine.find(" ") + 1);
    }
    m_numCols++;
    while(getline(reader, inLine)){ //determind number of rows
        m_numRows++;
    }
    m_numRows++; // account for row used to determine columns
    input = new Stack<double>(m_numCols * m_numRows);// create input stack to take in input

    reader.clear();
    reader.seekg (0, ios::beg); // start from beginning of file to read in all values
    for(int i = 0; i < m_numCols; i++){
        while(getline(reader, inLine)){ // go through file column by column 
            for(int j = 0; j < i; j++){
                inLine = inLine.substr(inLine.find(" ") + 1); // starts line at value to be pushed onto stack
            }
            inLine = inLine.substr(0, inLine.find(" ")); // ends line at end of value to be pushed onto stack
            input->push(stod(inLine)); // pushes value onto stack
        }
        reader.clear();
        reader.seekg (0, ios::beg); // start at beginning of file to go through the next column
    }
    audience = new MonoStack<double>(m_numRows * m_numCols, 'd'); // create monotonic stack

}

void SpeakerView::determineVisibilty(){

    string output = "";
    for(int i = m_numCols - 1; i >= 0; --i){
        for(int j = 0; j < m_numRows; ++j){ // push each column onto stack separately
            audience->push(input->pop());
        }
        string outLine = "";
        outLine = "In column " + to_string(i) + " there are " + to_string(audience->getSize()) + " that can see. Their heights are: ";
        while(!audience->isEmpty()){ // pop out values of monotonic stack into string output
            string numToPush;
            if(audience->getSize() == 1){ // checks if last element for proper formatting
                numToPush = to_string(audience->pop());
                outLine += numToPush.erase(numToPush.find_last_not_of("0") + 1) + " inches.";   // gets rid of trailing zeros with erase and find_last_not_of methods 
            }else {
                numToPush = to_string(audience->pop());
                outLine += numToPush.erase(numToPush.find_last_not_of("0") + 1) + ", ";
            }
        }
        outLine += "\n"; // separates each line for output formatting
        output.insert(0, outLine); // since stack is backwards, each line is pushed at the start of the string
    }

    cout << output << endl;
}