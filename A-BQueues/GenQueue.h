#ifndef GENQUEUE_H
#define GENEQUEUE_H
#include<iostream>
#include<exception>

class GenQueue{

public:
    GenQueue();
    GenQueue(int maxSize);
    ~GenQueue();

    //core functions
    void insert(char data);
    void enqueue(char data);
    char remove();

    //aux functions
    char peek();
    bool isFull();
    bool isEmpty();
    unsigned int getSize(); // never going to be negative
    void printArray(); // helper function to visualize queue

    
private:
    int mSize;
    int front;
    int rear;
    unsigned int numElements;// number of elements cant be negative
    char *myQueue;
};

#endif