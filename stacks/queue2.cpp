#include "queue.h"

/*** Queue using one stack: recursive solution ***/

Queue::Queue() {
    s1 = stack<int>();
}

/* Push */
void Queue::push(int x) {
    s1.push(x);    
}

/* Pop */
int Queue::pop() {
    int val = s1.top(); 
    s1.pop();

    if (s1.empty())
        return val;
    else {
        int result = pop();
        s1.push(val);
        return result;
    }
}

/* Top */
int Queue::top() {
    int val = s1.top();
    s1.pop();

    if (s1.empty()) {
        s1.push(val);
        return val;
    }
    else {
        int result = top();
        s1.push(val);
        return result;
    }
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
