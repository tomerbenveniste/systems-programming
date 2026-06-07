#include <iostream>
#include "MyQueue.h"

using namespace std;
// The default constructor of the MyQueue class initializes
MyQueue::MyQueue() {
    this->maxQ = 0;
}
// The parameterized constructor of the MyQueue class initializes
MyQueue::MyQueue(int maxQ) {
    this->maxQ = maxQ;
}
// The destructor of the MyQueue class 
MyQueue::~MyQueue() {
    // No manual delete needed
}
// The set_maxQ function sets the maximum capacity of the queue to the given value.
void MyQueue:: set_maxQ(int maxQ) {
    this->maxQ = maxQ;
}

// The get_maxQ function returns the maximum capacity of the queue.
int MyQueue:: get_maxQ() const {
    return this->maxQ;
}

/* The print_queue function prints the elements of the queue. If the queue is empty,
 * it prints a message indicating that the queue is empty. */
void MyQueue::print_queue() const {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    for (size_t i = 0; i < queue.size(); i++) {
        cout << queue[i] << " ";
    }

    cout << endl;
}
/* The enQueue function adds an element to the back of the queue. If the queue is full
 * (i.e., its size is greater than or equal to maxQ), it prints a message indicating that the queue
 * is full and returns false. Otherwise, it adds the element to the back of the queue and returns true. */
bool MyQueue::enQueue(int element) {
    if (queue.size() >= maxQ) {
        cout << "Queue is full" << endl;
        return false;
    }
    queue.push_back(element);
    return true;
}

/* The deQueue function removes an element from the front of the queue. If the queue is empty,
 * it prints a message indicating that the queue is empty and returns false. Otherwise, it removes
 * the front element from the queue and returns true. */
bool MyQueue::deQueue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return false;
    }

    queue.erase(queue.begin());
    return true;
}

// The peek function returns the front element of the queue without removing it. If the queue is empty, it returns -1 to indicate that the queue is empty. Otherwise, it returns the front element of the queue.
int MyQueue::peek() const {
    if (isEmpty()) {
        return -1; // Return -1 to indicate the queue is empty
    }

    return queue[0];
}

// The isEmpty function checks if the queue is empty. It returns true if the queue is empty and false otherwise.
bool MyQueue::isEmpty() const {
    return queue.empty();
}

// The is_full function checks if the queue is full. It returns true if the size of the queue is greater than or equal to maxQ and false otherwise.
bool MyQueue::is_full() const {
    return queue.size() >= maxQ;
}