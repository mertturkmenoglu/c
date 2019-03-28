#include <stdio.h>

int main() {

	int a = 2, n;

	do {
		printf("Enter a number:\n");
		scanf("%d", &n);
	} while (n < 2);

	while (n != 1) {
		if (n % a == 0) {
			printf("%d\n", a);
			n /= a;
		} else {
			a++;
		}
	}
	
	return 0;
}
