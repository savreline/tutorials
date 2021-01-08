// arrayPnt1.c
// author: Sasha (Alexandre) Avreline, UBC BCS Tutor, Fall 2019
#include <stdio.h>
#include <string.h>

int foo1(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

int foo2(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

int foo3(int *a, int n) {
    int sum = 0;
    int *aEnd = a + n;
    for (; a < aEnd; a++)
        sum += *a;
    return sum;
}

int foo4(int a[], int n) {
    int sum = 0;
    a = (int []) {5, 10, 15, 20, 25};
    int *aEnd = a + n;
    for (; a < aEnd; a++)
        sum += *a;
    return sum;
}

void main() {
    int a[] = {1, 2, 3, 4, 5};
    int n = 5;

    printf("Foo1 sum is %d\n", foo1(a, n));
    printf("Foo2 sum is %d\n", foo2(a, n));
    printf("Foo3 sum is %d\n", foo3(a, n));
    printf("Foo4 sum is %d\n", foo4(a, n));
}
