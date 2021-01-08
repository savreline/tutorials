// pntIncS3.c
// author: Sasha (Alexandre) Avreline, UBC BCS Tutor, Fall 2019
#define STR_LEN 81
#include <stdio.h>
#include <string.h>

void foo(char *str, char *cpy) {
    int i = 0;
    while (str[i])
        cpy[i++] = str[i];

    cpy[i] = '\0';
}

int main() {
    char str[STR_LEN] = "abcde";
    char cpy[STR_LEN];
    foo(str, cpy);
    printf("Result is %s\n", cpy);
}
