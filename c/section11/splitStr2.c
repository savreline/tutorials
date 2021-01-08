// splitStr2.c
// author: Sasha (Alexandre) Avreline, UBC BCS Tutor, Fall 2019
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split_str(char *input_str, char token) {
    int i = 0;
    char *input_str_copy = input_str;

    while (*input_str_copy++)
        if (*input_str_copy == token)
            i++;

    input_str_copy = strdup(input_str);
    const char *token_string = (char[]){token, '\0'};
    char **components = malloc((i + 2) * sizeof(char *));
    char **components_pnt = components;

    char *result = strtok(input_str_copy, token_string);
    while (result) {
        *components++ = strdup(result);
        result = strtok(NULL, token_string);
    }

    *components = NULL;
    free(input_str_copy);
    return components_pnt;
}

int main() {
    char *str = "www.example.com";
    char token = '.';

    char **components = split_str(str, token);
    printf("Input string is %s\n", str);

    char **components_pnt = components;
    while (*components)
        printf("Component is %s\n", *components++);

    // free memory
    components = components_pnt;
    while (*components)
        free(*components++);
    free(components_pnt);
}
