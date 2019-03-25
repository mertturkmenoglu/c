/*5) N elemanlı A ve B 
dizilerini toplayarak C 
dizisini olusturan program
*/

#include <stdio.h>
#include <stdlib.h>

/*Main function starts*/
int main(){
	
	int len, i, *arrayA, *arrayB, *arrayC;
	
	/*Read arrays length*/
	printf("Please enter arrays length: ");
	scanf("%d", &len);
	
	
	/*Memory allocation of arrays*/
	arrayA = (int*) malloc(len * sizeof(int)); 
	arrayB = (int*) malloc(len * sizeof(int));
	arrayC = (int*) malloc(len * sizeof(int));
	
	/*Error message*/
	if((arrayA == NULL)||(arrayB == NULL)||(arrayC == NULL)){
		printf("\nError! Memory not allocated\n");
		exit(0);
	}
	
	/*Read arrays and calculate sum*/
	for(i=0; i<len; i++){
		printf("\nPlease enter A[%d]: ", i+1);
		scanf("%d", arrayA+i);
		printf("\nPlease enter B[%d]: ", i+1);
		scanf("%d", arrayB+i);
		*(arrayC+i) = *(arrayA+i) + *(arrayB+i);
	}
	
	printf("\n\n");
	
	/*Print array C*/
	for(i=0; i<len; i++){
		printf("C[%d]: %d\n", i+1, *(arrayC+i));
	}
	
	free(arrayA);
	free(arrayB);
	free(arrayC);
	
	/*Indicates successful termination*/
	return 0;
	
}/*Main function ends*/
