/*17) girilen tam sayının tek mi çift mi olduğunu bulan program
*/

#include <stdio.h>

int main(){

	int number;

	printf("Enter number: ");
	scanf("%d", &number);

	if(number%2 == 0)
		printf("Even number");
	else
		printf("Odd number");

	return 0;
}