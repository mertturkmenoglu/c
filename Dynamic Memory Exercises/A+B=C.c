/*4) Klavyeden girilen 
 *NxN tipindeki A ve B 
 *matrislerini toplayan 
 *(C) program
 */
 
#include <stdio.h>
#include <stdlib.h>

/*Main function starts*/
int main(){
	
	/*Variable declarations*/
	int i, j, row, col, *mtrA, *mtrB, *mtrC;
	
	/*Read row and column numbers*/
	printf("Please enter row number: ");
	scanf("%d", &row);
	
	printf("\nPlease enter column number: ");
	scanf("%d", &col);
	
	/*Memory allocation*/
	mtrA = (int*) malloc(row * col * sizeof(int));
	mtrB = (int*) malloc(row * col * sizeof(int));
	mtrC = (int*) malloc(row * col * sizeof(int));
	
	/*Error handling*/
	if((mtrA == NULL)||(mtrB == NULL)||(mtrC == NULL)){
		printf("\nError! Memory is not allocated\n");
		exit(0);
	}
	
	/*Read matrices*/
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			
			printf("\nA[%d][%d]: ", i+1, j+1);
			scanf("%d", (mtrA + i*col + j));
			
			printf("\nB[%d][%d]: ", i+1, j+1);
			scanf("%d", (mtrB + i*col + j));
			
			*(mtrC + i*col + j) = *(mtrA + i*col + j) + *(mtrB + i*col + j);
			
		}
	}
	
	printf("\n");
	
	/*Print C matrix*/
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			printf("%d\t", *(mtrC + i*col + j));
		}
		printf("\n");
	}
	
	/*Frees the space allocated in memory pointed by mtrA, mtrB, mtrC*/
	free(mtrA);
	free(mtrB);
	free(mtrC);
	
	/*Indicates successful termination*/
	return 0;
	
}/*Main function ends*/
