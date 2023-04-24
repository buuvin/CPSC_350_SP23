#ifndef SERVICECENTER_H
#define SERVICECENTER_H

#include <iostream>
#include <fstream>
#include "Office.h"


class ServiceCenter{

private:
    int m_timeStart;
    int m_timeNext;
    int m_simTime;
    int m_numRegistrar;
    int m_numCashier;
    int m_numFinancial;


    Office** m_offices;

public:
    ServiceCenter();
    ~ServiceCenter();

    void streamFile(string inFile);
    void simulateService();
    bool isEmpty();
    bool checkTime();
    void printResults();
    Customer* createCustomer(string inLine);
    Window* findNextWindow();
    void moveStudent(Customer* cusToProcess);
    void changeTime(int timeC);
};

#endif