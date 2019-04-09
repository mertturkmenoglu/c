#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    Stack *s = (Stack*) malloc(sizeof(Stack));
    s->item = (int*) malloc(DEFAULT_STACK_SIZE * sizeof(int));
    s->top = 0;

    push(s, 0);
    push(s, 1);
    push(s, 2);
    printStack(s);
    int tmp;
    peek(s, &tmp);
    printf("%d\n", tmp);
    printStack(s);
    pop(s, &tmp);
    printStack(s);

    free(s->item);
    free(s);
    return 0;
}