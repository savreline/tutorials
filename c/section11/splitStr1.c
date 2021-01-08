// splitStr1.c
// author: Sasha (Alexandre) Avreline, UBC BCS Tutor, Fall 2019
#define NO_OF_COMPONENTS 10
#define STR_LEN 81
#include <stdio.h>
#include <string.h>

int split_str(char *input_str, char token, char components[][STR_LEN]) {
        char input_str_copy[STR_LEN];
        strcpy(input_str_copy, input_str);
        const char *token_string = (char[]){token, '\0'};

        int i = 0;
        char *result = strtok(input_str_copy, token_string);
        while (result) {
                strcpy(components[i++], result);
                result = strtok(NULL, token_string);
        }

        return i;
}

int main() {
        char components[NO_OF_COMPONENTS][STR_LEN];
        char *str = "www.example.com";
        char token = '.';

        int i = split_str(str, token, components);
        printf("Input string is %s\n", str);

        for (int j = 0; j < i; j++)
                printf("Component is %s\n", components[j]);
}
