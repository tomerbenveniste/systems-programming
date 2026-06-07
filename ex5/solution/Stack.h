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
};

#endif