/*Passing dynamic memory
 *matrix to function
 *test
 */
 
#include <stdio.h>
#include <stdlib.h>

/*Function prototypes*/
void ffread(int, int, int*);
void fprint(int, int, int*);

/*Main function starts*/
int main(){
	
	/*Variable declarations*/
	int row, col, *mtrA;
	
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
	
	ffread(row, col, mtrA);
	fprint(row, col, mtrA);
	
	free(mtrA);
	return 0;
}

void ffread(int row, int col, int *mtrA){
	
	int i, j;
	
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			printf("\nA[%d][%d]: ", i+1, j+1);
			scanf("%d", (mtrA + i*col + j));
		}
	}
}

void fprint(int row, int col, int *mtrA){
	
	int i, j;
	printf("\n\n");
	for(i=0; i<row; i++){
		for(j=0; j<col; j++)
			printf("%d", *(mtrA + i*col + j));
		printf("\n");
	}
	
}
