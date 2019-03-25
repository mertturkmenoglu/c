/*12) Klavyeden kutlesi ve molekul agırligi girilen maddenin mol sayisini hesaplayan program.
*/

#include <stdio.h>

int main(){

	float m, ma, n;

	printf("Please enter mass: ");
	scanf("%f", &m);

	printf("Please enter molecul mass: ");
	scanf("%f", &ma);

	n = m / ma;

	printf("Mol: %f", n);

	return 0;
}