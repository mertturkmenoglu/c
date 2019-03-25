/*43) klavyeden girilen n sayının sadece birler basamagını toplayan program
*/

#include <stdio.h>
#define SIZE 100

int main(){

	int len, i, array[SIZE], sum=0;

	printf("Please enter array size: ");
	scanf("%d", &len);

	for(i=0; i<len; i++){
		printf("Please enter %d -th number: ", i+1);
		scanf("%d", &array[i]);
		sum += (array[i]%10);
	}

	printf("Sum: %d", sum);

	return 0;

}