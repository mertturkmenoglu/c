/*13) Klavyeden baslangic kutlesi 
ile yarılanma suresi girilen bir 
radyoaktif elementin belirtile 
sure sonunda kac yarılanma 
gecilecegini ve kütlesinin ne kadar 
kalacagini hesaplayan program
*/

#include <stdio.h>
#include <math.h>

int main(){

	float m0, dt, t, n, m;

	printf("Baslangic kutlesi: ");
	scanf("%f", &m0);

	printf("\nYarilanma suresi: ");
	scanf("%f", &dt);

	printf("\nSure: ");
	scanf("%f", &t);

	n = t/dt;

	m = m0/pow(2,n);

	printf("\nn: %f\nm: %f\n", n, m);

	return 0;
}
