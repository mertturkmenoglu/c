/*Inplace matrix transpoze*/

#include <stdio.h>
#include <time.h>
#define SIZE 100
#include <stdlib.h>

void printmtr(int mtr[][SIZE], int row, int col);

int main() {
	
	srand( time(NULL) );
	int i, j, row, col;
	static int mtr[SIZE][SIZE];
	
	printf("Row: ");
	scanf("%d", &row);
	
	printf("\nColumn: ");
	scanf("%d", &col);
	printf("\n");
	
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			mtr[i][j] = rand()%10+1;
		}
	}
	
	printmtr(mtr, row, col);
	
	printf("\n-----------------\n");
	
	printmtr(mtr, row, col );
	
	return 0;
	
}

void printmtr(int mtr[][SIZE], int row, int col){
	
	int i, j;
	
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
				printf("%2d", mtr[i][j]);
		}	
		printf("\n");	
	}
	
}
