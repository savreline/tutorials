#include <iostream>
using namespace std;

/* 1. Does Nothing */
void add(int x, int y) {
    x = x + y;
}

/* 2. Changes Values */
void add(int *x, int *y) {
    *x = *x + *y;
    x = y;
}

/* 3. Changes Pointers and Values */
void add(int **x, int **y) {
    **x = **x + **y;
    *x = *y;
}

/* Do not do this:
    do not return an address of a local varaible */
int *foo() {
    int v = 1;
    int *w = &v;
    return w;
}

int main() {
    int x = 1;
    int y = 2;

    // A pointer is a variable that stores the memory address of an another variable
    //  (i.e. points to that variable)
    // “Address of” [&] operator fetches the address of some variable
    int *p = &x;
    int *q = &y;

    // Double Pointers
    int **a = &p;
    int **b = &q;

    add(x, y);
    cout << "Value of x: " << x << endl;
    cout << "Value of y: " << y << endl;
    cout << "Value of p: " << p << endl;
    cout << "Value of q: " << q << endl;

    add(p, q);
    cout << "RESULT OF THE POINTER VERSION" << endl;
    cout << "Value of x: " << x << endl;
    cout << "Value of y: " << y << endl;
    cout << "Value of p: " << p << endl;
    cout << "Value of q: " << q << endl;

    add(a, b);
    cout << "RESULT OF THE DOUBLE POINTER VERSION" << endl;
    cout << "Value of x: " << x << endl;
    cout << "Value of y: " << y << endl;
    cout << "Value of p: " << p << endl;
    cout << "Value of q: " << q << endl;

    // The returned value here is garbage
    int *retFromFoo = foo();
    cout << "Value of *retFromFoo: " << *retFromFoo << endl;

    // Always initialize pointers!
    int *c;
    cout << "Value of *c: " << *c << endl;

    // Null pointers cause the program to crash
    int *d = NULL;
    cout << "Value of *d: " << *d << endl;
}
