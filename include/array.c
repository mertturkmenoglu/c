#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include "../dsa/sort/dsasort.h"
void printArray(int *array, int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d\t", array[i]);
    printf("\n");
}

void sort(int *array, int n)
{
    // Selection sort
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

void copyArray(int *dest, int *src, int n)
{
    int i;
    for(i = 0; i < n; i++)
        dest[i] = src[i];
}