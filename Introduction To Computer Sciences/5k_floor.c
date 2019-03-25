/*35) klavyeden girilen bir tamsayıyı kendisinden kucuk en yakın 5 in katına yuvarlayan program
*/

#include <stdio.h>

int main(){

	int number;

	printf("Please enter the number: ");
	scanf("%d", &number);

	while(number%5 != 0)
		number--;
	

	printf("Result: %d", number);

	return 0;
		
}
