#include <iostream>
#include "MyQueue.h"

using namespace std;

MyQueue::MyQueue() {
    // The vector is empty by default
}

MyQueue::~MyQueue() {
    // No manual delete needed
}

void MyQueue::print_queue() const {
    if (is_empty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    for (size_t i = 0; i < queue.size(); i++) {
        cout << queue[i] << " ";
    }

    cout << endl;
}

void MyQueue::enqueue(int element) {
    queue.push_back(element);
}

void MyQueue::dequeue() {
    if (is_empty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    queue.erase(queue.begin());
}

int MyQueue::peek() const {
    if (is_empty()) {
        return INT_MIN;
    }

    return queue[0];
}

bool MyQueue::is_empty() const {
    return queue.empty();
}