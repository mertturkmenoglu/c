#include <stdio.h>
#include "search.h"

void horspool(int M, int R, int pattern[M], int right[R]) {
    int i;
    for(i = 0; i < R; i++) {
        right[i] = -1;
    }
    for(i = 0; i < M; i++) {
        right[pattern[i] - 'A'] = i;
    }
}

int search(int N, int text[N], int M, int pattern[M], int R, int right[R]) {
    int i = 0;
    int found = 0;

    while ((i <= N - M) && !found) {
        int j = M - 1;
        while ((j >= 0) && (pattern[j] == text[i+j]))
            j--;
        if (j >= 0) {
            int skip = j - right[text[i+j] - 'A'];
            if (skip < 0)
                i++;
            else
                i += skip;
        } else {
            found = 1;
        }
    }

    return (found == 1) ? i : -1;
}