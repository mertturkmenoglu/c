/*5) NxN A matrisinin 
 *izini hesaplayan program
 */
 
#include <stdio.h>
#include <stdlib.h>

/*Main function starts*/
int main(){
	
	/*Variable declarations*/
	int i, j, row, col, *mtrA, izA = 0;
	
	/*Read row and column numbers*/
	printf("Please enter row number: ");
	scanf("%d", &row);
	printf("\nPlease enter column number: ");
	scanf("%d", &col);
	
	/*Memory allocation*/
	mtrA = (int*) malloc(row * col * sizeof(int));
	
	/*Error handling*/
	if(mtrA == NULL){
		printf("\nError! Memory is not allocated\n");
		exit(0);
	}
	
	/*Read matrix*/
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			printf("\nA[%d][%d]: ", i+1, j+1);
			scanf("%d", (mtrA + i*col + j));
		}
	}
	
	/*Compute izA*/
	for(i=0; i<row; i++){
		izA += *(mtrA + i*col + i);
	}
	
	/*Print izA*/
	printf("\nizA: %d", izA);
	
	/*Frees space allocated in memory pointed by mtrA*/
	free(mtrA);
	
	/*Indicates successful termination*/
	return 0;
	
}/*Main function ends*/
