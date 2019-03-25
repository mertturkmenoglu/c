#include <stdio.h>

void swap(int *a, int *b)
{
    if (a != b)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}
void swapFloat(float *a, float *b)
{
    swap((int*)a, (int*)b);
}

int main()
{
    float a=3.5f, b=457.0f;
    swapFloat(&a, &b);
    printf("a: %f\nb: %f", a, b);
    return 0;
}
