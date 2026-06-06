#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack() {
    this->top = nullptr;
}
Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}
void Stack::push(int element) {
    StackNode* new_node = new StackNode(element);
    new_node->set_next(this->top);
    this->top = new_node;
}
void Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }   
    StackNode* temp = this->top;
    this->top = this->top->get_next();
    delete temp;
}
bool Stack::isEmpty() const {
    return this->top == nullptr;
}
int Stack::peek() const {
    if (isEmpty()) {
        return -1; // Return -1 to indicate the stack is empty
    }
    return this->top->get_data();
}       

void Stack::print_stack() const {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    StackNode* current = this->top;
    while (current != nullptr) {
        cout << current->get_data() << " ";
        current = current->get_next();
    }
    cout << endl;
}