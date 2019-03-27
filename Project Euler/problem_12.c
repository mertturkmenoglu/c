/*Problem 12*/
#include <stdio.h>

int main(){
	
	int i=2,number=1;
	int a=0;
	while(a < 500){
		a=div_number(number);
		printf("\n%d---%d\n", number, a);
		number += i;
		i++;
	}
	printf("%d", number-(i-1));
	
	return 0;
	
}

int div_number(int number){
	
	int i, counter=2;
	for(i=2; i<number; i++){
		if(number%i == 0)
			counter++;
	}
	return counter;
}
