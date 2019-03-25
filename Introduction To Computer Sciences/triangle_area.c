/*Ucgen alani hesaplayan program
 *1) Klavyeden bir kenar uzunlugu 
 *ve o kenara ait yuksekligi girilen 
 *ucgenin alanini hesaplayan program
 */

#include <stdio.h>

/*Main function starts*/
int main(){

	/*Variable declarations*/
	int len, height;
	float area;

	/*Read values*/
	printf("Please enter side length: ");
	scanf("%d", &len);

	printf("Please enter height: ");
	scanf("%d", &height);

	/*Compute area*/
	area = (len+height) / 2;

	/*Print result*/
	printf("Area: %f", area);

	/*Indicates successful termination*/
	return 0;
	
}/*Main function ends*/