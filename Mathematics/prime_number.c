/*Prime number*/
#include <stdio.h>

int main(void){
	
	int i, n, flag=0;
	
	do{
		printf("\nSayi giriniz: ");
		scanf("%d", &n);
	}while(n<2);
	
	i = 2; 
	
	while((i<n)&&(flag!=1)){
		if(n%i==0)
			flag = 1;
		i++;
	}
	
	if(flag == 1)
		printf("\nAsal degil");
	else
		printf("\nAsal sayi");
	
	return 0;
}
