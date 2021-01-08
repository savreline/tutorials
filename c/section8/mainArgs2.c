// mainArgs2.c
// author: Sasha (Alexandre) Avreline, UBC BCS Tutor, Fall 2019
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    // Check no.
    if (argc < 2 + 1 || argc > 4 + 1) {
        printf("Invalid no. of arguments\n");
        return -1;
    }

    char *ep;
    int *args = malloc(argc * sizeof(int));

    // Convert
    for (int i = 0; i < argc - 1; i++) {
        args[i] = strtol(argv[i + 1], &ep, 10);
        if (*ep) {
            printf("An argument is not a number, x is %d, value of *ep is %s\n",
                   args[i], ep);
            free(args);
            return -1;
        }
    }

    // Use the args
    for (int i = 0; i < argc - 1; i++)
        printf("Argument %d is %d\n", i, args[i]);

    free(args);
    return 0;
}
