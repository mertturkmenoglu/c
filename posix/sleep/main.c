#include <unistd.h>
#include <stdio.h>

int main() {
    int i;

    for (i = 0; i < 5; i++) {
        printf("%d\n", i);
        sleep(3);
    }

    return 0;
}