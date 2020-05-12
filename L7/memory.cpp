#include <iostream>
using namespace std;

int *foo() {
    int *x = new int(1);
    return x;
}

int main () {
    int *retFromFoo = foo();
    cout << "value of retFromFoo is " << *retFromFoo << endl;
    delete retFromFoo;
    // delete retFromFoo; // double-free error
}
