/*N e kadar asal sayilari yazdirir*/
#include <stdio.h>

int main(void){
	
	int n, i=2;
	
	do{
		printf("\nSayi giriniz: ");
		scanf("%d", &n);
	}while(n<2);
	printf("\n2-");
	
	while(++i<n){
		if(isPrime(i))	
			printf("%d-", i);
	}
	
	return 0;
	
}

int isPrime(int n){
	
	int i;
	for(i=2; i<n; i++){
		if(n%i == 0)
			return 0;
	}
	return 1;
	
}
