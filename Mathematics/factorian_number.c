/*Faktorian sayi bulma*/
#include <stdio.h>

int main(void) {
	
	int i, n, temp, toplam;

	printf("Sayi giriniz: ");
	scanf("%d", &n);
	
	temp = n;
	toplam = 0;
	
	while (temp) {
		toplam += faktoriyel(temp % 10);
		temp /= 10;
	}
	
	if (toplam == n)
		printf("\nFaktorian sayi");
	else
		printf("\nFaktorian sayi degil");
	
	return 0;
}

int faktoriyel(int n) {
	int i, sonuc=1;
	
	if(n<2)
		return 1;
	else{
		for(i=n; i>1; i--)
			sonuc *= i;
	}
	return sonuc;
}
