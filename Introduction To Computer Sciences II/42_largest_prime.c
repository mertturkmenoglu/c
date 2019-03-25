/*
 *42) Large prime: Find the largest prime 
 *in an interval [a,b]
 */
 
#include <stdio.h>
#include <math.h>

int isPrime(int);

int main(void){
	
	int start, end, i;
	int largestPrime=2;
	
	printf("Starting point: ");
	scanf("%d", &start);
	
	printf("\nEnding point: ");
	scanf("%d", &end);
	
	for(i=start; i<=end; i++){
		if(isPrime(i))
			largestPrime = i;
	}
	
	printf("\nLargest prime in this interval is: %d", largestPrime);
	
	return 0;
	
}

int isPrime(int number){
	
	int i, sq=sqrt(number);
	
	if(number % 2 == 0)
		return 0;
	
	for(i=3; i<=sq; i += 2){
		if(number % i == 0)
			return 0;
	}
	
	return 1;
	
}
