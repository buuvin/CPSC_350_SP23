#include "ServiceCenter.h"
#include <climits>
using namespace std;


ServiceCenter::ServiceCenter(){
    m_offices = new Office*[3];

}
ServiceCenter::~ServiceCenter() {}


void ServiceCenter::streamFile(string inFile){ // streams in file constantly until nothing left to read
    ifstream reader(inFile);
    string inLine = "";

    for(int i = 0; i < 3; i++){
        getline(reader, inLine);
        m_offices[i] = new Office(stoi(inLine)); // creates offices
    }
   
    m_numRegistrar = m_offices[0]->getSize();
    m_numCashier = m_offices[1]->getSize();
    m_numFinancial = m_offices[2]->getSize();
    m_simTime = 1;
    m_timeNext = INT_MAX;

    getline(reader, inLine);
    int m_timeStart = stoi(inLine); // gets start time
    if(m_timeNext != INT_MAX)
        m_timeStart = m_timeNext;
    while(getline(reader, inLine)){
        int numStuds = stoi(inLine); // gets number of students to eb inputed
        for(int i = 0; i < numStuds; i++){ // creates students and pushes them into correct offices
            getline(reader, inLine);
            Customer* cusToAdd = createCustomer(inLine);
            cusToAdd->setTimeInLine(m_simTime);
            m_offices[cusToAdd->getCurOffice()]->push(cusToAdd);
        }
        if(getline(reader, inLine)) // gets the next time for students to be pushed
                m_timeNext = stoi(inLine);
            else
                m_timeNext = INT_MAX;
        simulateService(); // starts  simulation
    }
}

void ServiceCenter::simulateService(){
    while(checkTime() && !isEmpty()){ // checks if simulation should keep going or pause/stop
        Window* nextWindow = findNextWindow(); // gets next window to be processed

        Office* curOffice = m_offices[nextWindow->getOffice()];
       
        Customer* custoProcess = nextWindow->peek();
        int cusTime = custoProcess->getCurTime();
        if(cusTime + m_simTime >= m_timeNext){ // if reaches next time, simulation skips to that time then pauses to input next students
            changeTime(m_timeNext - 1 - m_simTime);
            m_simTime += (m_timeNext - 1 - m_simTime);
            break;
        }
        changeTime(cusTime);  // changes time at all offices
        m_simTime += cusTime; // changes simulation time
        curOffice->processWindow(m_simTime, nextWindow); // processes window
        
        moveStudent(custoProcess); // moves student into next office
    }
}

Customer* ServiceCenter::createCustomer(string inLine){ // creates new studetn with string input from file
    int* inTimes = new int[3];
    char* inOrder = new char[3];

    for(int i = 0; i < 3; i++){
        int ind = inLine.find(" ");
        inTimes[i] = stoi(inLine.substr(0, ind));
        inLine = inLine.substr(ind + 1);
    }

    for(int i = 0; i < 3; i++){
        int ind = inLine.find(" ");
        inOrder[i] = inLine.substr(0, ind)[0];
        inLine = inLine.substr(ind + 1);
    }

    return new Customer(inTimes, inOrder);
}

Window* ServiceCenter::findNextWindow(){ // finds the next window to be processed
    Office* curOffice = m_offices[0];
    Window* minWin = curOffice->nextWindowToProcess();
    Window* curWin;
    for(int i = 1; i < 3; i++){ // goes through each office 
        curWin = m_offices[i]->nextWindowToProcess(); // finds next window to be processed at each office
        if(curWin != NULL){
            if(minWin == NULL)
                minWin = curWin;
            //compares each window to be processed for each office to see which one should be processed first
            else if(curWin->getCurTime() < minWin->getCurTime() || curWin->getCurTime() == minWin->getCurTime() && curWin->getWait() < minWin->getWait())
                minWin = curWin;
        }
    }
    return minWin;
}

void ServiceCenter::moveStudent(Customer* custoProcess){
    int order;
    if(!custoProcess->isLast()){ // if student is done w all offices, delete student
        custoProcess->setTimeInLine(m_simTime);
        do{// if next office has 0 ticks, then student will move on until it gets to an office it spends time at
            order = custoProcess->getNextOffice();
        }while(custoProcess->getTimeAtOffice() == 0);
        
        if(custoProcess->getPlace() <= 2)// checks while loop above in case student doesnt have anymore offices to visit
            m_offices[order]->push(custoProcess);
        else delete custoProcess;
    }
    else
        delete custoProcess;
}

void ServiceCenter::changeTime(int timeC){ // change time at each office
    for(int i = 0; i < 3; i++){
        m_offices[i]->changeTimeWindows(timeC);
        
    }
}
bool ServiceCenter::isEmpty(){
    for(int i = 0; i < 3; i++){
        if(!m_offices[i]->isEmpty())
            return false;
    }
    return true;
}

bool ServiceCenter::checkTime(){// checks if simulation should pause for next students to be read in
    if(m_timeNext == -1)
        return true;
    if(m_timeNext <= m_simTime)
        return false;

    return true;
}

void ServiceCenter::printResults(){ // prints results at end of program
    for(int i = 0; i < 3; i++){
        string off;
        if(i == 0) off = "Registrar";
        else if(i == 1) off = "Cashier";
        else off = "Financial";
        cout << "Statistics for the " << off << " office:" << endl;
        m_offices[i]->collectWindows();
        m_offices[i]->printStats(i);
    }
}