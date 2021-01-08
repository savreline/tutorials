#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <queue>
using namespace std;

class Stack {
    private:
    queue<int> q1;

    public:
    Stack();
    void push(int x);
    int pop();
    int top();
    bool empty();
};

#endif