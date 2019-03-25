/*27) klavyeden girilen iki pozitif tamsayiyi carpma operatörü kullanmadan carpan program
*/

#include <stdio.h>

int main(){

	int number1, number2, product=0, i;

	printf("Please enter first number: ");
	scanf("%d", &number1);

	printf("\nPlease enter second number: ");
	scanf("%d", &number2);

	for(i=0; i<=number2; i++)
		product += number1;

	printf("\nResult: %d", product);

	return 0;
}