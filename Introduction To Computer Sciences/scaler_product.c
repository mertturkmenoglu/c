/*9) n elemanli a ve b 
 *dizilerini skaler 
 *carpimini hesaplayan 
 *program
 *(a1.b1+a2.b2+....)
 */
 
#include <stdio.h>
#include <stdlib.h>

/*Main function starts*/
int main(){
	
	/*Variable declarations*/
	int len, *arrayA, *arrayB, sum=0, i; 
	
	printf("Please enter array length: ");
	scanf("%d", &len);
	
	arrayA = (int*) malloc(len * sizeof(int));
	arrayB = (int*) malloc(len * sizeof(int));
	
	if((arrayA == NULL)||(arrayB == NULL)){
		printf("\nError! Memory not allocated\n");
		exit(0);
	}
	
	/*Read arrays and operate*/
	for(i=0; i<len; i++){
		
		printf("\nA[%d]: ", i+1);
		scanf("%d", arrayA+i);
		
		printf("\nB[%d]: ", i+1);
		scanf("%d", arrayB+i);
		
		sum += (*(arrayA+i))  *  (*(arrayB+i));
		
	}
	
	printf("\nA[].B[]= %d", sum);
	
	free(arrayA);
	free(arrayB);

	return 0;
	
}
