#ifndef STACK_H
#define STACK_H

#include<iostream>
#include<exception>
using namespace std;

template<class T>
class Stack{
    
public:
    Stack() {//default constructor
        size = 64;
        top = -1;
        myArray = new int[size];
    }
    Stack(int maxSize){
        size = maxSize;
        top = -1;
        myArray = new T[size];
    }
    ~Stack(){//default destructor
        delete myArray;
    }

    //core functions
    void push(T data){
        if(isFull())//check if stack is full
            throw runtime_error("stack is full");
        myArray[++top] = data;
    }
    T pop(){
        if(isEmpty())//check if stack is empty
            throw runtime_error("stack is empty");
        return myArray[top--];// dont remove value in A-B stack
    }
    T peek(){ return myArray[top]; }

    //aux functions
    bool isFull(){ return top == size - 1; }

    bool isEmpty(){ return top == -1; }

    int getSize(){ return (top + 1); }

private:
    T* myArray;
    int size;
    int top;
};

#endif