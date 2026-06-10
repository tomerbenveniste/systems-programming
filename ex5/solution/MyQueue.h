/* Assignment C++: 1
Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
   */

#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <vector>
#include <climits>
using namespace std;

/* MyQueue is a vector-based queue with a fixed maximum capacity.
 * It follows the FIFO (First In First Out) principle - elements are added at the back and removed from the front. */
class MyQueue {
private:
    vector<int> queue; // The underlying container holding the queue elements (front is index 0)
    int maxQ; // The maximum number of elements the queue can hold

public:
    MyQueue(); // Default constructor - initializes the queue with maxQ set to 0 (unlimited until set)
    MyQueue(int maxQ); // Parameterized constructor - initializes the queue with the given maximum capacity
    ~MyQueue(); // Destructor - drains the queue before destruction using cleanQueue()
    int get_maxQ() const; // Returns the maximum capacity of the queue
    void print_queue() const; // Prints all elements from front to back separated by " <- ", prints nothing if empty
    bool enQueue(int element); // Adds an element to the back of the queue, returns false if the queue is full
    bool deQueue(); // Removes the front element from the queue, returns false if the queue is empty
    int peek() const; // Returns the front element without removing it, returns -1 if the queue is empty
    bool isEmpty() const; // Returns true if the queue has no elements, false otherwise
    void set_maxQ(int maxQ); // Sets the maximum capacity of the queue to the given value
    bool is_full() const; // Returns true if the number of elements has reached maxQ, false otherwise
    void cleanQueue(); // Removes all elements from the queue by repeatedly calling deQueue()
};

#endif