#include <stdio.h>
#define SIZE 100

/*Main function starts*/
int main() {
	
	/*Variable declarations*/
	int i, j, n, index = 0, array[SIZE];
	static int freq[SIZE][2];
	
	printf("Please enter the number of elements: ");
	scanf("%d", &n);
	
	/*Read array*/
	for (i = 0; i < n; i++) {
		printf("\nPlease enter %d -th element: ", i+1);
		scanf("%d", &array[i]);
	}
	
	for (i = 0; i < n; i++) {
		j = 0;
		while((j <= index) && (array[i] != freq[j][0]))
			++j;
			
		if (j > index) {
			freq[index][0] = array[i];
			freq[index][1]++;
			++index;
		} else {
			freq[j][1]++;
		}
	}
	
	for(i = 0; i < index; i++)
		printf("\nNumber of %d:\t%d", freq[i][0], freq[i][1]);
	
	return 0;
	
}
