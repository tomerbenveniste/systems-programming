#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <vector>
#include <climits>
using namespace std;

class MyQueue {
private:
    vector<int> queue;
    int maxQ;


public:
    MyQueue();
    MyQueue(int maxQ);
    ~MyQueue();
    int get_maxQ() const;
    void print_queue() const;
    bool enQueue(int element);
    bool deQueue();
    int peek() const;
    bool isEmpty() const;
    void set_maxQ(int maxQ);
    bool is_full() const;
};

#endif