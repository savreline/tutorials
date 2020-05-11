#include <iostream>
using namespace std;

int main() {
    int x = 1;
    int y = 2;

    // A reference is a variable that is a direct, fixed link to an another variable
    int &r = x;
    int &s = y;

    cout << "Value of x is: " << x << endl;
    cout << "Value of y is: " << y << endl;
    cout << "Value of r is: " << r << endl;
    cout << "Value of s is: " << s << endl;

    // Change r to 10
    r = 10;
    cout << "After changing r" << endl;
    cout << "Value of x is: " << x << endl;
    cout << "Value of y is: " << y << endl;
    cout << "Value of r is: " << r << endl;
    cout << "Value of s is: " << s << endl;

    // Change x to 5
    x = 5;
    cout << "After changing x" << endl;
    cout << "Value of x is: " << x << endl;
    cout << "Value of y is: " << y << endl;
    cout << "Value of r is: " << r << endl;
    cout << "Value of s is: " << s << endl;

    // References cannot be re-assigned
    r = y;
    cout << "After r = y" << endl;
    cout << "Value of x is: " << x << endl;
    cout << "Value of y is: " << y << endl;
    cout << "Value of r is: " << r << endl;
    cout << "Value of s is: " << s << endl;

    // Change y
    y = 100;
    cout << "After y = 100" << endl;
    cout << "Value of x is: " << x << endl;
    cout << "Value of y is: " << y << endl;
    cout << "Value of r is: " << r << endl;
    cout << "Value of s is: " << s << endl;
}
