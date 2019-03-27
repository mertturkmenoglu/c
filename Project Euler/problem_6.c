/*Problem 6*/
#include <stdio.h>

int main(){
	
	int sum=0,i;
	for(i=1; i<101; i++){
		sum += i;
	}
	printf("%d", sum*sum);
	return 0;
}
