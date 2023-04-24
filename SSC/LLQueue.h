#ifndef LLQUEUE_H
#define LLQUEUE_H

#include "DoubleLinkedList.h"

template <class T>
class LLQueue : public DoubleLinkedList<T>{

public:
    LLQueue();
    ~LLQueue();

    void insert(T d);
    T remove();

    T peek();
};

template <class T>
LLQueue<T>::LLQueue(){
    this->front = NULL;
    this->back = NULL;
    this->size = 0;
}

template <class T>
LLQueue<T>::~LLQueue(){
    
}

template <class T>
void LLQueue<T>::insert(T d){
    this->insertBack(d);
}

template <class T>
T LLQueue<T>::remove(){
    return this->removeFront();
}

template <class T>
T LLQueue<T>::peek(){
    return this->front->data;
}

#endif