#include <iostream>
#include "MyQueue.h"

using namespace std;
MyQueue::MyQueue() {
    this->maxQ = 0;
}
MyQueue::MyQueue(int maxQ) {
    this->maxQ = maxQ;
}

MyQueue::~MyQueue() {
    // No manual delete needed
}

void MyQueue:: set_maxQ(int maxQ) {
    this->maxQ = maxQ;
}

int MyQueue:: get_maxQ() const {
    return this->maxQ;
}

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

bool MyQueue::enQueue(int element) {
    if (queue.size() >= maxQ) {
        cout << "Queue is full" << endl;
        return false;
    }
    queue.push_back(element);
    return true;
}


bool MyQueue::deQueue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return false;
    }

    queue.erase(queue.begin());
    return true;
}

int MyQueue::peek() const {
    if (isEmpty()) {
        return -1; // Return -1 to indicate the queue is empty
    }

    return queue[0];
}

bool MyQueue::isEmpty() const {
    return queue.empty();
}

bool MyQueue::is_full() const {
    return queue.size() >= maxQ;
}