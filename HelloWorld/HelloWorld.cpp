#include <iostream>
#include "HelloWorld.h"
using namespace std;


HelloWorld::HelloWorld(){}
HelloWorld::~HelloWorld(){ delete this; }

void HelloWorld::printHelloWorld(){ cout << "Hello World!" << endl; }

int main(){
    HelloWorld* myObj = new HelloWorld();
    myObj->printHelloWorld();
}
