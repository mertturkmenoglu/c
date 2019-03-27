/*Problem 10*/
#include <stdio.h>
#include <math.h>
int main(){
	
	int i;
	long int sum=17;
	for(i=9; i<2000000; i+=2){
		if(isPrime(i) == 1){
			printf("\n%d\n", i);
			sum += i;
		}
			
	}
	printf("%ld", sum);
	
	return 0;
}

int isPrime(int value){
	
	int i=3;
	
	while(i<=floor(sqrt(value))){
		if(value%i == 0)
			return 0;
		i+=2;
	}
	
	return 1;
}
