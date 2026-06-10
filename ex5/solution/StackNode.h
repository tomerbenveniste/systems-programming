/* Assignment C++: 1
Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
   */

#ifndef STACKNODE_H
#define STACKNODE_H

using namespace std;

/* StackNode represents a single node in a linked list used by the Stack class.
 * Each node holds an integer value and a pointer to the next node in the list. */
class StackNode {

private:
    int data; // The integer value stored in this node
    StackNode* next; // Pointer to the next node in the stack (nullptr if this is the bottom node)

public:
    StackNode(); // Default constructor - initializes data to 0 and next to nullptr
    StackNode(int data); // Parameterized constructor - initializes data to the given value and next to nullptr
    ~StackNode(); // Destructor - no dynamic memory to free since next is managed by the Stack
    int get_data() const; // Returns the integer value stored in this node (read-only, does not modify the object)
    StackNode* get_next() const; // Returns a pointer to the next node in the stack (read-only, does not modify the object)
    void set_next(StackNode* next); // Sets the next pointer to the given node (used when linking nodes together)
};

#endif