/**
 * Driver code for testing
 * queue structure
 */
#include <stdio.h>
#include "queue.h"

void printQueue(Queue *q);

int main(void) {
    Queue *q = createQueue(10);

    enqueue(q, 1);
    enqueue(q, 2);
    printQueue(q);

    enqueue(q, 3);
    enqueue(q, 4);
    printQueue(q);

    int var;
    dequeue(q, &var);
    printQueue(q);
    printf("var: %d\n", var);

    dequeue(q, &var);
    printQueue(q);
    printf("var: %d\n", var);

    finalizeQueue(q);

    return 0;
}

