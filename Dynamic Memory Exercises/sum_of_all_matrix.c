/*8) NxN A matrisinin 
 *tum elemanlarinin
 *toplamini bulan program
 */
 
#include <stdio.h>
#include <stdlib.h>

/*Main function starts*/
int main(){
	
	/*Variable declarations*/
	int i, j, row, col, *mtr, sum = 0;
	
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
			sum += *(mtr+i*col+j);
		}
	}
	
	printf("\nSum: %d", sum);
	
	free(mtr);
	
	return 0;

}
