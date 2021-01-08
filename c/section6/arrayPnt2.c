// arrayPnt2.c
// author: Sasha (Alexandre) Avreline, UBC BCS Tutor, Fall 2019
#include <stdio.h>
#include <string.h>

int foo(int a[], int n) { // OK!
    int sum = 0;
    int *aEnd = a + n;
    for (; a < aEnd; a++)
        sum += *a;
    return sum;
}

void main() {
    int a[] = {1, 2, 3, 4, 5};
    int n = 5;

    for (int i = 0; i < n; i++) // OK!
        printf("val is %d\n", *(a + i));

    int *aEnd = a + n;
    for (; a < aEnd; a++) // does not compile
        printf("val is %d\n", *a);

    int *b = a;
    int *bEnd = b + n;
    for (; b < bEnd; b++) // OK!
        printf("val is %d\n", *b);

    printf("Sum is %d\n", foo(a, n));
}
