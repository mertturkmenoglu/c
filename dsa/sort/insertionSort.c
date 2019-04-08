#include "dsasort.h"

void insertionSort(int *array, int n)
{
    int i, j, temp;
    for(i = 0; i < n; i++) {
        j = i - 1;
        temp = array[i];
        while((j >= 0) && (array[j] > temp)) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
}