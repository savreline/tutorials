// passingValues1.c
// author: Sasha (Alexandre) Avreline, UBC BCS Tutor, Fall 2019
#include <stdio.h>

typedef struct Point {
    int x, y;
} Point;

void foo1(int p, int *q, int a[], Point pnt) {
    p = p + 2;
    *q = *q + 2;
    q = 0;
    a[0] = a[0] + 2;
    pnt.x = 300;
}

void foo2(int p, int *q, int **r) {
    *r = 0;
    r = 0;
    q = &p;
}

void main(void) {
    Point pnt = {100, 200};
    int a[] = {1, 2, 3, 4, 5};
    int p = 10;
    int *q = &p;
    int **r = &q;

    foo1(p, q, a, pnt);

    printf("The value of p is %d\n", p);         // 12
    printf("The value of q is %#x\n", q);        // 0x...
    printf("The value of *q is %d\n", *q);       // 12
    printf("The value of a[0] is %d\n", a[0]);   // 3
    printf("The value of pnt.x is %d\n", pnt.x); // 100

    foo2(p, q, r);

    printf("The value of q is %#x\n", q);   // 0
    printf("The value of r is %#x\n", r);   // 0x...
    printf("The value of *r is %#x\n", *r); // 0
}
