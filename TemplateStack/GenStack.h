// #ifndef GENSTACK_H
// #define GENSTACK_H

#include<iostream>
#include <exception>
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

template <class T>
GenStack<T>::GenStack(){
    size = 64;
    top = -1;
    myArray = new T[size];
}

template <class T>
GenStack<T>::GenStack(int maxSize){
    size = maxSize;
    top = -1;
    myArray = new T[size];
}

template <class T>
GenStack<T>::~GenStack(){
    cout << "garbage time" << endl;
    delete myArray;
}

template <class T>
void GenStack<T>::push(T data){
    if(isFull())//check if stack is full
        throw runtime_error("stack is full");
    myArray[++top] = data;
}

template <class T>
T GenStack<T>::pop(){
    if(isEmpty())//check if stack is empty
        throw runtime_error("stack is empty");
    return myArray[top--];// dont remove value in A-B stack
}

template <class T>
T GenStack<T>::peek(){ return myArray[top]; }

template <class T>
bool GenStack<T>::isFull(){ return top == size - 1; }
template <class T>
bool GenStack<T>::isEmpty(){ return top == -1; }
template <class T>
int GenStack<T>::getSize(){ return size; }


//#endif