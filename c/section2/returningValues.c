// returningValues.c
// author: Sasha (Alexandre) Avreline, UBC BCS Tutor, Fall 2019
#include <stdio.h>

typedef struct Point {
    int x, y, z;
} Point;

Point foo1(int x, int y, int z) {
    x += 10;
    y += 20;
    z += 30;
    Point p = {x, y, z};
    return p;
}

void foo2(int *a, int *b, int *c) {
    *a = *a + 1;
    *b = *b + 2;
    *c = *c + 3;
}

void main(void) {
    int x = 1, y = 2, z = 3;

    Point p = foo1(x, y, z);
    x = p.x, y = p.y;
    z = p.z;

    printf("x is %d\n", x); // 11
    printf("y is %d\n", y); // 22
    printf("z is %d\n", z); // 33

    int *a, *b, *c;
    a = &x, b = &y, c = &z;

    foo2(a, b, c);

    printf("x is %d\n", x); // 12
    printf("y is %d\n", y); // 24
    printf("z is %d\n", z); // 36
}
