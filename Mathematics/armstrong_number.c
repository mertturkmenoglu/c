/*Armstrong Sayisi*/
#include <stdio.h>

int main(){
	
	int n, temp, bs=0, toplam=0;
	
	printf("Sayi giriniz: ");
	scanf("%d", &n);
	
	temp = n;
	
	while(temp){
		temp /= 10;
		bs++;
	}
	
	temp = n;
	while(temp){
		toplam += pow(temp%10, bs);
		temp /= 10;
	}
	
	
	
	if(n == toplam)
		printf("Armstrong sayisi");
	else
		printf("\nArmstrong sayisi degil");
		
	return 0;
	
}
