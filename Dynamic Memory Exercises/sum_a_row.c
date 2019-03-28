/*7) NxN A matrisinin 
 *istenen satirinin
 *elemanlarinin toplamini
 *bulan program
 */
 
#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i, j, *mtr, sum = 0, row, col;
	
	/*Read row and column numbers*/
	
	printf("Please enter row number: ");
	scanf("%d", &row);
	
	printf("\nPlease enter column number: ");
	scanf("%d", &col);

	/*Memory allocation*/
	
	mtr = (int*) malloc(row * col * sizeof(int));
	
	/*Error handling*/
	
	if(mtr == NULL){
		printf("\nError! Memory is not allocated\n");
		exit(0);
	}
	
	/*Read matrix*/
	
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			printf("\nA[%d][%d]: ", i+1, j+1);
			scanf("%d", (mtr+i*col+j));
		}
	}
	
	printf("\nWhich row do you want to sum?\n");
	scanf("%d", &row);
	row--;
	
	for(i=0; i<col; i++)
		sum += *(mtr+row*col+i);
		
	printf("\nSum: %d\n", sum);
	
	free(mtr);
	
	/*Indicates successful termination*/
	return 0;
	
}
