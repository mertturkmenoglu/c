/*30) klavyeden girilen sayının tamsayı olup olmadıgını test eden program
*/

#include <stdio.h>
#include <math.h>

int main(){

	float number; 

	printf("Please enter the number: ");
	scanf("%f", &number);

	if(floor(number) == number)
		printf("Integer");
	else
		printf("Not an integer");

	return 0;
}