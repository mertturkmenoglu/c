/**
 * A stack can hold N element
 * We have 2*N element
 * Use 2 stack as one stack (User doesn't know there is two stack)
 * (User pushes / popes without knowing stack implementation)
 */
#include "../stack.h"
#include "../Boolean.h"
#include <stdio.h>
#include <stdlib.h>

Stack *s1;
Stack *s2;

void ctrlPrintStack();
Boolean ctrlPush(int value);
Boolean ctrlPop(int *pPop);

int main() {
    
    s1 = (Stack*) malloc(sizeof(Stack));
    s2 = (Stack*) malloc(sizeof(Stack));
    int sSize = 1;  // !PLEASE CHANGE THIS VALUE IN STACK.H TOO
    s1->item = (int*) malloc(sSize * sizeof(int));
    s2->item = (int*) malloc(sSize * sizeof(int));
    s1->top = 0;
    s2->top = 0;

    // ------ Insert Your Driver Code Here ------

    // ------ End ------

    free(s1);
    free(s2);
    return 0;
}

void ctrlPrintStack()
{
    printStack(s1);
    if(isEmpty(s2) != TRUE) {
        printf("s2:");
        printStack(s2);
    }
}

Boolean ctrlPush(int value)
{
    if(isFull(s1) != TRUE) {
        push(s1, value);
        return TRUE;
    }

    if((isFull(s1) == TRUE) && (isFull(s2) != TRUE)) {
        push(s2, value);
        return TRUE;
    }
    return FALSE;
}

Boolean ctrlPop(int *pPop)
{
    if(isEmpty(s1) == TRUE)
        return FALSE;
    
    if(isEmpty(s2) == TRUE) {
        pop(s1, pPop);
        return TRUE;
    } else {
        pop(s2, pPop);
        return TRUE;
    }
}