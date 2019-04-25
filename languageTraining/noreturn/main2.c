#include <stdio.h>
#include <stdlib.h>

// gcc -std=c11 main2.c

_Noreturn void function() {
    printf("Prints a string literal\n");
}

int main() {
    printf("Program starts.\n");

    function();

    printf("Program ends.\n");
    return 0;
}