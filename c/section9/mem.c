// mem.c
// author: Sasha (Alexandre) Avreline, UBC BCS Tutor, Fall 2019
#define BUF_SIZE 10
#include <stdio.h>
#include <stdlib.h>

int main() {
    int count = 0;
    int cur_size = BUF_SIZE;
    char *text = malloc(cur_size * sizeof(char));

    printf("Type in your input\n");

    while (1) {
        char c = getchar();

        if (c == '\n')
            break;

        if (count >= cur_size) {
            cur_size += BUF_SIZE;
            text = realloc(text, cur_size * sizeof(char));
        }

        text[count++] = c;
    }

    text[count] = '\0';
    printf("The text is %s\n", text);
    free(text);
}
