/*34) basamaklarının toplamı 
basamak sayısına 
esit olan 100-999 arasındaki 
sayıları bulan program
*/

#include <stdio.h>

int main(){

	int i; 

	for(i=100; i<1000; i++){
		if((i%10)+(i/10%10)+(i/100)==3)
			printf("%d\n", i);
	}

	return 0;
}