#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int b = 8;
    int &c = a;
    int *d = &a;
    int *e = &b;
    int **f = &d;
    
    d = e;
    e = &a;
    f = &e;
    **f = 4;

    cout << "value of &a: " << &a << endl;
    cout << "value of a: " << a << endl;
    cout << "value of b: " << b << endl;
    cout << "value of c: " << c << endl;
    cout << "value of *d: " << *d << endl;
    cout << "value of *e: " << *e << endl;
    cout << "value of *f: " << *f << endl;
    cout << "value of **f: " << **f << endl;
}
