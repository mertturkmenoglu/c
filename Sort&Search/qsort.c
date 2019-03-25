#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void* a, const void* b) {

    return ( *(int*)a - *(int*)b );

}

int main(void) {

    srand(time(NULL));
    int *array, len, i;

    printf("\nArray size: ");
    scanf("%d", &len);

    array = (int*) malloc(len * sizeof(int));
    printf("\n");

    for(i=0; i<len; i++) {

        array[i] = rand() % len;
        printf("%d\t", array[i]);

    }

    qsort(array, len, sizeof(int), compare);

    printf("\n");
    
    for(i=0; i<len; i++)
        printf("%d\t", array[i]);

    free(array);
    array = NULL;
    printf("\n");
    return 0;

}