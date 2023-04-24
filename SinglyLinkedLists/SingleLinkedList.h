#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include "ListNode.h"

class SingleLinkedList{

private:
    ListNode* front;//head of list
    ListNode* back; // tail of list
    unsigned int size;
public:
    SingleLinkedList();
    ~SingleLinkedList();

    void insertFront(int d);
    void insertBack(int d);
    int removeFront();
    int removeBack();
    int find(int value);
    int deleteAtPos(int pos);
    bool isEmpty();
    unsigned int getSize();
    void printList(bool printLink);

};
#endif