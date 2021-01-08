// loops1.c
// author: Sasha (Alexandre) Avreline, UBC BCS Tutor, Fall 2019
#include <stdio.h>

void main() {
    int a[] = {1, 2, 3, 4, 5};
    int n = 5, sum = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    printf("Sum is %d\n", sum);

    sum = 0;

    int j = 0;
    for (;;) {
        if (j >= n)
            break;
        sum += a[j];
        j++;
    }

    printf("Sum is %d\n", sum);
}
