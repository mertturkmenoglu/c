#include "stack.h"
#include <stdio.h>

Boolean isFull(Stack *stack)
{
    return (stack->top == DEFAULT_STACK_SIZE) ? TRUE : FALSE;
}

Boolean isEmpty(Stack *stack)
{
    return (stack->top == 0) ? TRUE : FALSE;
}

Boolean peek(Stack *stack, int *pPeek)
{
    if(isEmpty(stack) != TRUE) {
        *pPeek = stack->item[stack->top];
        return TRUE;
    }
    return FALSE;
}

void printStack(Stack *stack)
{
    int i;
    for(i = 0; i < stack->top; i++)
        printf("%d\t", stack->item[i]);
    printf("\n");
}

Boolean push(Stack *stack, int value)
{
    if(isFull(stack) != TRUE) {
        stack->item[stack->top++] = value;
        return TRUE;
    }
    return FALSE;
}

Boolean pop(Stack *stack, int *pPop)
{
    if(isEmpty(stack) != TRUE) {
        *pPop = stack->item[--(stack->top)];
        return TRUE;
    }
    return FALSE;
}