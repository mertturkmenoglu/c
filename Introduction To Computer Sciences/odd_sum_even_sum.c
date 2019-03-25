/*20) Klavyeden girilen n sayisina göre 1 den n e kadar sayıların toplamını (t1) 1 den n e kadar tek sayiların toplamını (t2 ) ve 2 den n e kadar cift tamsayıların toplamını hesaplayan program
*/

#include <stdio.h>

int main(){

	int number, evensum= 0;
	int oddsum=0;
	int i;
	
	printf("Please enter the number: ");
	scanf("%d", &number);

	for(i=1; i<=number; i++){
		if(i%2==0)
			evensum += i;
		else
			oddsum += i;
	}

	printf("\nEven sum: %d", evensum);
	printf("\nOdd sum: %d", oddsum);
	printf("\nAll sum: %d", evensum+oddsum);

	return 0;

}