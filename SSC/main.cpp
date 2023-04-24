#include "LLQueue.h"
#include "ServiceCenter.h"
int main(int argc, char **argv){
    //LLQueue<Customer*> *dl1 = new LLQueue<Customer*>();

    // dl1->insert(4);
    // dl1->printList(false);
    // dl1->insert(34);
    // dl1->printList(false);
    // dl1->insert(45);
    // dl1->printList(false);
    // dl1->insert(33);
    // dl1->printList(false);

    // int pos = dl1->find(34);
    // cout << "position: " << pos << endl;
    // //dl1->removeNode(34);
    // cout << dl1->remove() << endl;

    // dl1->printList(false);

    // cout << dl1->remove() << endl;

    // dl1->printList(false);
    
    // cout << dl1->remove() << endl;

    // dl1->printList(false);

    // cout << "test" << endl;
    // cout << dl1->remove() << endl;

    // //cout << "test" << endl;
    // dl1->printList(false);
    // int* arr1 = new int[3];
    // arr1[0] = 10;
    // arr1[1] = 1;
    // arr1[2] = 2;
    // char* arr2 = new char[3];
    // arr2[0] = 'R';
    // arr2[1] = 'C';
    // arr2[2] = 'F';
    // Customer* cus1 = new Customer(arr1, arr2);
    // arr1[0] = 5;
    // arr1[1] = 6;
    // arr1[2] = 3;
    // arr2[0] = 'R';
    // arr2[1] = 'F';
    // arr2[2] = 'C';
    // Customer* cus2 = new Customer(arr1, arr2);
    // Office* office = new Office(1);
    // office->push(cus1);
    // office->printOffice();
    // office->push(cus2);
    // office->processWindow(10, office->m_windows[0]);
    // office->printOffice();

    ServiceCenter* service = new ServiceCenter();
    service->streamFile("input.txt");
    service->printResults();
}