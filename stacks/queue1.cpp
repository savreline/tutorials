#include "queue.h"

/*** Queue using two stacks: O(n) solution ***/

Queue::Queue() {
    s1 = stack<int>();
    s2 = stack<int>();
}

/* Push */
void Queue::push(int x) {
    s1.push(x);
}

/* Pop */
int Queue::pop() {
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }

    int result = s2.top();
    s2.pop();
    while (!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }

    return result;
}

/* Top */
int Queue::top() {
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }

    int result = s2.top();
    while (!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }

    return result;
}

/* Empty */
bool Queue::empty() {
    return s1.empty();
}

/* Main */
int main() {
    Queue q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);

    cout << q1.top() << endl; q1.pop();
    cout << q1.top() << endl; q1.push(4);
    cout << q1.top() << endl;
}
