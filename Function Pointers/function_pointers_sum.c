#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fsquare(int);
int fsum(int);
void sum(int*, int, int (*fp)());

int main(void){

	srand(time(NULL));

	int (*fp)();
	int* array;
	int len,i,choice;

	printf("Length of the array: ");
	scanf("%d", &len);

	array = (int*) malloc(len*sizeof(int));

	for(i=0; i<len; i++){
		array[i] = rand()%10;
		printf("%d\t", array[i]);
	}

	printf("\nFor sum 0, for square sum 1: \n");
	scanf("%d", &choice);

	if(choice)
		fp = fsquare;
	else
		fp = fsum;

	sum(array, len, fp);

	printf("\n\n\n-------\n");
	return 0;
}

int fsquare(int x){
	return x*x;
}

int fsum(int x){
	return x;
}

void sum(int* array, int len, int (*fp)()){

	int sum = 0;
	int i;

	for(i=0; i<len; i++)
		sum += (*fp)(array[i]);
	printf("\n%d\n", sum);
	
}



