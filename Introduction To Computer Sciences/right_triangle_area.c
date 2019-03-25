/*4) Klavyeden iki dik 
 *kenari girilen dik 
 *ucgenin alanini 
 *hesaplayan program
 */

#include <stdio.h>

/*Main function starts*/
int main(){

	/*Variable declarations*/
	float side1, side2, area;

	/*Read values*/
	printf("Please enter first side: ");
	scanf("%f", &side1);

	printf("Please enter second side: ");
	scanf("%f", &side2);


	/*Compute area*/
	area = (side1*side2)/2;

	/*Print area*/
	printf("Area: %f", area);

	/*Indicates successful termination*/
	return 0;
}/*Main function ends*/
