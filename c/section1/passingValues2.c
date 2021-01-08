// passingValues2.c
// author: Sasha (Alexandre) Avreline, UBC BCS Tutor, Fall 2019
#include <stdio.h>

void func1(int a, int b) {
    a = b;
}

void func2(int *a, int b) {
    *a = b;
}

void func3(int *a, int *b) {
    a = b;
}

void func4(int **a, int *b) {
    *a = b;
}

void main(void) {
    int i = 1;
    int j = 2;
    int k = 3;
    int *x = &i;
    int *y = &k;
    int **v = &x;       // v points to x, which points to i

    func1(i, j);                                // does nothing
    printf("The value of i is %d\n", i);        // 1

    func2(x, j);                                // sets value of x to j
    printf("The value of i is %d\n", i);        // 2

    func3(x, y);                                // does nothing
    printf("The value of *x is %d\n", *x);      // 2

    func4(v, y);                                // points x to k (and not i) 
    printf("The value of *x is %d\n", *x);      // 3
}
