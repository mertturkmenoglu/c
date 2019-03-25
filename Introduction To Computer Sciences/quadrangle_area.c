/*6) klavyeden kosegenleri 
 *ve arasındaki derece 
 *cinsinden acisi girilen 
 *dortgenin alanini 
 *hesaplayan program
 */

#include <stdio.h>
#include <math.h>

/*Main function starts*/
int main(){

	/*Variable declarations*/
	float len1, len2, angle, area; 

	/*Read values*/
	printf("Please enter first length: ");
	scanf("%f", &len1);

	printf("Please enter second length: ");
	scanf("%f", &len2);

	printf("Please enter angle: "); 
	scanf("%f", &angle);


	/*Compute area*/
	area = len1*len2*sin(angle*M_PI/180)/2;

	/*Print area*/
	printf("Area: %f", area);

	/*Indicates successful termination*/
	return 0;

}/*Main function ends*/
