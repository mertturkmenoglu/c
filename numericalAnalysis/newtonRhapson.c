#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "numeric.h"

/*newtonRhapson function starts*/
void newtonRhapson(void){
	
	/*Variable declarations
	 *@degree: Maximum exponent of variable
	 *@iteration: Iteration number
	 *@xZero: Starting value
	 *@xNew: x0 + deltax value
	 *@epsilon: Tolerance. Equals difference between last x values
	 *@fxZero: f(x0)
	 *@fdxZero: f'(x0)
	 *@ *array: Coefficient array's pointer
	 */
	 
	int degree, i, iteration=1;
	double xZero, xNew, epsilon, fxZero, fdxZero, *array;
	double DX = 0.001;
	
	system("clear");
	
	printf("Sayisal Analiz Kok Bulma Yontemleri Newton Rhapson Metodu");
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
	
	/*Read X0*/
	printf("\nLutfen ilk x degerini giriniz(x0):\t");
	scanf("%lf", &xZero);
	
	/*Read epsilon value*/
	do{
		
		printf("\nLutfen epsilon degerini giriniz:\t");
		scanf("%lf", &epsilon);
		
	}while(epsilon == 0);
	
	/*Read DX value*/
	do{
		
		printf("\nLutfen turev alma esnasinda kullanilan artirim miktari dx i giriniz: ");
		scanf("%lf", &DX);
		
	}while(DX <= 0);
	
	/*Compute x values
	 *Difference between consecutive x values equals
	 *absolute value of fx0/fdx0
	 *Loop goes until it is smaller than tolerance value
	 */
	 
	do{
		
		/*Compute f(x0) and f'(x0)
		 *fx0: f(x0)
		 *fdx0: f derivative x: f'(x0)
		 *fx: Calling function y=f(x)
		 */
		fxZero  = fx(array, degree, xZero);
		
		/*Numerical derivative*/
		fdxZero = fx(array, degree, xZero+DX) - fx(array, degree, xZero-DX);
		fdxZero /= (2*DX);
		
		/*X(i+1) = X(i) - ( f(Xi) / f'(Xi) )*/
		xNew = xZero - (fxZero / fdxZero);
		
		/*Print values*/
		printf("\nXi: %lf\n", xZero);
		printf("f(Xi): %lf\n", fxZero);
		printf("f'(Xi): %lf\n", fdxZero);
		printf("Xi+1: %lf\n", xNew);
		printf("\n--- %d -inci iterasyon sonlandi ---\n", iteration);
		
		iteration++;
		xZero = xNew;
		
	}while( fabs(fxZero/fdxZero) > epsilon );
	
	/*Print root value 5 decimal point*/
	printf("\nKok: %.5lf", xZero);
	
	free(array);
	
}/*newtonRhapson function ends*/