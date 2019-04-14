#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    
    int n = 10;
    int i;
    int *array;

    array = (int*) malloc(n * sizeof(int));

    for(i=0; i<n; i++)
        array[i] = i+1;

    for(i=0; i<n; i++)
        printf("A[%d]: %d\t", i+1, array[i]);

    printf("\n\n\n");

    for(i=0; i<n; i++)
        printf("A[%d]: %d\t", i+1, i[array]);

    free(array);

    return 0;
}
