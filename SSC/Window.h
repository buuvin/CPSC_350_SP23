#ifndef WINDOW_H
#define WINDOW_H

#include "Customer.h"
class Window{

public:
    bool m_isIdle;
    bool m_idle5Min;
    Customer* curCustomer;

    Window();
    ~Window();

    void push(Customer* cusToTake);
    Customer* processStudent();
    Customer* peek();
    void incIdleTime(int timeInc);
    int getIdleTime();
    bool isEmpty();
    int getCurTime();
    int getOffice();
    int getWait();
    void changeTime(int timeC);
    void printWindow();

private:
    unsigned int m_idleTime;

};

#endif