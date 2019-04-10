#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heap.h"

void printArray(array, n);

// Driver code for heap sort
int main()
{
    // Random seed
    srand(time(NULL));
    
    int i;
    int n = 10;
    int *array = (int*) malloc(n * sizeof(int));

    // Init array
    for(i = 0; i < n; i++)
        array[i] = rand() % 50; // Just an arbitrary number

    printArray(array, n);
    heapSort(array, n);
    printArray(array, n);

    free(array);
    return 0;
}

void printArray(int *array, int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d\t", array[i]);
    printf("\n");
}