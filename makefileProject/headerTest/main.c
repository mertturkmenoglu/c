#include "../../include/array.h"
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int n = 10;
    int *array = (int*) malloc(n * sizeof(n));

    for(int i = 0; i < n; i++)
        array[i] = rand() % 50;

    printArray(array, n);
    sort(array, n);
    printArray(array, n);
    
    free(array);
    return 0;
}