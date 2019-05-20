#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i, searched, *array, len;
	
	printf("Array length: ");
	scanf("%d", &len);
	
	array = (int*) malloc(len*sizeof(int));
	
	printf("\nSearched element: ");
	scanf("%d", &searched);
	
	for(i=0; i<len; i++){
		printf("\n%d -th element: ", i+1);
		scanf("%d", array+i);
	}
	i=-1;
	while((*(array+(++i))!=searched)&&(i<len)){}

	if(i != len)
		printf("\nFound at %d", i+1);
	else
		printf("\nCan not find");
	
	free(array);
	return 0;
}
