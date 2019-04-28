#include "dsasort.h"

void quickSort(int *array, int start, int end)
{
    if (start < end) {
        int partititonIndex = partition(array, start, end);
        quickSort(array, start, partititonIndex - 1);
        quickSort(array, partititonIndex + 1, end);
    }
}


int partition(int *array, int start, int end)
{
    int pivot = array[end];
    int i = start - 1;
    int j;
    int temp;

    for (j = start; j <= end - 1; j++) {
        if (array[j] <= pivot) {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    i++;
    temp = array[i];
    array[i] = array[end];
    array[end] = temp;

    return i;
}