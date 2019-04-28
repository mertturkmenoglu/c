/**
 * Data Structures and Algorithms
 * Basic Sort Algorithms Implementation
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dsasort.h"

void copyArray(int *dest, int *src, int n);
void printArray(char *message, int *array, int n);

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
    printArray("Original array: ", array, n);

    // Sort with Bubble Sort and print
    bubbleSort(temp, n);
    printArray("Bubble sort: ", temp, n);

    // Copy array and sort with Insertion Sort and print
    copyArray(temp, array, n);
    insertionSort(temp, n);
    printArray("Insertion sort: ", temp, n);

    // Copy array and sort with Merge Sort and print
    copyArray(temp, array, n);
    mergeSort(temp, 0, n-1);
    printArray("Merge sort: ", temp, n);

    // Copy array and sort with Selection Sort and print
    copyArray(temp, array, n);
    selectionSort(temp, n);
    printArray("Selection sort: ", temp, n);

    // Copy array and sort with Shell Sort and print
    copyArray(temp, array, n);
    shellSort(temp, n);
    printArray("Shell sort: ", temp, n);
    
    free(temp);
    free(array);
    return 0;
}

void printArray(char *message, int *array, int n)
{
    int i;
    printf("%s\n", message);
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