/*9) NxM A matrisinin 
 *transpozesini alan 
 *program
 */
 
#include <stdio.h>
#include <stdlib.h>

void printmtr(int* , int, int);

int main(){
	
	int i, j, row, col, *mtr;
	
	printf("Please enter row number: ");
	scanf("%d", &row);
	
	printf("\nPlease enter column number: ");
	scanf("%d", &col);

	mtr = (int*) malloc(col* row * sizeof(int));
	
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			printf("\nA[%d][%d]: ", i+1, j+1);
			scanf("%d", (mtr+j*col+i));
		}
	}
	
	printmtr(mtr, row, col);
	
	free(mtr);
	return 0;
}

void printmtr(int* mtr, int row, int col){
	
	int i, j;
	printf("\n");
	
	for(i=0; i<col; i++){
		for(j=0; j<row; j++){
				printf("%4d", *(mtr+i*col+j));
		}
		printf("\n");
	}
	
}
