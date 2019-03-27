/*Problem 4*/
#include <stdio.h>
void pal(int );
int main(){
	
	int i, j, a=0;
	
	for(i=100; i<1000; i++){
		for(j=100; j<1000; j++){
			a = i*j;
			pal(a);
		}
	}
	
	return 0;
}

void pal(int sayi){
	int temp, rev=0;
	temp=sayi;
	while(temp != 0){
		rev=rev*10;
		rev=rev+temp%10;
		temp=temp/10;
	}
	if((rev==sayi)&&(rev>900000))
		printf("\n%d\n", sayi);
	
}
