/* Assignment C++: 1
Author: Tomer Benveniste, ID: 207961954 / Carmi Friedman, ID: 206463846
   */

#ifndef STACK_H
#define STACK_H

#include "StackNode.h"
#include <climits>

using namespace std;

class Stack {
private:
    StackNode* top;
    
public:
    Stack();
    ~Stack();
    void push(int element);
    void pop();
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