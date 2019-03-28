/*e number*/
#include <stdio.h>
#include <math.h>

int main(void) {
	
	double x, n, sonuc;
	
	printf("x: ");
	scanf("%lf", &x);
	
	printf("\nn: ");
	scanf("%lf", &n);
	
	sonuc = pow( 1+(x/n), n);
	
	printf("\n\n%lf", sonuc);
	
	return 0;
	
}
