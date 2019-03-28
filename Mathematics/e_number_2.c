/*e number*/
#include <stdio.h>
#include <math.h>

int main(void) {
	
	int i, n, f = 1;
	float x;
	double sonuc = 1;
	
	printf("x: ");
	scanf("%f", &x);
	printf("\nn:");
	scanf("%d", &n);

	for(i = 1; i <= n; i++){
		f *= i;
		sonuc += pow(x,i) / f;
	
	}
	
	printf("\n%lf", sonuc);
	
	return 0;
	
}

int faktoriyel(int n){
	
	int i, sonuc=1;
	if(n <2)
		return 1;
	for(i=n; i>1; i--)
		sonuc *= n;
	
	return sonuc;
	
}
