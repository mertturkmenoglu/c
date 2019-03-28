/*Ilk n tane 2^(2^n) + 1 sayisini bulma*/
#include <stdio.h>
#include <math.h>

int main(void){
	
	int i, n;
	
	printf("N: ");
	scanf("%d", &n);
	printf("\n");
	
	for(i=1; i<=n; i++)
		printf("%.0f ", pow(2, pow(2,i))+1);		
	
	return 0;
}
