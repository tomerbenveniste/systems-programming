#include <iostream>
#include "Stack.h"

using namespace std;

// Constructor
Stack::Stack() {
    this->top = nullptr; // empty Stack, the pointer points to NULL
}

// Destructor
Stack::~Stack() {
    // as long as the Stack has StackNodes, pop them out (the deletion happens in the pop method)
    while (!isEmpty()) {
        pop();
    }
}

// Pushes element to the stack method
void Stack::push(int element) {
    StackNode* new_node = new StackNode(element); // allocate memory for a new StackNode then construct it
    new_node->set_next(this->top); // the new node points to the old top
    this->top = new_node; // the new node becomes the top
}

// Pushes element from the stack method
void Stack::pop() {
    // if the stack is empty, nothing to pop
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    // there is an element to pop
    StackNode* temp = this->top; // define a temp pointer to not lose the element we want to delete after
    this->top = this->top->get_next(); // define new top as the next element in the stack
    delete temp; // delete the popped item from the memory (first destructor, then memory release)
}

// the method checks if the stack is empty
bool Stack::isEmpty() const {
    return this->top == nullptr;
}

// the method peeks to see what element is at the top of the stack, just reading the data.
int Stack::peek() const {
    if (isEmpty()) {
        return INT_MIN; // Return INT_MIN to indicate the stack is empty
    }
    return this->top->get_data();
}       

// the method prints the stack nodes from top to bottom
void Stack::print_stack() const {
    // check if empty
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    // the stack has elements
    StackNode* current = this->top; // a new pointer to the top of the stack
    while (current != nullptr) { // as long sa there are stack nodes, keep printing the data of the nodes
        cout << current->get_data() << " ";
        current = current->get_next();
    }
    cout << endl;
}