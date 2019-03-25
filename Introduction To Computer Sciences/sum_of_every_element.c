/*4) N elemanli A dizisinin 
tum elemanlarini toplayan 
program*/

#include <stdio.h>
#define SIZE 100

int main(){
	
	int i, n, sum=0, array[SIZE];
	
	printf("Array length: ");
	scanf("%d", n);
	
	for(i=0; i<n; i++){
		printf("Please enter %d -th element: ");
		scanf("%d", &array[i]);
	}
	
	for(i=0; i<n; i++)
		sum += array[i];
	
	printf("\nSum: %d", sum);
	
	return 0;
}
