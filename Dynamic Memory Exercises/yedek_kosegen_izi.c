/*6) NxN A matrisinin 
 *yedek kosegeninin tüm 
 * elemanlarinin toplamini 
 *bulan program
 */
 
#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i, j, n, *mtrA, sum = 0;
	
	printf("Please enter N: ");
	scanf("%d", &n);
	
	mtrA = (int*) malloc(n*n*sizeof(int));
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("\nA[%d][%d]: ", i+1, j+1);
			scanf("%d", (mtrA + i*n + j));
		}
	}
	
	for(i=0; i<n; i--)
		sum += *(mtrA+i*n+(n-1-i));
		
	printf("\n\n%d", sum);
	
	free(mtrA);
	return 0;
}
