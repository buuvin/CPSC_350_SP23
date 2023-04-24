#include "SingleLinkedList.h"

SingleLinkedList::SingleLinkedList(){
    front = NULL;
    back = NULL;
    size = 0;
}
SingleLinkedList::~SingleLinkedList(){

}

int SingleLinkedList::find(int value){
    int pos = -1;
    ListNode* curr = front;

    while(curr->data != value){
        ++pos;
        if(curr->data == value){
            break;
        }
        curr = curr->next;
    }

    if(curr == 0){
        pos = -1;
    }

    return pos;
}
void SingleLinkedList::insertFront(int d){
    ListNode* node = new ListNode(d);

    if(isEmpty()){
        back = node;
    }
    else{
        node->next = front;
    }
    front = node;
    size++;
}
void SingleLinkedList::insertBack(int d){
    ListNode* node = new ListNode(d);

    if(isEmpty()){
        front = node;
    }
    else{
        back->next = node;
    }
    back = node;
    size++;
}

int SingleLinkedList::removeFront(){
    if(isEmpty()) {
        cerr << "list is empty" << endl;
        return -1;
    }
    int temp = front->data;
    ListNode* ft = front;

    front = front->next;
    ft->next = NULL;
    delete ft;

    size--;
    return temp;
}
int SingleLinkedList::removeBack(){
    if(isEmpty()) {
        cerr << "list is empty" << endl;
        return -1;
    }
    int temp = back->data;
    ListNode* curr = new ListNode();
    ListNode* prev = new ListNode();

    while(curr->next != back)
    {
        prev = curr;
        curr = curr->next;
    }
    back = prev->next;
    curr->next = NULL;
    //delete bt;

    size--;
    return temp;
}
int SingleLinkedList::deleteAtPos(int pos){
    if(isEmpty()){
        return -1;
    }
    int idx = 0;
    ListNode *curr = new ListNode();
    ListNode *prev = new ListNode();

    while(idx != pos){
        prev = curr;
        curr = curr->next;
        idx++;
    }
    prev->next = curr->next;
    curr->next = NULL;
    int d = curr->data;
    delete curr;
    size--;

    return d;
}
bool SingleLinkedList:: isEmpty(){
    return size == 0;
}
void SingleLinkedList::printList(bool printLink){

}