/* Assignment C++: 1
Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
   */

#include <iostream>
#include "StackNode.h"

using namespace std;

// Default Constructor - called when the user writes StackNode node;
StackNode::StackNode() {
    this->data = 0;
    this->next = nullptr; //pointer to NULL
}

// Parameterized Constructor - called when the user writes StackNode node(5);
StackNode::StackNode(int data) {
    this->data = data;
    this->next = nullptr; //pointer to NULL
}

// Destructor
StackNode::~StackNode() {
    // No manual delete needed
}

// It reads the data field, const makes sure the user can't change this field
int StackNode::get_data() const {
    return this->data;
}

// It reads the next field, const makes sure the user can't change this field
StackNode* StackNode::get_next() const {
    return this->next;
}

// It modifies the object, setting the next field to be the input value (no const here)
void StackNode::set_next(StackNode* next) {
    this->next = next;
}   
