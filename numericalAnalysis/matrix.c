#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "numeric.h"

/*matrixInverse function starts*/
void matrixInverse(void){
	
	int i, j, k, size;
	double temp;
	double matrix[NUMERICSIZE][NUMERICSIZE];
	double inverseMatrix[NUMERICSIZE][NUMERICSIZE];
	double identityMatrix[NUMERICSIZE][NUMERICSIZE];
	double unifiedMatrix[NUMERICSIZE][2*NUMERICSIZE];
	
	system("clear");
	
	printf("Sayisal Analiz Matris Inversi Bulma");
	printf("\nOndalikli sayi girerken nokta isareti kullaniniz\n");
	
	printf("Kare matrisin boyutu: ");
	scanf("%d", &size);
	
	/*Read Matrix*/
	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			
			printf("\nLutfen %d-%d elemani giriniz: ", i+1, j+1);
			scanf("%lf", &matrix[i][j]);
			
		}
	}
	
	/*Assignment of identity matrix*/
	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			
			if(i==j)
				identityMatrix[i][j] = 1;
			else
				identityMatrix[i][j] = 0;
				
		}
	}
	
	/*Concatenating two matrices: Original Matrix*/
	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			unifiedMatrix[i][j] = matrix[i][j];
		}
	}
	
	/*Concatenating two matrices: Identity Matrix*/
	for(i=0; i<size; i++){
		for(j=size; j<2*size; j++){
			unifiedMatrix[i][j] = identityMatrix[i][j-size];
		}
	}
	
	for(i=0; i<size; i++){
	
		/*i-th row divided by A[i][i]*/
		temp=unifiedMatrix[i][i];
		for(j=0; j<2*size; j++)
			unifiedMatrix[i][j]/=temp;
			
		/*Ajk=Ajk-Aji*Aik*/
		for(j=0; j<size; j++){
			if(j!=i){
				temp = unifiedMatrix[j][i];
				for(k=0; k<2*size; k++)
					unifiedMatrix[j][k] -= (temp * unifiedMatrix[i][k]);
			}
		}
		
	}
	
	for(i=0; i<size; i++){
		for(j=size; j<2*size; j++)
			inverseMatrix[i][j-size] = unifiedMatrix[i][j];
	}
	
	for(i=0; i<size; i++){
		for(j=0; j<size; j++)
			printf("%.4f\t\t\t", inverseMatrix[i][j]);
		printf("\n");
	}
	
}/*matrixInverse function ends*/



/*gaussElimination functon starts*/
void gaussElimination(void){

	/*Variable declarations*/
	double mtr[NUMERICSIZE][NUMERICSIZE], temp, c[NUMERICSIZE], root[NUMERICSIZE];
	int i, j, k, l, size;
	
	system("clear");
	
	printf("Sayisal Analiz Gauss Eliminasyon");
	printf("\nOndalikli sayi girerken nokta isareti kullaniniz\n");
	
	printf("Matris boyutunu giriniz: ");
	scanf("%d", &size);

	/*Read the matrix*/
	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			printf("\nA[%d][%d]: ", i+1, j+1);
			scanf("%lf", &mtr[i][j]);
		}
	}
	
	
	/*Read C Matrix*/
	for(i=0; i<size; i++){
		printf("\nC[%d]: ", i+1);
		scanf("%lf", &c[i]);
	}
	
	/*
	 *Translating matrix to a lower 
	 *triangle matrix with 
	 *Gauss elimination method
	 */
	for(i=0; i<size; i++){
		
		temp = mtr[i][i];
		
		for(j=0; j<size; j++)
			mtr[i][j] /= temp;
			
		c[i] /= temp;
	
		for(j=i+1; j<size; j++){
			
			temp = mtr[j][i];
			for(k=0; k<size; k++){
				mtr[j][k] /= temp;
				mtr[j][k] -= mtr[i][k];
				mtr[j][k] *= temp;
			}
			
			c[j] /= temp;
			c[j] -= c[i];
			c[j] *= temp;
			
		}
		
	}
	
	for(k=0; k<size; k++){
		i=size-k-1;
		root[i] = (c[i]-matrixSum(i+1,mtr,root,size))/mtr[i][i];
		printf("X%d: %lf\n", i+1, root[i]);
	}
	
	/*Print the new matrix*/
	for(i=0; i<size; i++){
		
		for(j=0; j<size; j++)
			printf("%2.4lf\t\t", mtr[i][j]);
			
		printf("%2.4lf\t", c[i]);
		printf("\n");
		
	}
	printf("\n---------------------\n");
	
}/*gaussElimination function ends*/



/*matrixSum function starts*/
double matrixSum(int start, double mtr[][NUMERICSIZE], double root[NUMERICSIZE], int size){
	
	int i=start-1,j;
	double sum=0;
	
	for(j=start; j<size; j++)
		sum += mtr[i][j] * root[j];
		
	return sum;
	
}/*matrisSum function ends*/

