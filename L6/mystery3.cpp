#include <iostream>
using namespace std;

int mystery3(int x, int *y) {
    x += x;
    *y = x - 2;
    return x;
}

int main() {
    int a = 10;
    int *b = &a;
    int c = mystery3(a, b);

    cout << "value of &a: " << &a << endl; 
    cout << "value of a: " << a << endl;
    cout << "value of b: " << b << endl;
    cout << "value of *b: " << *b << endl;
    cout << "value of c: " << c << endl;
}
