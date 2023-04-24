#include "Office.h"

Office::Office(int numWindows){
    m_numWindows = numWindows;
    m_windows = new Window*[m_numWindows];
    for(int i = 0; i < m_numWindows; i++){
        m_windows[i] = new Window();
    }
    m_customers = new LLQueue<Customer*>();

    m_numStudents = 0;
    m_meanWait = 0.0;
    m_longestWait = 0;
    m_numWait10 = 0;
    m_meanIdle = 0.0;
    m_numIdle = 0;
    m_longestIdle = 0;
    m_numIdle5 = 0;
}

Office::~Office(){}

int Office::getSize(){ return m_numWindows; }

Window* Office::nextWindowToProcess(){
    Window* windowP = m_windows[0];
    for(int i = 1; i < m_numWindows; i++){ // loops through all windows
        if(!m_windows[i]->isEmpty()){ // checks if it is occupied
            if(windowP->isEmpty())
                windowP = m_windows[i];
            else if(m_windows[i]->getCurTime() < windowP->getCurTime()) // gets the window with the least time student has to spend at it
                windowP = m_windows[i];
        }
    }

    if(windowP->isEmpty())
        return NULL;
    return windowP;
}

void Office::changeTimeWindows(int timeC){ // changes time for all windows in office
    for(int i = 0; i < m_numWindows; i++){
        m_windows[i]->changeTime(timeC);
        
    }
}

void Office::processWindow(int curTime, Window* windowP){ //pops student off window passed in
    Customer* customerP = windowP->processStudent(); // pops student off window
    if(!m_customers->isEmpty()){ // gets next studetn in queue into windows
        windowP->push(m_customers->remove());
    }
    int curStudWait = curTime - (customerP->getTimeInLine() + customerP->getTimeAtOffice()); // calculates how long student waited in line
    m_numStudents++;

    if(curStudWait > 10) // calculates student stats for results
        m_numWait10++;
    if(curStudWait > m_longestWait)
        m_longestWait = curStudWait;
    m_meanWait += curStudWait;
    
}

void Office::collectWindows(){ // collects all stats of the windows in office at end of program
    for(int i = 0; i < m_numWindows; i++){
        Window* windowP = m_windows[i];
        int windowIdleTime = windowP->getIdleTime();
        if(windowIdleTime > 5)
            m_numIdle5++;
        if(windowIdleTime > m_longestIdle)
            m_longestIdle = windowIdleTime;
        m_meanIdle += windowIdleTime;
    }
}
void Office::push(Customer* customerP){ // pushes a student into next available window or queue
    for(int i = 0; i < m_numWindows; i++){
        Window* curWindow = m_windows[i];
        if(curWindow->isEmpty()){
            curWindow->push(customerP);
            return;
        }
    }
    
    m_customers->insert(customerP);
}


bool Office::isEmpty(){
    for(int i = 0; i < m_numWindows; i++){
        if(!m_windows[i]->isEmpty()){
            return false;
        }
    }
    return true;
}

void Office::printOffice(){ // helper method
    for(int i = 0; i < m_numWindows; i++){
        cout << "window " << i << ":" << endl;
        m_windows[i]->printWindow();
    }
    cout << endl;
}

void Office::printQueue(){ // helper method
    m_customers->printList(false);
}

void Office::printStats(int ind){ // prints statistics of office
    string off;
    if(ind == 0) off = "Registrar";
    else if(ind == 1) off = "Cashier";
    else off = "Financial";
    if(m_numStudents == 0)
        m_meanWait = 0;
    else
        m_meanWait /= m_numStudents;
    m_meanIdle /= m_numWindows;
    cout << "The mean wait time for the " << off << " office is: " << m_meanWait << endl;
    cout << "The longest student wait time for the " << off << " office is: " << m_longestWait << endl;
    cout << "The number of students waiting over 10 minutes is: " << m_numWait10 << endl;
    cout << endl;
    cout << "The mean idle time for the " << off << " office is: " << m_meanIdle << endl;
    cout << "The longest idle time for the " << off << " office is: " << m_longestIdle << endl;
    cout << "The number of windows waiting over 5 minutes is: " << m_numIdle5 << endl;
    cout << endl << endl;
}