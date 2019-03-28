/*Matrisin istenilen satir ve sutununu yer degistiren program*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printmtr(int* , int);
void swapmtr(int* mtr, int row, int col, int size);

/*Main function starts*/
int main(){
	
	/*Random function seeds. Current CPU time*/
	srand( time(NULL) );
	
	int i, j, size, row, col, *mtr;
	
	printf("Please enter your matrix size: ");
	scanf("%d", &size);
	
	/*Dynamic memory allocation*/
	mtr = (int*) malloc(size * size * sizeof(int));
	
	/*Error handling*/
	if(mtr == NULL){
		printf("\nError! Memory is not allocated\n");
		exit(0);
	}
	
	for(i=0; i<size; i++){
		for(j=0; j<size; j++)
			*(mtr+i*size+j) = rand()%10;
	}
	
	printmtr(mtr, size);
	
	printf("\nWhich row and column do you want to swap?\n");
	printf("Row: ");
	scanf("%d", &row);
	printf("\nColumn: ");
	scanf("%d", &col);
	
	row--;
	col--;
	
	swapmtr(mtr, size, row, col);
	
	printmtr(mtr, size);
	
	free(mtr);
	
	return 0;
	
}/*Main function ends*/


/*printmtr function starts*/
void printmtr(int* mtr, int size){
	
	int i, j;
	
	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			printf("%2d", *(mtr+i*size+j));
		}
		printf("\n");
	}
	
}/*printmtr function ends*/

void swapmtr(int* mtr, int row, int col, int size){
	
	int temp, i;
	
	for(i=0; i<size; i++){
		temp = *(mtr+i*size+col);
		*(mtr+i*size+col) = *(mtr+row*size+i);
		*(mtr+row*size+i) = temp;
	}
		
}