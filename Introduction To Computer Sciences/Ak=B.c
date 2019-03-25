/*6) N elemanlı bir A 
 *dizisini k katsayisi
 *ile carpip B dizisini 
 *olusturan program
 */
 
#include <stdio.h>
#include <stdlib.h>

/*Main function starts*/
int main(){
	
	int i, len, k, *arrayA;
	
	/*Read array length*/
	printf("Please enter array length: ");
	scanf("%d", &len);
	
	/*Read factor value*/
	printf("\nPlease enter factor k: ");
	scanf("%d", &k);
	
	/*Memory allocation*/
	arrayA = (int*) malloc(len * sizeof(int));
	
	/*Error message*/
	if(arrayA == NULL){
		printf("\nError! Memory not allocated\n");
		exit(0);
	}
	
	/*Read array and multiply with value k*/
	for(i=0; i<len; i++){
		printf("\nPlease enter %d -th element: ", i+1);
		scanf("%d", arrayA+i);
		*(arrayA+i) *= k;
	}
	
	printf("\n");
	
	/*Print final array*/
	for(i=0; i<len; i++)
		printf("A[%d]: %d\t", i+1, *(arrayA+i));
	
	free(arrayA);
	
	/*Indicates successful termination*/	
	return 0;
	
}/*Main function ends*/

