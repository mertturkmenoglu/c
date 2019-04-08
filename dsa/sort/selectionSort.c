#include "dsasort.h"

void selectionSort(int *array, int n)
{
    int i, j, location, min;
    for(i = 0; i < n - 1; i++) {
        location = i;
        min = array[i];
        for(j = i + 1; j < n; j++) {
            if(array[j] < min) {
                min = array[j];
                location = j;
            }
        }
        array[location] = array[i];
        array[i] = min;
    }
}