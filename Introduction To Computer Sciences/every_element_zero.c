/*3) T�m elemanlar� 0 olan bir A dizisi olu�turmak*/

#include <stdio.h>
#define SIZE 100

int main(){
	
	int n, i, array[SIZE];
	
	printf("Array length: ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
		array[i] = 0;
		
	for(i=0; i<n; i++)
		printf("\n%d", array[i]);

	return 0;
	
}
