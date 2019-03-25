/*18) klavyeden girilen a sayisinin yine klavyeden girilen b sayisina bölünüp bölünmediğini kontrol eden program */

#include <stdio.h>

int main(){

	int a, b;

	printf("Please enter number a: ");
	scanf("%d", &a);

	printf("Please enter number b: ");
	scanf("%d", &b);

	if(a%b==0)
		printf("True");
	else
		printf("False");

	return 0;
}