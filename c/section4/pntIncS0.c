// pntIncS0.c
// author: Sasha (Alexandre) Avreline, UBC BCS Tutor, Fall 2019
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *foo(char *str) {
    char *cpy = malloc((strlen(str) + 1) * sizeof(char));
    while (*str)
        *cpy++ = *str++;

    *cpy = '\0';
    return cpy;
}

int main() {
    char *str = "abcde";
    char *cpy = foo(str);
    printf("Result is %s\n", cpy);
    free(cpy);
}
