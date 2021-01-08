// loops2.c
// author: Sasha (Alexandre) Avreline, UBC BCS Tutor, Fall 2019
#include <stdio.h>

void main() {
    puts("\n");
    int a[] = {1, 2, 3, 4, 5};
    int n = 5;

    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];

    for (int i = 0; i < n; i++)
        printf("Final value of a[%d] is %d\n", i, a[i]);

    puts("\n");
    int b[] = {1, 2, 3, 4, 5};

    for (int i = 1, j = 0; i < n; i++, j++)
        b[i] += b[j];

    for (int i = 0; i < n; i++)
        printf("Final value of b[%d] is %d\n", i, b[i]);
}
