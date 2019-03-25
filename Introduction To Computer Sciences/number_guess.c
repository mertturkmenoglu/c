/*38) bilgisayarın girilen aralıkta urettigi rastgele sayıyı bulma oyunu
*/

#include <stdio.h>
#include <time.h>

int main(){

	srand(time(NULL));

	int a, b, number, temp; 

	printf("A: ");
	scanf("%d", &a);

	printf("B: ");
	scanf("%d", &b);

	number = random() % (b-a) + a;

	do{
		printf("\nEnter a value: ");
		scanf("%d", &temp);

		if(temp<number)
			printf("Say a higher number");
		else
			printf("Say a lower number");

	}while(temp != number);

	printf("\nYou win");

	return 0;
}