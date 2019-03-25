#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	
	double (*fp)();

	fp = sin;

	printf("%lf", (*fp)(M_PI/2));

	return 0;
}





