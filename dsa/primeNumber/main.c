/**
 * Data Structures and Algorithms
 * Prime Number Finder
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int *array;
    int i, j;
    // n is just an arbitrary number.
    // But I assumed it is bigger enough to not give me 
    // a problem. I did not add controls because
    // I did not want to focus on other things.
    int n = 36;
    int sqrtN = (int)sqrt(n);   // Square root of n

    /* Dynamic memory allocation
     * Extra element allocation is just for setting
     * index-element correspondence.
     */
    array = (int*) malloc((n+1) * sizeof(int));

    // All numbers considered as prime
    // at the begining
    // 0 for prime numbers
    // 1 for non-prime numbers
    for(i = 1; i <= n; i++)
         array[i] = 0;

    // Number 2 is prime
    array[2] = 0;

    // Getting rid of the all other even numbers
    for(i = 4; i <= n; i += 2)
        array[i] = 1;

    // Starting from 3, check every odd number if it is
    // marked as prime. If it is prime then starting from
    // it is square number, mark that number as non-prime
    // and increase index by i. Do this in given range.
    for(i = 3; i <= sqrtN; i += 2) {
        if(array[i] == 0) {
            for(j = (i * i); j <= n; j += i)
                array[j] = 1;
        }
    }

    // Print prime numbers up to n
    for(i = 2; i < n; i++) {
        if(array[i] == 0) {
            printf("%d\t", i);
        }
    }

    printf("\n");
    free(array);
    return 0;
}