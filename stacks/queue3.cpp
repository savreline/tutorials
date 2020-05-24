#include "queue.h"

/*** Queue using two stacks: O(1) solution ***/

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
    int result;

    // If there is nothing in s2, then we must transfer elements from s1 over
    if (s2.empty()) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

    // If there is something in s2, that is the element that we are looking for
    result = s2.top();
    s2.pop();
    return result;
}

/* Top */
int Queue::top() {  
    if (s2.empty()) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

    return s2.top();
}

/* Empty */
bool Queue::empty() {
    return s1.empty() && s2.empty();
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
