#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <vector>
#include <climits>
using namespace std;

class MyQueue {
private:
    vector<int> queue;

public:
    MyQueue();
    ~MyQueue();

    void print_queue() const;
    void enqueue(int element);
    void dequeue();
    int peek() const;
    bool is_empty() const;
};

#endif