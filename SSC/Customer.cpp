#include "Customer.h"

#include <iostream>
using namespace std;

Customer::Customer(int* inTimes, char* inOrder){
    m_officeOrder = new char[3];
    m_officeTimes = new int[3];
    for(int i = 0; i < 3; i++){
        m_officeTimes[i] = inTimes[i];
        m_officeOrder[i] = inOrder[i];
    }

    m_waitTime = 0;
    m_timeInLine = 0;
    m_ifWait10 = false;
    m_curNum = 0;
    m_curTime = m_officeTimes[0];
    m_isLast = false;
}

Customer::~Customer(){
    delete []m_officeOrder;
    delete []m_officeTimes;
}

int Customer::getCurTime() { return m_curTime; } // gets current time at window
int Customer::getTimeAtOffice() {return m_officeTimes[m_curNum]; }
int Customer::getPlace() { return m_curNum; } // gets how many offices its visited

int Customer::getCurOffice() {
    if(m_officeOrder[m_curNum] == 'R') 
        return 0;
    else if(m_officeOrder[m_curNum] == 'C')  
        return 1;
    else   
        return 2; 
}

void Customer::decreaseCurTime(int timeDec) { m_curTime -= timeDec; }

int Customer::getTimeInLine(){ return m_timeInLine; }

void Customer::setTimeInLine(int timeSet){ m_timeInLine = timeSet; }

bool Customer::isLast(){ return m_isLast; } // checks if customer is at last office


char Customer::getNextOffice(){ // gets the next office of student 
    m_curNum++;
    if(m_curNum == 2)
        m_isLast = true;
    m_curTime = m_officeTimes[m_curNum];

    return this->getCurOffice();
}

void Customer::printStud(){ // helper method
    cout << "time in line: " << m_timeInLine << endl;
    cout << "current window: " << m_curNum << endl;
    cout << "time at window: " << m_curTime << endl;

    for(int i = 0; i < 3; i++){
        cout << (i + 1) << ": " << m_officeOrder[i] << ", " << m_officeTimes[i] << endl;
    }
}
