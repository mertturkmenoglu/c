#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
    int front;
    int rear;
    int size;
    unsigned int capacity;
    int *array;
} Queue;

Queue *createQueue(unsigned int initCapacity);

int isQueueFull(Queue *q);
int isQueueEmpty(Queue *q);

// Add item to queue
int enqueue(Queue *q, int item);
// Remove item from queue
int dequeue(Queue *q, int *var);
// Get the front item
int getFront(Queue *q, int *var);
// Get the rear item
int getRear(Queue *q, int *var);
// Print queue to stdout
void printQueue(Queue *q);
// Memory deallocate
void finalizeQueue(Queue *q);

#endif