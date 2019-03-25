/*25) klavyeden metre cinsinden girilen uzunlugu secilen birime donusturen program
*/

#include <stdio.h>
#include <math.h>

int main(){

	float number; 
	int check;
	int factor[]={4,3,2,1,-1,-2,-3,-6,-9,-12};
	printf("Please enter the number: ");
	scanf("%d", &number);

	printf("\nPlease choose: ");
	printf("\n1.Mega");
	printf("\n2.Kilo");
	printf("\n3.Hecto");
	printf("\n4.Deca");
	printf("\n5.Deci");
	printf("\n6.Centi");
	printf("\n7.Mili");
	printf("\n8.Micro");
	printf("\n9.Nano");
	printf("\n10.Pico\n");
	scanf("%d", &check);

	printf("\n%f", pow(number, factor[check-1]));

	return 0;

}