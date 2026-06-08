/* Assignment C++: 1
Author: Tomer Benveniste, ID: 207961954 / Carmi Friedman, ID: 206463846
   */

#ifndef STACKNODE_H
#define STACKNODE_H

using namespace std;

class StackNode {
private:
    int data;
    StackNode* next;

public:
    StackNode();
    StackNode(int data);
    ~StackNode();
    int get_data() const;
    StackNode* get_next() const;
    void set_next(StackNode* next);
};

#endif