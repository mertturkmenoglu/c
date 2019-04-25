#include <stdio.h>
#include <stdlib.h>

// gcc -std=c11 main.c

_Noreturn void function() {
    return "Returns a string literal";
}

int main() {
    printf("Program starts.\n");

    function();

    printf("Program ends.\n");
    return 0;
}