#include "World.h"
using namespace std;

int main(int argc, char** argv){
    World* myWorld = new World(argv[1], argv[2]);
    myWorld->play();


}