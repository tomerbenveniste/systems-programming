/* Assignment C++: 1
Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
   */

#ifndef STACK_H
#define STACK_H

#include "StackNode.h"
#include <climits>
#include <iostream>

using namespace std;

/* Stack is a linked-list based data structure that follows the LIFO (Last In First Out) principle.
 * It stores integers using dynamically allocated StackNode objects linked together. */
class Stack {
private:
    StackNode* top; // Pointer to the top node of the stack (nullptr when the stack is empty)
    void copy_from(const Stack& other); // helper: deep copies other's elements into this (assumes this is empty)
    
public:
    Stack(); // normal Constructor
    Stack(const Stack& stack); // copy Constructor - deep copies all nodes from other into this stack
    Stack& operator=(const Stack& stack); // assignment operator - clears this stack then deep copies other into it
    ~Stack(); // normal Destructor
    bool push(int element); // Pushes a new integer onto the top of the stack, returns true on success
    bool pop(); // Removes the top element from the stack, returns false if the stack is empty
    bool isEmpty() const; // Returns true if the stack has no elements, false otherwise
    int peek() const; // Returns the top element without removing it, returns INT_MIN if the stack is empty
    void print_stack() const; // Prints all stack elements numbered from top to bottom
    Stack& operator+=(int value); // operator that pushes an integer to the stack
    bool operator==(const Stack&  other) const; // operator that compares two stacks
    Stack operator+(const Stack&  other) const; // operator that stacks two stacks on top of each other
    Stack operator+(int value) const; // operator that adds an int to the top of the stack
    friend Stack operator+(int value, const Stack& other); // operator that adds an int to the bottom of the stack
    friend ostream& operator<<(ostream& os, const Stack& other); // insertion operator for easy printing
};

#endif