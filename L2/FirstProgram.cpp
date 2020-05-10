#include <iostream>
#include <string>
#include "FirstProgram.h"
using namespace std;

/* Main Method */
int main() {
    int day = 6;
    int month = 5;
    int year = 2020;
    string greeting = "HELLO";

    // Prints Today's Date
    cout << greeting << ", today is: " << day << "/" << month << "/" << year << endl;

    // Prints Tomorrow's Date
    cout << "Tomorrow is the " << tomorrow(day) << "th" << endl;

    // Call to A
    cout << "Result of call to A: " << A(5) << endl;
}

/* Tomorrow Function */
int tomorrow(int day) {
    if (day == 30) {
        return 1;
    } else {
        return day + 1;
    }
}

int A(int x) {
    if (x > 0) {
        x--;
        x = B(x);
    }
    return x;
}

int B(int x) {
    if (x > 0) {
        x--;
        x = A(x);
    }
    return x;
}
