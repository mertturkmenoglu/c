/*7) Klavyeden yaricaoi girilen kurenin alanini ve hacmini hesapayan program
*/

#include <stdio.h>
#include <math.h>

int main(){

	float r, area, volume;

	printf("Please enter r: ");
	scanf("%f", &r);

	volume = 4*M_PI*r*r*r/3;
	area = 4*M_PI*r*r;

	printf("Volume: %f\nArea: %f\n", volume, area);

	return 0;
}