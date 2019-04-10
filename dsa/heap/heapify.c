void heapify(int *array, int n, int i)
{ 
    int max = i; // Initialize max as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    // If left child is larger than root
    if (left < n && array[left] > array[max])
        max = left; 

    // If right child is larger than max so far
    if (right < n && array[right] > array[max])
        max = right; 

    // If max is not root
    if (max != i) {
        temp = array[i];
        array[i] = array[max];
        array[max] = temp;

        // Heapify recursively
        heapify(array, n, max);
    }
}