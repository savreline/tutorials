#include <iostream>
using namespace std;

int main() {
    int x = 1;
    int y = 2;

    // A pointer is a variable that stores the memory address of an another variable
    //  (i.e. points to that variable)
    // “Address of” [&] operator fetches the address of some variable
    int *p = &x;
    int *q = &y;

    cout << "Value of x: " << x << endl;
    cout << "Value of y: " << y << endl;
    cout << "Value of p: " << p << endl;
    cout << "Value of q: " << q << endl;

    // Dereference operator [*] “goes to” the address stored in the pointer
    cout << "Value of *p: " << *p << endl;
    cout << "Value of *q: " << *q << endl;

    // Change the value at the memory location pointed to by p
    *p = 3;

    cout << "AFTER THE CHANGE" << endl;
    cout << "Value of x: " << x << endl;
    cout << "Value of y: " << y << endl;
    cout << "Value of p: " << p << endl;
    cout << "Value of q: " << q << endl;

    // Change p to point to the same location as q
    p = q;

    cout << "AFTER RE-ASSIGN OF P" << endl;
    cout << "Value of x: " << x << endl;
    cout << "Value of y: " << y << endl;
    cout << "Value of p: " << p << endl;
    cout << "Value of q: " << q << endl;

    // Change the value at the memory location pointed to by p
    *p = 10; 

    cout << "AFTER RE-ASSIGN OF P & CHANGE TO 10" << endl;
    cout << "Value of x: " << x << endl;
    cout << "Value of y: " << y << endl;
    cout << "Value of p: " << p << endl;
    cout << "Value of q: " << q << endl;
}
