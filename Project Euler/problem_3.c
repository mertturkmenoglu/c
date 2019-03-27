/*Problem 3*/
#include <stdio.h>
#include <math.h>

int main(){
	
	int i=2,sayi;
	
	while((10086647 % i) != 0)
		i++;
	sayi = 10086647 / i;
	printf("\n%d\n", sayi);
	while(i<sayi){
		if(sayi % i == 0){
			sayi /= i;
			i++;
		}	
	}
	
	printf("%d", sayi);
	
	return 0;
	
}

