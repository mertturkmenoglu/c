/*3) Tum elemanlari 0 
 *olan NxN tipi A kare 
 *matrisi olusturma
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
	
	/*Assignment*/
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			*(matrix + i*col* j) = 0;
		}
	}
	
	printf("\n");
	
	/*Print matrix*/
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			printf("%d", *(matrix + i*col* j));
		}
		printf("\n");
	}
	
	/*Frees the space allocated in the memory pointed by matrix*/
	free(matrix);
	
	/*Indicates successful termination*/
	return 0;
		
}/*Main function ends*/
