// strMemLeak1.h
// author: Sasha (Alexandre) Avreline, UBC BCS Tutor, Fall 2019
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str = "abcde";
    char *cpy = strdup(str);
    printf("Result is %s\n", cpy);
    free(cpy);
}
