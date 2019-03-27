/*Problem 5*/
#include <stdio.h>

int main(){
	int dizi[19], i,j, check=1;
	
	for(i=0; i<19; i++)
		dizi[i] = i+2;
	
	j=2520;
	while(j<1000000){
		i=0;
		while(i<19){
			if(j % dizi[i] != 0)
				check = 0;
			i++;
		}
		if(check==1)
			printf("\n%d\n", j);
		else
			check = 1;	
	}
	return 0;
}
