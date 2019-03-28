#include <stdio.h>
#define SIZE 10

int main() {
	float mtr[SIZE][SIZE],temp,c[SIZE],root[SIZE];
	int i,j,k,l,size;
	size=3;

	mtr[0][0]=3.6;	mtr[0][1]=2.4;	mtr[0][2]=-1.8;
	mtr[1][0]=4.2;	mtr[1][1]=-5.8;	mtr[1][2]=2.1;
	mtr[2][0]=0.8;	mtr[2][1]=3.5;	mtr[2][2]=6.5;
	
	c[0]=6.3;
	c[1]=7.5;
	c[2]=3.7;
	
	//Translating matrix to a lower triangle matrix with 
	//Gauss elimination method
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
	
	printf("\n---------------------\n");
	
	for(i=0; i<size; i++)
		printf("%f\n", c[i]);

	return 0;

}
