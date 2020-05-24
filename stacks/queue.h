#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stack>
using namespace std;

class Queue {
    private:
    stack<int> s1;
    stack<int> s2;

    public:
    Queue();
    void push(int x);
    int pop();
    int top();
    bool empty();
};

#endif
