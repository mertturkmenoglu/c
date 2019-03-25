/*
44) n sayıdan en buyuk cift tamsayıyı bulan program
*/

#include <stdio.h>
#define SIZE 100
int main(){

	int array[SIZE], i, max, n;

	printf("Please enter the array size: ");
	scanf("%d", &n);

	for(i=0; i<n; i++){
		printf("Please enter %d -th element: ", i+1);
		scanf("%d", &array[i]);
	}

	max= -1;
	
	for(i=0; i<n; i++){
		if((array[i]%2 == 0)&&(array[i]>max))
			max = array[i];
	}

	if(max != -1)
		printf("\nMaximum even number: %d", max);
	else
		printf("\nThere is no even number");

	return 0;
}