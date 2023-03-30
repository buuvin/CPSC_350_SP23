#ifndef MONOSTACK_H
#define MONOSTACK_H

#include<iostream>
#include<exception>
using namespace std;

template <class T>
class MonoStack{

public:
    MonoStack(int maxSize, char o){
        size = maxSize;
        array = new T[size];
        top = -1;
        m_o = o;
    }
    ~MonoStack() {
        cout << "garbage collection" << endl;
        delete[] array;
    }
    //~MonoStack();

    void push(T data){
        if(isFull())//check if stack is full
            throw runtime_error("stack is full");
        if(m_o == 'i'){ // if the stack is increasing, then get rid of data greater than value inputted
            while(!this->isEmpty() && this->peek() > data){
                this->pop();
            }
        }else if(m_o == 'd'){ // if the stack is decreasing, then get rid of data less than value inputted
            while(!this->isEmpty() && this->peek() < data){
                this->pop();
            }
        }
        array[++top] = data;
    }
    T pop() {
            if(isEmpty()) {
                throw std::runtime_error("Stack is empty, nothing to pop");
            }
            return array[top--];
        }

    T peek() {
        return array[top];
    }

    int getSize() {
        return top + 1;
    }

    bool isFull() {
        return getSize() == top;
    }

    bool isEmpty() {
        return top == -1;
    }
private:
    T *array;
    int size;
    int top;
    char m_o;
};


#endif