// splitStr3.c
// author: Sasha (Alexandre) Avreline, UBC BCS Tutor, Fall 2019
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void split_str(char *input_str, char token, char ***components_addr) {
    int i = 0;
    char *input_str_copy = strdup(input_str);
    const char *token_string = (char[]){token, '\0'};
    char **components = *components_addr;

    char *result = strtok(input_str_copy, token_string);
    while (result) {
        components[i] = strdup(result);
        components = realloc(components, (++i + 1) * sizeof(char *));
        result = strtok(NULL, token_string);
    }

    components[i] = NULL;
    *components_addr = components;
    free(input_str_copy);
}

int main() {
    char *str = "www.example.com";
    char token = '.';

    char **components = malloc(sizeof(char *));
    char ***components_addr = &components;
    split_str(str, token, components_addr);
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
