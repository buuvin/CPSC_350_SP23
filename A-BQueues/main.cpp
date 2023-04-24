#include "GenQueue.h"
using namespace std;

int main(int argc, char** args[]){
    GenQueue* queue1 = new GenQueue(9);
    try{
        for(int i = 0; i < 8; i++){
            queue1->insert('r' + (i + 1));
            queue1->printArray();
        }

        queue1->printArray();
        cout << "PEEK: " << queue1->peek() << endl;
        cout << "POP: " << queue1->remove() << endl;
        cout << "PEEK: " << queue1->peek() << endl;

        while(!queue1->isEmpty()){
            cout << "POPPING: " << queue1->remove() << endl;
            queue1->printArray();
        }

        cout << "SIZE: " << queue1->getSize() << endl;
        cout << "POP: " << queue1->remove() << endl;
        queue1->printArray();
    }
    catch(runtime_error &excep){
        cout << excep.what() << endl;
    }

    delete queue1;

}