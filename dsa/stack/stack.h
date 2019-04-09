#ifndef DSASTACK_H
#define DSASTACK_H
#include "Boolean.h"

#ifndef DEFAULT_STACK_SIZE
#define DEFAULT_STACK_SIZE 100
#endif

typedef struct {
    int *item;
    int top;
} Stack;

Boolean isFull(Stack *stack);
Boolean isEmpty(Stack *stack);
Boolean peek(Stack *stack, int *pPeek);
void printStack(Stack *stack);
Boolean push(Stack *stack, int value);
Boolean pop(Stack *stack, int *pPop);

#endif