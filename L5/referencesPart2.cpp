#include <iostream>
using namespace std;

void add1(int x, int y) {
    x = x + y;
}

void add2(int &x, int &y) {
    x = x + y;
}

void add3(int *&x, int *&y) {
    *x = *x + *y;
    x = y;
}

int main() {
    int x = 1;
    int y = 2;

    // A reference is a variable that is a direct, fixed link to an another variable
    int &r = x;
    int &s = y;

    // Pointers to x and y
    int *p = &x;
    int *q = &y;

    add2(x, y);
    cout << "Value of x is: " << x << endl;
    cout << "Value of y is: " << y << endl;
    cout << "Value of p is: " << p << endl;
    cout << "Value of q is: " << q << endl;

    add3(p, q);
    cout << "After add3" << endl;
    cout << "Value of x is: " << x << endl;
    cout << "Value of y is: " << y << endl;
    cout << "Value of p is: " << p << endl;
    cout << "Value of q is: " << q << endl;
}
