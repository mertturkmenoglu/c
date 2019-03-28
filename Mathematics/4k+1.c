/*4k+1*/
#include <stdio.h>

int main(){
	
	int i, k;
	
	printf("K: ");
	scanf("%d", &k);
	
	printf("\n");
	
	for(i=0; i<=k; i++)
		printf(" %d ", 4*i+1);
	
	return 0;
	
}
