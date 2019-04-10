#include "heap.h"
/**
 * 
 */
void heapSort(int *array, int n)
{
    int i, temp;
    // Heapify 
    for(i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i); 

    for (i = n - 1; i >= 0; i--) {
        // Swap root and end node
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        // Heapify again
        heapify(array, i, 0);
    }
}