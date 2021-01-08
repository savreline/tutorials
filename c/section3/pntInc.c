// pntInc.c
// author: Sasha (Alexandre) Avreline, UBC BCS Tutor, Fall 2019
#include <stdio.h>

void main(void) {
    int a[] = {10, 20, 30, 40, 50};
    int *p = a;

    int x = *p++;
    printf("After *p++ the value of x is %d\n", x);   // 10
    printf("After *p++ the value of *p is %d\n", *p); // 20

    int y = *++p;
    printf("After *++p the value of y is %d\n", y);   // 30
    printf("After *++p the value of *p is %d\n", *p); // 30

    int v = (*p)++;
    printf("After (*p)++ the value of v is %d\n", v);   // 30
    printf("After (*p)++ the value of *p is %d\n", *p); // 31

    int w = ++(*p);
    printf("After ++(*p) the value of w is %d\n", w);   // 32
    printf("After ++(*p) the value of *p is %d\n", *p); // 32
}
