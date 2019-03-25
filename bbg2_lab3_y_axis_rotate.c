/*BBG-2 LAB-3
 *Verilen matrisi y eksenine
 *gore rotate eden program
 *memory management yok
 */
 
#include <stdio.h>
#define SIZE 100

void write(int [SIZE][SIZE], int, int);
void rotate(int [SIZE][SIZE], int, int);

int main(){

	int mtr[SIZE][SIZE], i, j, row, col;
	
	printf("Please enter row number: ");
	scanf("%d", &row);
	
	printf("\nPlease enter column number: ");
	scanf("%d", &col);
	
	for(i=0; i<row; i++){
		for(j=0; j<col; j++)
			mtr[i][j] = i*col+j;
	}
	
	printf("\nOriginal matrix:\n");
	write(mtr, row, col);
	rotate(mtr, row, col);
	printf("\nRotated matrix:\n");
	write(mtr, row, col);
	
	return 0;

}

void write(int mtr[SIZE][SIZE], int row, int col){
	
	int i, j;
	for(i=0; i<row; i++){
		for(j=0; j<col; j++)
			printf("%4d", mtr[i][j]);
		printf("\n");
	}
	
}

void rotate(int mtr[SIZE][SIZE], int row, int col){
	
	int i, j, temp;
	
	for(i=0; i<row; i++){
		for(j=0; j<(col/2); j++){
			temp = mtr[i][j];
			mtr[i][j] = mtr[i][col-j-1];
			mtr[i][col-j-1] = temp;
		}
	}
	
}
