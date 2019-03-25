/*2) Klavyeden derece 
 *cinsinden girilen aciyi 
 *radyan ve grad ceviren 
 *program
 */

#include <stdio.h>
#include <math.h>

/*Main function starts*/
int main(){

	/*Variable declarations*/
	float angle;

	/*Read value*/
	printf("Please enter angle: ");
	scanf("%f", &angle);

	/*Convert and print*/
	printf("\nRadian: %f", angle * M_PI / 180);
	printf("\nGrand: %f", angle*200/180);

	/*Indicates successful termination*/
	return 0;

}