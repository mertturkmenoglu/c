/*Problem 2*/
#include <stdio.h>

int main(){
	
	int sayi1=1, sayi2=2, sayi3=0;
	int sum=2;
	
	while(sayi3<4000000){
		
		sayi3 = sayi2 + sayi1;
		
		if(sayi3%2 == 0)
			sum += sayi3;
			
		sayi1 = sayi2;
		sayi2 = sayi3;
	}
	
	printf("%d", sum);
	
	return 0;
	
}
