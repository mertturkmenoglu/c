/*4) N elemanli
 *A dizisinin 
 *tum elemanlarini
 *toplayan program
 */
 
#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int sum = 0, i, len, *array;
	
	printf("Length: ");
	scanf("%d", &len);
	
	array = (int*) malloc(len*sizeof(int));
	
	for(i=0; i<len; i++){
		printf("\nA[%d]: ", i+1);
		scanf("%d", array+i);
		sum += *(array+i);
	}
	
	printf("\nSum: %d", sum);
	
	free(array);
	return 0; 
}
