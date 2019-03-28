/*3) Tum elemanlari 
 *0 olan bir A 
 *dizisi olusturmak
 */
 
#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i, len, *array;
	
	
	printf("Please enter array length: ");
	scanf("%d", &len);
	
	array = (int*) malloc(len * sizeof(int));
	
	for(i=0; i<len; i++)
		*(array+i) = 0;
		
	printf("\n");
	
	for(i=0; i<len; i++)
		printf("%2d", *(array+i));
	
	free(array);
	return 0;
	
}

