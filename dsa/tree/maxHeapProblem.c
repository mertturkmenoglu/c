#include <Boolean.h>

// It is known that a number in a max heap tree
// is placed incorrectly. This function finds the location.
// If there is no incorrectly placed number returns -1
int findIncorrect(int N, int HEAP[N]) {
    Boolean flag = FALSE;
    Boolean endFlag = FALSE;
    int i = 0;

    while (!flag) {
        if (2 * i + 2 < N) {
            if ((HEAP[i] < HEAP[2*i+1]) || (HEAP[i] < HEAP[2*i+2])) {
                flag = TRUE;
            } else {
                i++;
            }
        } else {
            if (2 * i + 1 < N) {
                if (HEAP[i] < HEAP[2*i+1]) {
                    flag = TRUE;
                } else {
                    i++;
                }
            } else {
                endFlag = TRUE;
            }
        }
    }
    
    if (endFlag == TRUE)
        return -1;
    
    if (flag == 1) {
        return i;
    }
}