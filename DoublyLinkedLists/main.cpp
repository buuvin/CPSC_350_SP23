#include "DoubleLinkedList.h"

int main(int argc, char **argv){
    DoubleLinkedList<int> *dl1 = new DoubleLinkedList<int>();

    dl1->insertBack(4);
    dl1->insertFront(34);
    dl1->insertFront(45);
    dl1->insertBack(33);

    dl1->printList(false);

    int pos = dl1->find(34);
    cout << "position: " << pos << endl;
    //dl1->removeNode(34);
    cout << dl1->removeFront() << endl;

    dl1->printList(false);

    cout << dl1->removeBack() << endl;

    dl1->printList(false);
    
    cout << dl1->removeBack() << endl;

    dl1->printList(false);

    cout << dl1->removeBack() << endl;

   dl1->printList(false);
}