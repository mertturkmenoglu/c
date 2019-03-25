/*19) klavyeden girilen pozitif bir a tamsayisinin tam bolenlerini hesaplayip listeleyen program
*/

#include <stdio.h>

int main(){

	int number, i;

	do{
		printf("\nPlease enter the number: ");
		scanf("%d", &number);
	}while(number<=0);

	printf("1\t-1\t");

	for(i=2; i<=number; i++){
		if(number % i == 0)
			printf("%d\t%d\t", i, -i);
	}

	return 0;
}