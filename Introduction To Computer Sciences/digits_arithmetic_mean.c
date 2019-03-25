/*37) klavyeden girilen uc basamaklı pozitif tamsayının rakamlarının aritmetik ortalamasını hesaplayıp ekrana yazdıran program
*/

#include <stdio.h>

int main(){

	int number;
	float result=0;

	printf("Please enter the number: ");
	scanf("%d", &number);

	while(number){
		result += number%10;
		number/= 10;
	}

	result /= 3;

	printf("Result: %f", result);

	return 0;

}