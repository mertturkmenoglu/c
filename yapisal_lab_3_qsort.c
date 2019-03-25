#include <stdio.h>
#include <stdlib.h>

typedef struct {

    int year;
    char id[11];
    char location[50];

}STUDENT;

int compare(const void* a, const void* b) {

    return ( *(int*)a - *(int*)b );

}

int main(int argc, char const *argv[]) {
    
    STUDENT *array;
    int numberOfStudents, i;

    printf("Please enter the number of the students: ");
    scanf("%d", &numberOfStudents);

    array = (STUDENT*) malloc(numberOfStudents * sizeof(STUDENT));

    for(i=0; i<numberOfStudents; i++) {

        printf("\n----\n%d-th student", i+1);
        printf("\nBirth year: ");
        scanf("%d", &array[i].year);
        printf("\nID: ");
        scanf("%s", array[i].id);
        printf("\nLocation: ");
        scanf("%s", array[i].location);

    }

    qsort(array, numberOfStudents, sizeof(STUDENT), compare);
    printf("\n\n\n");

    for(i=0; i<numberOfStudents; i++) {

        printf("\n----\n%d-th student", i+1);
        printf("\nBirth year: %d", array[i].year);
        printf("\nID: %s", array[i].id);
        printf("\nLocation: %s", array[i].location);

    }

    free(array);
    printf("\n");
    system("PAUSE");

    return 0;

}

