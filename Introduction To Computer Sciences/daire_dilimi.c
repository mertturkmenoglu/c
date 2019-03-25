/*8) Klavyeden yaricapi ve derece cinsinden acisi girlen daire diliminini alanini hesaplayan program
*/

#include <stdio.h>
#include <math.h>

int main(){

	float radius, angle, area;

	printf("Radius: ");
	scanf("%f", &radius);

	printf("\nAngle: ");
	scanf("%f", &angle);

	area = angle*M_PI*radius*radius/360;

	printf("\nArea: %f", area);

	return 0;
}