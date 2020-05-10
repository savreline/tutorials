#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

/* A function:
 Example of a if statement */
int tomorrow(int x) {
    if (x == 30) {
        return 1; 
    } else {
        return x + 1;
    }
}

/* How many days in a month:
 Example of a switch statement */
int dayInMonth(int month) {
    switch (month) {
        case 1: 
        case 3: 
        case 5: 
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return 28;
    }
}

/* Main Method */
int main() {
    int day = 6;
    int month = 5;
    int year = 2020;
    string greetings = "HELLO";

    // C++ style print statement
    cout << greetings << " today is: " << day << "/" << month << "/" << year << endl;

    // C style print statement [use %x to print values in hex, etc.]
    printf("%s, today is %d/%d/%d \n", greetings.c_str(), day, month, year);

    // Call to the Tomorrow Function
    cout << "Tomorrow is day " << tomorrow(day) << endl;

    // No. of Days in May
    cout << "No. Days in May is " << dayInMonth(5) << endl;

    // For Loop
    cout << "For Loop: ";
    for (int i = 0; i < 5; i++) {
        cout << i << " ";
    }
    cout << endl;

    // While Loop
    cout << "While Loop: ";
    int i = 3;
    while (i > 0) {
        cout << i << " ";
        i--;
    }
    cout << endl;

    // Technically main should return an int here,
    // the compiler assumes it returns 0 by default
    // and "0" mean that execution was "successful"
}
