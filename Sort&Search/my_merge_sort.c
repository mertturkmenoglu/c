#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void readArray(int*, int);
void printArray(int*, int);
void mergeSort(int* array, int left, int right);
void merge(int*, int, int, int);

int main(void) {

   srand(time(NULL));

   int* array;
   int array_size;

   printf("Please enter array size: ");
   scanf("%d", &array_size);

   array = (int*) malloc(array_size * sizeof(int));

   readArray(array, array_size);
   printf("Given array: \n");
   printArray(array, array_size);
   mergeSort(array, 0, array_size-1);
   printf("\nSorted array: \n");
   printArray(array, array_size);

   free(array);
   printf("\n");
   return 0;

}



void readArray(int* array, int array_size) {

   int i;

   for(i = 0; i < array_size; i++) {
      //printf("Array[%d]: ", i+1);
      *(array+i) = rand() % array_size;
   }

}



void printArray(int* array, int array_size) {

   int i;

   for(i = 0; i < array_size; i++)
      printf("%d\t", *(array+i));

}



void mergeSort(int* array, int left, int right) {

   if(left < right) {

      int middle = left + (right-left) / 2;

      mergeSort(array, left, middle);
      mergeSort(array, middle+1, right);
      merge(array, left, right, middle);

   }

}



void merge(int* array, int left, int right, int middle) {

   int i, j, k;

   int size_left = middle - left + 1;
   int size_right = right - middle;

   int array_left[size_left], array_right[size_right];

   for(i = 0; i < size_left; i++)
      array_left[i] = array[left + i];
   for(i = 0; i < size_right; i++)
      array_right[i] = array[middle + i + 1];

   i = 0;
   j = 0;
   k = left;

   while(i < size_left && j < size_right) {

      if(array_left[i] <= array_right[j]) {

         array[k] = array_left[i];
         i++;

      } else {

         array[k] = array_right[j];
         j++;

      }

      k++;

   }

   while(i < size_left) {

      array[k] = array_left[i];
      i++;
      k++;

   }

   while(j < size_right) {

      array[k] = array_right[j];
      j++;
      k++;
   }

}
