#include "MonoStack.h"


MonoStack::MonoStack(int maxSize, char o){
    size = maxSize;
    myArray = new int[size];
    top = -1;
    m_o = o;
}
// MonoStack::~MonoStack(){
//     delete myArray;
// }

void MonoStack::push(int data){
    if(isFull())//check if stack is full
        throw runtime_error("stack is full");
    if(m_o == 'i'){
        while(!this->isEmpty() && this->peek() > data){
            this->pop();
        }
    }else{
        while(!this->isEmpty() && this->peek() < data){
            this->pop();
        }
    }
    myArray[++top] = data;
}