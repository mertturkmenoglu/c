/*5) Klavyeden iki kenari 
 *ve bunların arasindaki 
 *derece cinsinden acisi
 *grlen ucgenin ucuncu 
 *kenarini hesaplayan program
 */

#include <stdio.h>
#include <math.h>

/*Main function starts*/
int main(){

	/*Variable declarations*/
	float side1, side2, angle, side3;

	/*Read values*/
	printf("Please enter first side: ");
	scanf("%f", &side1);

	printf("Please enter second side: ");
	scanf("%f", &side2);

	printf("Please enter angle: ");
	scanf("%f", &angle);

	/*Compute third side*/
	side3 = side1*side1 + side2*side2 - 2*side1*side2*cos(angle*M_PI/180);
	side3 = sqrt(side3);

	/*Print value*/
	printf("Third side: %.2f", side3);

	/*Indicates successful termination*/
	return 0;
}/*Main function ends*/