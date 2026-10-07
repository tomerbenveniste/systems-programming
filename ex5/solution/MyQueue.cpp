/* Assignment C++: 1
Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
   */

#include <iostream>
#include "MyQueue.h"

using namespace std;
// Default constructor - initializes the queue with maxQ set to 0
MyQueue::MyQueue() : buffer(), head(0), count(0), maxQ(0) {
}
// Parameterized constructor - initializes the queue with the given maximum capacity
MyQueue::MyQueue(int maxQ) : buffer(maxQ > 0 ? maxQ : 0), head(0), count(0), maxQ(maxQ) {
}
// Destructor of the MyQueue class - uses cleanQueue method
MyQueue::~MyQueue() {
    this->cleanQueue();
}
// Empties the queue by repeatedly removing the front element until nothing is left
void MyQueue::cleanQueue() {
    while (!this->isEmpty()) {
        this->deQueue();
    }
}
/* The set_maxQ function sets the maximum capacity of the queue to the given value.
 * The buffer is reallocated to the new size and any existing elements are copied over in order,
 * starting from index 0. If the new capacity is smaller than the current element count, the buffer
 * keeps room for all of them (nothing is lost) and is_full() simply reports the queue as full. */
void MyQueue::set_maxQ(int maxQ) {
    int capacity = maxQ > this->count ? maxQ : this->count;
    vector<int> resized(capacity);
    for (int i = 0; i < this->count; i++) {
        resized[i] = buffer[(head + i) % buffer.size()];
    }
    buffer.swap(resized);
    this->head = 0;
    this->maxQ = maxQ;
}

// The get_maxQ function returns the maximum capacity of the queue.
int MyQueue::get_maxQ() const {
    return this->maxQ;
}

/* The print_queue function prints the elements of the queue from front to back.
 * If the queue is empty, it prints nothing. */
void MyQueue::print_queue() const {
    if (isEmpty()) {
        return;
    }
    // Walk count elements starting at head, wrapping around the end of the buffer, separating them with " <- "
    for (int i = 0; i < count; i++) {
        cout  << buffer[(head + i) % buffer.size()] << "";
        if (i != count - 1) {
            cout << " <- " << "";
        }
    }
    cout << endl;
}
/* The enQueue function adds an element to the back of the queue. If the queue is full
 * (i.e., its size is greater than or equal to maxQ), it returns false. Otherwise, it writes the element
 * into the slot just after the last element (wrapping around to index 0 if needed) and returns true. */
bool MyQueue::enQueue(int element) {
    if (is_full()) {
        return false;
    }
    buffer[(head + count) % buffer.size()] = element;
    count++;
    return true;
}

/* The deQueue function removes an element from the front of the queue. If the queue is empty,
 * it returns false. Otherwise, it advances the front index by one (wrapping around) and returns true.
 * No elements are moved, so this is O(1). */
bool MyQueue::deQueue() {
    if (isEmpty()) {
        return false;
    }
    head = (head + 1) % buffer.size();
    count--;
    return true;
}
/* The peek function returns the front element of the queue without removing it. If the queue is empty,
 * it returns -1 to indicate that the queue is empty. Otherwise, it returns the front element of the queue. */
int MyQueue::peek() const {
    if (isEmpty()) {
        return -1; // Return -1 to indicate the queue is empty
    }
    return buffer[head];
}
// The isEmpty function checks if the queue is empty. It returns true if the queue is empty and false otherwise.
bool MyQueue::isEmpty() const {
    return count == 0;
}
/* The is_full function checks if the queue is full. It returns true if the number of elements is greater
 * than or equal to maxQ and false otherwise. */
bool MyQueue::is_full() const {
    return count >= maxQ;
}
