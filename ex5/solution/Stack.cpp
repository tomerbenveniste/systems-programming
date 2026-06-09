/* Assignment C++: 1
Author: Tomer Benveniste, ID: 207961954 / Carmi Friedman, ID: 206463846
   */

#include <iostream>
#include "Stack.h"

using namespace std;

// Constructor
Stack::Stack() {
    this->top = nullptr; // empty Stack, the pointer points to NULL
}

// helper method - deep copies all nodes from other into this stack in correct order
void Stack::copy_from(const Stack& other) {

    Stack temp; // a temp stack to reverse the push order caused by pushing the original Stacks
    StackNode* ptr = other.top; // pointer to the top of the second stack

    // as long as the other stack has elements, keep pushing to temp
    while (ptr != nullptr) {
        temp.push(ptr->get_data()); // push element from other to temp
        ptr = ptr->get_next();
    }
    ptr = temp.top; // pointer to the top of the temp stack
    // as long as the temp stack has elements, keep pushing to this stack
    while (ptr != nullptr) {
        this->push(ptr->get_data()); // push element from temp to this stack
        ptr = ptr->get_next();
    }
}

// copy constructor - deep copies all nodes from other into this stack
Stack::Stack(const Stack& other) : top(nullptr) {
    copy_from(other); // using the helper to deep copy
}

// assignment operator - clears this stack then deep copies other into it
Stack& Stack::operator=(const Stack& other) {
    // guard against self-assignment (s = s)
    if (this == &other) {
        return *this;
    }
    // clear current nodes
    while (!isEmpty()) {
        pop();
    }
    // using the helper to deep copy
    copy_from(other);
    return *this;
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
    cout << "Removing " << temp->get_data() << endl; // print the popped element
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

// operator that pushes an integer to the stack
Stack& Stack::operator+=(int value) {
    this->push(value);
    return *this;
}

// operator that compares 2 stacks and return TRUE if they contain the same elements in the same order, FALSE otherwise
bool Stack::operator==(const Stack& other) const {

    StackNode* first = this->top; // pointer to the first stack
    StackNode* second = other.top; // pointer to the second stack

    // as long as both pointers are pointing on elements, keep comparing
    while (first != nullptr && second != nullptr) {
        if (first->get_data() != second->get_data()) {
            return false;
        }
        // approaching ahead in the stack
        first = first->get_next();
        second = second->get_next();
    }

    // if sizes of stacks are not the same, it will return false, otherwise all elements equal and will return true
    return (first == nullptr && second == nullptr);
}

// operator that stacks two stacks one on top of the other.
Stack Stack::operator+(const Stack& other) const {

    Stack temp; // a temp stack to reverse the push order caused by pushing the original Stacks
    Stack target; // the stack that will eventually hold all the elements [S1 | S2]

    StackNode* ptr = other.top; // pointer to the top of the second stack
    // pushing all elements from the second stack to temp
    while (ptr != nullptr) {
        temp.push(ptr->get_data());
        ptr = ptr->get_next();
    }

    ptr = this->top; // moving the pointer to the first stack top
    // pushing first stack elements to temp on top of the second stack elements
    while (ptr != nullptr) {
        temp.push(ptr->get_data());
        ptr = ptr->get_next();
    }

    ptr = temp.top; // moving the pointer to temp top
    // pushing all elements from temp to target in the correct order
    while (ptr != nullptr) {
        target.push(ptr->get_data());
        ptr = ptr->get_next();
    }

    // all elements are in order
    return target;
}

// operator that adds an in to the top of the stack
Stack Stack::operator+(const int value) const {
    Stack temp; // a new stack to hold the value
    temp.push(value); // push the value to temp stack
    // now we can use the + operator for the 2 stacks
    return *this + temp;
}

// operator that adds an int to the bottom of the stack
Stack operator+(int value, const Stack& other) {
    Stack temp; // a new stack to hold the value
    temp.push(value); // push the value to temp stack
    // now we can use the + operator for the 2 stacks
    return temp + other;
}

// insertion operator for easy printing
ostream& operator<<(ostream& os, const Stack& other) {

    // check if the given stack is empty
    if (other.isEmpty()) {
        os << "Stack is empty" << endl;
        return os;
    }

    // the stack has elements
    Stack temp; // a temp stack for order reverse
    StackNode* ptr = other.top; // pointer to the given stack top

    // as long as the stack has elements, push to temp stack
    while (ptr != nullptr) {
        temp.push(ptr->get_data());
        ptr = ptr->get_next();
    }

    ptr = temp.top; // the pointer now points to temp stack
    int i = 0; // element index for the printout
    // as long sa there are stack nodes, keep printing the data of the nodes
    while (ptr != nullptr) {
        i++;
        os << i << ". " << ptr->get_data() << endl;
        ptr = ptr->get_next();
    }
    return os;
}