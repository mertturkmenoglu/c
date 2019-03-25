#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	
	double (*fp)();
	fp = sin;
	
	printf("%lf", (*fp)(1.0/3));
	
	return 0;
	
}
