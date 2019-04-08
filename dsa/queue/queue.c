#include "queue.h"
#include <stdio.h>
#include <stdlib.h>



/**
 * Create a queue with 
 * @param initCapacity  
 * @return a pointer to queue
 */
Queue *createQueue(unsigned int initCapacity) {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->capacity = initCapacity;
    q->front = 0;
    q->size = 0;
    q->rear = q->capacity - 1;
    q->array = (int*) malloc(q->capacity * sizeof(int));
    return q;
}



/**
 * If size of the queue is equal to its capacity(max)
 * then return 1 (true) else 0 (false)
 */
int isQueueFull(Queue *q) {
    return (q->size == q->capacity);
}



/**
 * If size of the queue is equal to 0, then there is no
 * element in the queue return 1 (true) else 0 (false)
 */
int isQueueEmpty(Queue *q) {
    return (q->size == 0);
}



/**
 * Add item to queue
 */
int enqueue(Queue *q, int item) {
    if(isQueueFull(q))
        return 0;
    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear] = item;
    q->size++;
    return 1;
}



/**
 * Remove item from queue
 * @param var is the pointer of the variable that will
 * hold the removed item
 * @return 1(true) if operation is successfull 
 * else 0(false).
 */
int dequeue(Queue *q, int *var) {
    if(isQueueEmpty(q))
        return 0;
    *var = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return 1;
}



/**
 * Get the front item of the queue and assign it to
 * @param var
 * @return 1(true) if operation is successfull 
 * else 0(false).
 */
int getFront(Queue *q, int *var){
    if(isQueueEmpty(q))
        return 0;
    *var = q->array[q->front];
    return 1;
}



/**
 * Get the rear item of the queue and assign it to
 * @param var
 * @return 1(true) if operation is successfull
 * else 0(false).
 */
int getRear(Queue *q, int *var) {
    if(isQueueEmpty(q))
        return 0;
    *var = q->array[q->rear];
    return 1;
}



/**
 * Print the queue to stdout
 */
void printQueue(Queue *q) {
    int i;
    for(i = q->front; i <= q->rear; i++) {
        printf("%d\t", q->array[i]);
    }
    printf("\n");
}



/**
 * Deallocate memory
 */
void finalizeQueue(Queue *q) {
    free(q->array);
    q->array = NULL;
    q = NULL;
}