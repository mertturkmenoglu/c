/*BBG-2 LAB-3
 *Verilen matrisi x eksenine
 *gore rotate eden program
 *memory management var
 */
 
#include <stdio.h>
#include <stdlib.h>

void write(int *, int, int);
void rotate(int *, int, int);

int main(){

	int *mtr, i, j, row, col;
	
	printf("Please enter row number: ");
	scanf("%d", &row);
	
	printf("\nPlease enter column number: ");
	scanf("%d", &col);
	
	mtr = (int*) malloc(row*col*sizeof(int));
	
	if(mtr == NULL){
		printf("\nError! Memory is not allocated\n");
		exit(0);
	}
	
	for(i=0; i<row; i++){
		for(j=0; j<col; j++)
			*(mtr+i*col+j) = i*col+j;
	}
	
	printf("\nOriginal matrix:\n");
	write(mtr, row, col);
	rotate(mtr, row, col);
	printf("\nRotated matrix:\n");
	write(mtr, row, col);
	free(mtr);
	return 0;

}

void write(int* mtr, int row, int col){
	
	int i, j;
	for(i=0; i<row; i++){
		for(j=0; j<col; j++)
			printf("%4d", *(mtr+i*col+j));
		printf("\n");
	}
	
}

void rotate(int* mtr, int row, int col){
	
	int i, j, temp;
	
	for(i=0; i<(row/2); i++){
		for(j=0; j<col; j++){
			temp = *(mtr+i*col+j);
			*(mtr+i*col+j) = *(mtr+(row-1-i)*col+j);
			*(mtr+(row-1-i)*col+j) = temp;
		}
	}
	
}
