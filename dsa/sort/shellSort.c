void shellSort(int *array,int n)
{
    int i, j, h, temp;

    for (h = n/2; h > 0; h /= 2) {
        for (i = h; i < n; i++) {
            temp = array[i];
            for (j = i; (j >= h) && (array[j - h] > temp); j -= h)
                array[j] = array[j - h]; 
            array[j] = temp;
        }
    }
}