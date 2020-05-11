#include <iostream>
using namespace std;

void mystery2(int &x, int *y, int *&z) {
    x *= 10;
    *y += x;
    z = &x;
}

int main() {
    int a = 3;
    int b = 5;
    int *c = &b;
    mystery2(a, &b, c);
    
    cout << "value of &a: " << &a << endl;
    cout << "value of a: " << a << endl;
    cout << "value of b: " << b << endl;
    cout << "value of c: " << c << endl;
    cout << "value of *c: " << *c << endl;
}
