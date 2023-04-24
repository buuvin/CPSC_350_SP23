#ifndef OFFICE_H
#define OFFICE_H

#include "Window.h"
#include "Customer.h"
#include "LLQueue.h"

class Office{

private:
    LLQueue<Customer*>* m_customers;
    unsigned int m_numWindows;

    double m_meanWait;
    unsigned int m_numStudents;
    unsigned int m_longestWait;
    unsigned int m_numWait10;
    
    double m_meanIdle;
    unsigned int m_numIdle;
    unsigned int m_longestIdle;
    unsigned int m_numIdle5;


public:
    Office(int numWindows);
    ~Office();
    int getSize();
    bool isEmpty();
    Window* nextWindowToProcess();
    void changeTimeWindows(int timeC);
    void processWindow(int curTime, Window* windowP);
    void push(Customer* customerP);
    void collectWindows();
    void printOffice();
    void printQueue();
    void printStats(int ind);
    Window** m_windows;
};

#endif