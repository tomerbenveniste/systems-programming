/* Assignment C++: 1
Author: Tomer Benveniste, ID: 207961954 / Carmi Friedman, ID: 206463846
   */

#ifndef STACK_H
#define STACK_H

#include "StackNode.h"
#include <climits>
#include <iostream>

using namespace std;

class Stack {
private:
    StackNode* top;
    void copy_from(const Stack& other); // helper: deep copies other's elements into this (assumes this is empty)
    
public:
    Stack(); // normal Constructor
    Stack(const Stack& stack); // copy Constructor - deep copies all nodes from other into this stack
    Stack& operator=(const Stack& stack); // assignment operator - clears this stack then deep copies other into it
    ~Stack(); // normal Destructor
    bool push(int element);
    bool pop();
    bool isEmpty() const;
    int peek() const;
    void print_stack() const;
    Stack& operator+=(int value); // operator that pushes an integer to the stack
    bool operator==(const Stack&  other) const; // operator that compares two stacks
    Stack operator+(const Stack&  other) const; // operator that stacks two stacks on top of each other
    Stack operator+(int value) const; // operator that adds an int to the top of the stack
    friend Stack operator+(int value, const Stack& other); // operator that adds an int to the bottom of the stack
    friend ostream& operator<<(ostream& os, const Stack& other); // insertion operator for easy printing
};

#endif