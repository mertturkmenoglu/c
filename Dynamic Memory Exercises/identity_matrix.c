/*10) Klavyeden girilen 
 *N sayisina gore NxN 
 *birim matris olusturan 
 *program
 */
 
#include <stdio.h>
#include <stdlib.h>

void printmtr(int*, int, int);

int main(){
	
	int size, *mtr, i, j;
	
	printf("Please enter the matrix size: ");
	scanf("%d", &size);
	
	mtr = (int*) malloc(size * size * sizeof(int));
	
	for(i=0; i<size; i++){
		for(j=0; j<size; j++)
			*(mtr+i*size+j) = (i == j) ? 1 : 0;	
	}
	
	printmtr(mtr, size, size);
	
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
