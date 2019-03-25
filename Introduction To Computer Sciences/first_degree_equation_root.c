/*22) klavyeden katsayilari girlen birinci dereceden denklemin kokünü bulan program
*/

#include <stdio.h>

int main(){

	/*ax+b=c
	x= c-b /a
	*/

	float a, b, c;
	float root;

	printf("Please enter a: ");
	scanf("%f", &a);

	printf("Please enter b: ");
	scanf("%f", &b);

	printf("Please enter c: ");
	scanf("%f", &c);

	root = (c-b)/a;

	printf("Root: %f", root);

	return 0;

}