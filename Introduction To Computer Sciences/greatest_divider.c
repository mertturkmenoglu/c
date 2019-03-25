/*40) klavyeden girilen pozitif tamsayının en buyuk bolenini bulan program
*/

#include <stdio.h>
#include <math.h>
int main(){

	int number, div=1;

	printf("Please enter a number: ");
	scanf("%d", &number);

	for(i=2; i<floor(sqrt(number)); i++){
		if(number%i == 0)
			div = i;
	}

	printf("Greatest divider: %d", div);

	return 0;
}