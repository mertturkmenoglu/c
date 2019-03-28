/*Asal sayi*/
#include <stdio.h>

int main(){
	int i=2,check=0, value;
	
	printf("Sayi: ");
	scanf("%d", &value);
	
	while(i<value){
		if(value%i == 0)
			check=1;
		else
			i++;
	}
	
	if(check==0)
		printf("\nAsal sayi");
	else
		printf("\nAsal sayi degil");
		
	return 0;
	
}
