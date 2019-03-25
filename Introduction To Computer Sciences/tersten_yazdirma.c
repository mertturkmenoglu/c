/*36) klavyeden girilen bir sayıyı tersten yazdıran program
*/

#include <stdio.h>

int main(){

	int number, temp=0; 

	printf("Please enter the number: ");
	scanf("%d", &number);

	while(number){
		temp *= 10 ;
		temp += number%10;
		number /= 10; 
	}

	printf("\n%d", temp);

	return 0;

}
