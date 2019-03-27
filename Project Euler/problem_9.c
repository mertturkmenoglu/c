/*Problem 9*/
#include <stdio.h>
#include <math.h>

int main(){
	
	int a,b;
	double c;
	
	for(a=1; a<1000; a++){
		for(b=a+1; b<1000; b++){
			c= sqrt(a*a+b*b);
			if(a+b+c == 1000)
				printf("\n%d--%d--%f\n",a,b,c);
		}
	}
	
	return 0;
}
