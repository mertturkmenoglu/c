#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *function(void *value) {
    int *number;
    printf("Second thread\n");

    number = (int*) value;

    printf("Value: %d\n", *number);

    return NULL;
}

int main() {
    int n;
    pthread_t thread;
    
    printf("First thread\n");
    n = 1000;
    pthread_create(&thread, NULL, function, &n);

    pthread_join(thread, NULL);

    return 0;
}