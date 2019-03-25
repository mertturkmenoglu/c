/*
 *3) Write a function that checks 
 *whether an element occurs in a list.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	short int* array;
	short int i, len, element;
	
	printf("Length of the array: ");
	scanf("%hd", &len);
	
	printf("\nElement: ");
	scanf("%hd", &element);
	
	array = malloc(len * sizeof(short int));
	
	for(i=0; i<len; i++){
		
		printf("\nA[%hd]: ", i+1);
		scanf("%hd", (array+i)); 
		
	}
	
	i=0;
	
	while((element != *(array+i))&&(i++<len));
	
	if(i == len+1)
		printf("\nNo occurance");
	else
		printf("\nAt: %hd", i+1);
	
	free(array);
	
	return 0;
	
}
