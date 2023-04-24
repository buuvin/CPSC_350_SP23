#include "SingleLinkedList.h"

int main(int argc, char **argv){
    SingleLinkedList* sll = new SingleLinkedList();
    sll->insertFront(4);
    sll->insertFront(34);
    sll->insertFront(45);

    sll->printList(true);
    //sll->removeFront();
    sll->printList(true);

    int pos = sll->find(34);
    sll->deleteAtPos(pos);
    cout << sll->find(45) << endl;
    
}