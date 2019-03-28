#include<stdio.h>

int ebob(int, int);

int main() {
	
	int a, b;

	printf("A yi giriniz:");
	scanf("%d", &a);
	
	printf("B yi giriniz:");
	scanf("%d", &b);
	
	printf("Iki sayinin ebobu: %d", ebob(a, b));
	
	return 0;

}

int ebob(int a, int b) {
	if (a % b == 0)
		return b;
	else
		return ebob(b, a % b);
}


