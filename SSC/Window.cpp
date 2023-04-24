#include <iostream>
#include "Window.h"

using namespace std;

Window::Window(){
    m_idleTime = 0;
    m_isIdle = true;
    m_idle5Min = false;
    curCustomer = NULL;
}

Window::~Window(){
    delete curCustomer;
}

void Window::push(Customer* cusToTake){ // places a student at the window
    curCustomer = cusToTake;
    m_isIdle = false;
}

Customer* Window::processStudent(){ // takes student out of window and returns it
    Customer* temp = curCustomer;
    curCustomer = NULL;
    m_isIdle = true;

    return temp;
}

Customer* Window::peek(){return curCustomer; }

int Window::getCurTime(){ // gets current time student needs to spend at window
    // if(curCustomer == NULL)
    //     return -1;
    return curCustomer->getCurTime();
}

int Window::getOffice(){ return curCustomer->getCurOffice(); }

int Window::getIdleTime(){ //gets how much idle time window spent throughout simulation
    int temp = m_idleTime;
    m_idleTime = 0;
    return temp;
}
int Window::getWait(){ // helper method to calculate wait time of student in queue
    return curCustomer->getTimeInLine();
}

void Window::changeTime(int timeC){ // decerases student time at window or increases idle time
    if(m_isIdle)
        m_idleTime += timeC;
    else{
        curCustomer->decreaseCurTime(timeC);
    }
}

bool Window::isEmpty(){ return m_isIdle; }

void Window::printWindow(){ // helper method
    if(m_isIdle)
        cout << "idle" << endl;
    else {  
        cout << "occupied" << endl;
        curCustomer->printStud();
    }
}