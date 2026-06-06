#include <iostream>
#include "StackNode.h"

using namespace std;


StackNode::StackNode() {
    this->data = 0;
    this->next = nullptr;
}

StackNode::StackNode(int data) {
    this->data = data;
    this->next = nullptr;
}


StackNode::~StackNode() {
    // No manual delete needed
}
int StackNode::get_data() const {
    return this->data;
}
StackNode* StackNode::get_next() const {
    return this->next;
}
void StackNode::set_next(StackNode* next) {
    this->next = next;
}   
