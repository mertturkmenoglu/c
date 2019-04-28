#include "dsasort.h"
#include <stdlib.h>

void mergeSort(int *array, int start, int end)
{
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

void merge(int *array, int start, int mid, int end)
{
    // Size of merged array
    int n;
    n = end - start + 1;

    // Temporary array
    int *tempArray = (int*) malloc(n * sizeof(int));
    
    // i is index of the first part
    int i = start;

    // j is index of the second part
    int j = mid + 1;

    // Index of the merged array
    int index = 0;

    /*
     * Iterate over two parts of the array.
     * Compare two elements and append the smaller one
     * to merged array.
     */
    while ((i <= mid) && (j <= end))
        tempArray[index++] = (array[i] < array[j]) ? array[i++] : array[j++];

    // Append elements from first part to merged array if there is any
    while (i <= mid)
        tempArray[index++] = array[i++];

    // Append elements from second part to merged array if there is any
    while (j <= end)
        tempArray[index++] = array[j++];

    // Clone elements from temporary array to the original one
    for (i = start; i <= end; i++)
        array[i] = tempArray[i - start];
    
    free(tempArray);
}