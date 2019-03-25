/*41) klavyeden girilen sayının 10 tabanındaki gösterimini yazdıran program
*/

#include <stdio.h>

int main(){

	int number, factor=1, temp; 

	printf("Please enter the number: ");
	scanf("%d", &number);

	temp = number; 
	while(temp){
		printf("%dx%d\t", temp%10, factor);
		temp /= 10;
		factor *= 10;
	}

	return 0;
}
