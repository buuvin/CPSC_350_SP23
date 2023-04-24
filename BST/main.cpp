#include "bst.h"

int main(int argc, char **argv){
    BST<int>* bst1 = new BST<int>();

    bst1->insert(10);
    bst1->insert(12);
    bst1->insert(20);
    bst1->insert(5);
    bst1->insert(9);
    bst1->insert(7);
    bst1->insert(13);
    bst1->insert(17);

    bst1->printTree();


}