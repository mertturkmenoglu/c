#include<stdio.h>

int main() {

	int ent, temp, rev = 0;

	printf("Enter a value to check if palindrome of not\n");
	scanf("%d", &ent);

	temp = ent;

	while (temp != 0){
		rev = rev*10;
		rev = rev + temp % 10;
		temp = temp / 10;
	}

	if (rev == ent)
		printf("It is a polindrome number\n");
	else
		printf("It is not a polindrome number\n");
	
	return 0;

}
