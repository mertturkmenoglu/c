/**
 * Data Structures and Algorithms
 * Basic Sort Algorithms Implementation
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dsasort.h"

void copyArray(int *dest, int *src, int n);
void printArray(int *array, int n);

int main() {
    srand(time(NULL));  // Random seed

    int *array;
    int *temp;
    int n = 10;     // Array length. Just an arbitrary number
    int i;

    // Memory allocation
    array = (int*) malloc(n * sizeof(int));
    temp = (int*) malloc(n * sizeof(int));

    // Assigning random values
    for(i = 0; i < n; i++) {
        array[i] = rand() % 100;    // Again just an arbitrary number
        temp[i] = array[i];
    }

    // Print original array
    printArray(array, n);

    // Sort with Bubble Sort and print
    bubbleSort(temp, n);
    printArray(temp, n);

    // Copy array and sort with Insertion Sort and print
    copyArray(temp, array, n);
    insertionSort(temp, n);
    printArray(temp, n);

    // Copy array and sort with Selection Sort and print
    copyArray(temp, array, n);
    selectionSort(temp, n);
    printArray(temp, n);

    // Copy array and sort with Shell Sort and print
    copyArray(temp, array, n);
    shellSort(temp, n);
    printArray(temp, n);
    
    free(temp);
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

void copyArray(int *dest, int *src, int n)
{
    int i;
    for(i = 0; i < n; i++)
        dest[i] = src[i];
}