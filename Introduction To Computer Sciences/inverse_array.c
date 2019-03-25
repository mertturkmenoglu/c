/*7) N elemanli bir
 *A dizisinin elemanlarini
 *ters sirada b dizisine 
 *yerlestiren program
 */
 
#include <stdio.h>
#include <stdlib.h>

/*Main function starts*/
int main(){
	
	/*Variable declarations
	 *@len
	 */
	int len, *arrayA, *arrayB, i;
	
	printf("Please enter array length: ");
	scanf("%d", &len);
	
	arrayA = (int*) malloc(len * sizeof(int));
	arrayB = (int*) malloc(len * sizeof(int));
	
	if((arrayA == NULL)||(arrayB == NULL)){
		printf("\nError! Memory not allocated\n");
		exit(0);
	}
	
	for(i=0; i<len; i++){
		printf("\nPlease enter A[%d]: ", i+1);
		scanf("%d", arrayA+i);
	}
	
	for(i=0; i<len; i++){
		*(arrayB+len-i-1) = *(arrayA+i);
	}
	
	for(i=0; i<len; i++)
		printf("\nB[%d]: %d", i+1, *(arrayB+i));
		
	free(arrayA);
	free(arrayB);
	
	return 0;
}
