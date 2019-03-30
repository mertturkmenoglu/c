#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "numeric.h"

/*graphic function starts*/
void graphic(void){
	
	/*Variable declaration
	 *@xZero: First x value (x0)
	 *@deltaX: Increament amount between x values
	 *@epsilon: Tolerance. Equals difference between last x values
	 *@fxZero: F(xZero) value
	 *@fxNew: F(xNew) value
	 *@xNew: x_zero+delta_x value
	 *@iteration: Amount of iteration. It controls loop times
	 *@degree: Maximum exponent of variable
	 *@control: Keeps consecutive iteration number
	 *@ *array: Coefficient array's pointer
	 */
	
	double xZero, xNew, deltaX, epsilon, fxZero, fxNew, *array;
	int iteration = 1, degree, control = 0, i;	
	
	system("clear");
	
	printf("Sayisal Analiz Kok Bulma Yontemleri Grafik Metodu");
	printf("\nOndalikli sayi girerken nokta isareti kullaniniz\n");
	
	/*Read equation degree*/
	do{
		
		printf("\nLutfen polinomunuzun derecesini giriniz: ");	
		scanf("%d", &degree);
		
	}while(degree <= 0);
	
	/*Memory allocation for coefficient array*/
	array = (double*) malloc( (degree+1) * sizeof(double) );
	
	/*Error handling*/
	if(array == NULL){
		
		printf("\nHata! Bellek ayrilamadi\n");
		exit(0);
		
	}
	
	/*Read coefficient array*/
	for(i=degree; i>=0; i--){
		
		printf("\nx^%d teriminin katsayisini isaretli olarak giriniz: ", i);
		scanf("%lf", (array+i));
		
	}
	
	/*Read xZero deltaX and epsilon*/
	printf("\nLutfen ilk x degerini giriniz: ");
	scanf("%lf", &xZero);
	
	do{
		
		printf("\nLutfen delta x degerini giriniz: ");			
		scanf("%lf", &deltaX);
		
	}while(deltaX == 0);
	
	do{
		
		printf("\nLutfen epsilon degerini giriniz: ");			
		scanf("%lf", &epsilon);
		
	}while(epsilon<0);
	
	do{
		
		/*Computes f(x0)*/
		fxZero = fx(array, degree, xZero);
	
		/*Xi+1 = Xi + dx*/
		xNew = xZero + deltaX;
		
		/*Computes f(x0+dx)*/
		fxNew = fx(array, degree, xNew);
		
		/*Print x and f(x) */
		printf("\nX0: %lf\t\tF(x): %lf\n", xZero, fxZero);
		printf("\nX0+dx: %lf\t\tF(X0+dx): %lf\n", xNew, fxNew);
		
		/*
		 *If there is zero crossing between F(x) values
		 *Root must be in this interval
		 *Changes interval boundaries for next iteration
		 */
		if(fxZero*fxNew < 0){
			
			/*Last two roots have different signs
			 *New deltax is half of the previous one
			 *Compute new x value
			 */
			 
			deltaX /= 2;
			
			/*Print information*/
			printf("\n ----- %d -inci iterasyon sona erdi. ----- \n", iteration); 
			iteration++;
			
			/*Resets consecutive iteration number */
			control = 0;
			
		}
		else{
			
			/*Roots have same sign*/
			xZero = xNew;
			control++;
		
		}
		
	}while((deltaX>epsilon)&&(control < 20));
	
	/*
	 *If consecutive iteration is higher than 20
	 *there is no root in this interval
	 *Indicates unsuccessful termination
	 */
	 
	if(control < 20)
		printf("\nKok: %lf", xZero);
	else
		printf("\n%d adimda kok bulunamadi. Degerlerinizi kontrol ediniz.", control);

	free(array);
	
}/*graphic function ends*/
