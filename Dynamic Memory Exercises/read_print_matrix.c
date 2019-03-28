/*1) NxN matrise eleman okuma
 *2) NxN matrisi ekrana yazdirma
 */
 
#include <stdio.h>
#include <stdlib.h>

/*Main function starts*/
int main(){
	
	/*Variable declarations*/
	int i, j, row, col, *matrix;
	
	/*Read row and column numbers*/
	printf("Please enter row number: ");
	scanf("%d", &row);
	
	printf("\nPlease enter column number: ");
	scanf("%d", &col);
	
	/*Memory allocation*/
	matrix = (int*) malloc(row * col * sizeof(int));
	
	/*Error handling*/
	if(matrix == NULL){
		printf("\nError! Memory is not allocated\n");
		exit(0);
	}
	
	/*Read matrix*/
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			printf("\nA[%d][%d]: ", i+1, j+1);
			scanf("%d", (matrix + i*col + j));
		}
	}
	
	printf("\n");
	
	/*Print matrix*/
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			printf("%d", *(matrix + i*col+ j));
		}
		printf("\n");
	}
	
	/*Frees the memory allocated by pointer matrix*/
	free(matrix);
	
	/*Indicates succesful termination*/
	return 0;
	
}
