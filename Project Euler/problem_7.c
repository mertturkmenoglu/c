/*Problem 7*/
#include <stdio.h>
int isPrime(int value);
int main(){
	
	int i=3, number=1;
	
	while(number != 10001){
		if(isPrime(i) == 1){
			printf("%d\n", i);
			number++;
		}
		i++;
	}
	
	printf("%d", i-1);
	
	return 0;
}

int isPrime(int value){
	
	int j=2,check=0;
	
	while(j<value){
		if(value % j == 0)
			check=1;
		j++;
	}
	if(check==0)
		return 1;
	else
		return 0;
	
}
