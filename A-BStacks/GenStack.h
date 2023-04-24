#ifndef GENSTACK_H
#define GENSTACK_H

#include<iostream>
using namespace std;

template<class T> class GenStack{
    
public:
    GenStack();//default constructor
    GenStack(int maxSize);
    ~GenStack();//default destructor

    //core functions
    void push(T data);
    T pop();
    T peek(); // top()

    //aux functions
    int getSize();
    bool isEmpty();
    bool isFull();

private:
    T* myArray;
    int size;
    int top;
};

#endif