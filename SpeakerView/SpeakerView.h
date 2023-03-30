#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include <iostream>
#include "MonoStack.cpp"
#include "Stack.cpp"

using namespace std;

class SpeakerView{

public:
  SpeakerView();
  SpeakerView(string inFile);
  ~SpeakerView();
  void readInput();
  void determineVisibilty();

private:
  string m_inFile;
  unsigned int m_numRows;
  unsigned int m_numCols;
  Stack<double>* input;
  MonoStack<double>* audience;



};
#endif