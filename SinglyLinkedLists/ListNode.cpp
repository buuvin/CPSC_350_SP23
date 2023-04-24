#include "ListNode.h"

ListNode::ListNode(){}
ListNode::ListNode(int d){
    data = d;
    next = NULL;
}
ListNode::~ListNode(){
    //build some character
    //research this
    delete next;
}

