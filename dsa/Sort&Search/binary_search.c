#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int left, right, middle, flag, len, i, searched, *array;
	
	printf("Searched: ");
	scanf("%d", &searched);
	
	printf("\nArray length: ");
	scanf("%d", &len);
	
	array = (int*) malloc(len*sizeof(int));
	
	for(i=0; i<len; i++){
		printf("\n%d-th element: ", i+1);
		scanf("%d", array+i);
	}	
	
	left = 0;
	right = len -1;
	
	while( (left<=right)&&(flag != 1) ){
		
		middle = (left+right)/2;
		if(searched < *(array+middle) )
			right = middle -1;
		else if(searched > *(array+middle) )
				left = middle + 1;
			else
				flag = 1;
		
	}
	
	if(flag == 1)
		printf("\n%d found at %d", searched, middle+1);
	else
		printf("\nCan not found");
	

	free(array);
	return 0;
	
}
