/*Dividers of N*/
#include <stdio.h>

int main(void) {
	
	int i = 1, n;

	printf("N:");
	scanf("%d", &n);
	printf("\n1");
	
	while (++i < n) {
		if( !(n % i) )
			printf("+%d", i);
	}
	
	return 0;
	
}
