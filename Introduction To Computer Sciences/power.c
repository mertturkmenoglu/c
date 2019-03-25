/*28) klavyeden girilen bir tamsayinini yine klavyeden girilen pozitif tamsayi ussünü hesaplayan program
*/

#include <stdio.h>

int main(){

	int number1, number2, i, result=1;

	printf("Please enter the base: ");
	scanf("%d", &number1);

	printf("Please enter the exponent: ");
	scanf("%d", &number2);

	for(i=0; i<=number2; i++)
		result *= number1;

	printf("Result: %d", result);

	return 0;

}