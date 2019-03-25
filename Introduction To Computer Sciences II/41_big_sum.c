/*
 *41) Big Sum: Take two numbers of 20 digits 
 *and print the sum of those two numbers.
 */
 
#include <stdio.h>

int main(void){
	
	static short int array1[20], array2[20];
	short int overflow = 0;
	short int i;
	
	for(i=0; i<20; i++){
		
		do{
			printf("First number: %d -th digit: ", i+1);
			scanf("%hd", &array1[i]);
		}while((array1[i]<0)||(array1[i]>9));
		
		do{
			printf("\nSecond number: %d -th digit: ", i+1);
			scanf("%hd", &array2[i]);
		}while((array2[i]<0)||(array2[i]>9));
		
		printf("\n"); 
		
	}
	
	for(i=0; i<20; i++)
		printf("%hd", array1[i]);
	printf("\n");
	for(i=0; i<20; i++)
		printf("%hd", array2[i]);
	
	for(i=19; i >= 0; i--){
		array1[i] += array2[i] + overflow;
		if(overflow != 0)
			overflow--;
		if(array1[i]>9){
			overflow++;
			array1[i] -= 10;
		}
	}
	
	printf("\n");
	for(i=0; i<20; i++){
		printf("%hd", array1[i]);
	}
	
	return 0;
	
}
