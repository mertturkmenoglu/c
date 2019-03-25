/*3) Klavyeden iki kenari
 * ve derece cinsinden aradaki
 * acisi girilen ucgenin alanini 
 *hesaplayan program
 */

#include <stdio.h>
#include <math.h>

/*Main function starts*/
int main(){

	/*Variable declarations*/
	float side1, side2, angle, area;

	/*Read values*/
	printf("Please enter first side: ");
	scanf("%f", &side1);

	printf("Please enter second side: ");
	scanf("%f", &side2);

	printf("Please enter angle: ");
	scanf("%f", &angle);


	/*Compute area*/
	area = side1*side2*sin(M_PI*angle/180)/2;

	/*Print area*/
	printf("Area: %f", area);

	/*Indicates successful termination*/
	return 0;
}/*Main function ends*/