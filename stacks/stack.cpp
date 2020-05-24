#include "stack.h"

/*** Stack using queue ***/

Stack::Stack() {
    q1 = queue<int>();
}

/* Push */
void Stack::push(int x) {
    q1.push(x);

    int size = q1.size();
    while (size > 1) {
        q1.push(q1.front());
        q1.pop();
        size--;
    }
}

/* Pop */
int Stack::pop() {
    int result = q1.front();
    q1.pop();
    return result;
}

/* Top */
int Stack::top() {
    return q1.front();
}

/* Empty */
bool Stack::empty() {
    return q1.empty();
}

/* Main */
int main() {
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);

    cout << s1.top() << endl; s1.pop();
    cout << s1.top() << endl; s1.push(4);
    cout << s1.top() << endl;
}
