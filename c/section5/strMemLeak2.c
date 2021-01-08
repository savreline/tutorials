// strMemLeak2.c
// author: Sasha (Alexandre) Avreline, UBC BCS Tutor, Fall 2019
#define STR_LEN 81
#include <stdio.h>
#include <string.h>

int main() {
    char str[STR_LEN] = "abcde";
    char cpy[STR_LEN];
    strcpy(cpy, str);
    printf("Result is %s\n", cpy);
}
