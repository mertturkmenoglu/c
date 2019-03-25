/*9) Klavyeden tum kenar uzunluklari girilen ucgenin alanini hesaplayan program
*/

#include <stdio.h>
#include <math.h>

int main(){

	float area, side1, side2, side3, s;

	printf("Please enter first side: ");
	scanf("%f", &side1);

	printf("Please enter second side: ");
	scanf("%f", &side2);

	printf("Please enter third side: ");
	scanf("%f", &side3);

	s = (side1 + side2 + side3)/2;

	area = sqrt(s*(s-side1)*(s-side2)*(s-side3));

	printf("\nArea: %f", area);

	return 0;
}