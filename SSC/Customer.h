#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer{

public:
    unsigned int m_timeInLine;
    unsigned int m_waitTime;
    bool m_ifWait10;
    bool m_isLast;
    unsigned int m_curNum;
    int m_curTime;

    Customer();
    Customer(int* inTimes, char* inOrder);
    ~Customer();

    int getCurTime();
    int getTimeAtOffice();
    int getCurOffice();
    char getNextOffice();
    int getTimeInLine();
    int getPlace();
    bool isLast();
    void decreaseCurTime(int timeDec);
    
    void setTimeInLine(int timeSet);
    void printStud();

private:
    int* m_officeTimes;
    char* m_officeOrder;
};

#endif