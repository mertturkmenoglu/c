#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "numeric.h"

/*trapez function starts*/
void trapez(void){

	/*Variable declarations
	 *@degree: Maximum exponent of variable
	 *@a: Starting point of integral
	 *@b: Final point of integral
	 *@n: Segment number
	 *@h: Iteration amount
	 *@S: Sum
	 *@ *array: Coefficient array
	 */
	int i, degree, n;
	double h, S, *array, a, b;
	
	system("clear");
	
	printf("Sayisal Analiz Integral Hesaplama Yontemleri Trapez Metodu");
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
	
	/*Read a b and n values*/
	printf("\nLutfen a degerini giriniz: ");	
	scanf("%lf", &a);
	
	printf("\nLutfen b degerini giriniz: "); 	
	scanf("%lf", &b);
	
	printf("\nLutfen n degerini giriniz: ");	
	scanf("%d", &n);
	
	/*Compute h value*/
	h = (double) (b-a) / n;
	
	/*Compute S value
	 * S = h[ (f(a)+f(b))/2 + sum(a to n-1)h*f(x) ]
	 */
	S = (h/2) * ( fx(array, degree, a) + fx(array, degree, b) );
	S = h * sum(a, n-1, h, array, degree);
	
	/*Print the result*/
	printf("\n%lf\n", S);
	
	free(array);

}/*trapez function ends*/

/*simpson function starts*/
void simpson(void){
	
	/*Variable declarations*/
	int i, degree, n;
	double x0, xn, h, S=0, *array;
	
	system("clear");
	
	printf("Sayisal Analiz Integral Hesaplama Yontemleri Simpson Metodu");
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
	
	/*
	 *Read n number and control it.
	 *n must be even number
	 */
	
	do{
		
		printf("Lutfen n degerini giriniz: ");
		scanf("%d", &n);
		
	}while(n % 2 == 1);
	
	/*Read X0 and Xn values*/
	
	printf("Lutfen X0 degerini giriniz: ");
	scanf("%lf", &x0);
	
	printf("Lutfen Xn degerini giriniz: ");
	scanf("%lf", &xn);
	
	/*
	 *Computing h value. 
	 *h: delta x: increasing value
	 */
	
	h = (double)(xn - x0) / n;
	
	/*Computing Simpsons Sum*/
	
	S = fx(array, degree+1, x0) + fx(array, degree+1, xn);
	S += 4 * simpsonSum(1, n-1, array, degree+1, x0, h);
	S += 2 * simpsonSum(2, n-2, array, degree+1, x0, h);
	S *= h;
	S /= 3;
	
	/*Print answer*/
	printf("Sonuc: %lf", S);
	free(array);
	
}/*simpson function ends*/



/*differentiation function starts*/
void differentiation(void){

	/*Variable declarations
	 *@degree: Maximum exponent of variable
	 *@ *array: Coefficient array's pointer
	 *@xi: X value
	 *@dx: Increment amount
	 *@fdf: f derivative forward
	 *@fdb: f derivative backward
	 *@fdc: f derivative central
	 */
	
	int i, degree;
	double *array, xi, dx, fdf, fdb, fdc;
	
	system("clear");
	
	printf("Sayisal Analiz Turev Hesaplama");
	printf("\nOndalikli sayi girerken nokta isareti kullaniniz\n");
	
	/*Read equation degree*/
	do{
		printf("Lutfen denkleminizin derecesini giriniz: ");
		scanf("%d", &degree);
	}while(degree < 0);
	
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
	
	/*Read Xi*/
	printf("\nLutfen x degeri giriniz: ");
	scanf("%lf", &xi);
	
	/*Read dx value*/
	do{
		
		printf("\nLutfen dx i giriniz: ");
		scanf("%lf", &dx);
		
	}while(dx == 0);
	
	/*Computing fdf fdb fdc*/
	fdf = ( fx(array, degree, xi+dx) - fx(array, degree, xi) ) / dx;
	fdb = ( fx(array, degree, xi) - fx(array, degree, xi-dx) ) / dx;
	fdc = ( fx(array, degree, xi+dx) - fx(array, degree, xi-dx) ) / (2*dx);
	
	/*Print computed values*/
	printf("\nIleri fark turev: %lf", fdf);
	printf("\nGeri fark turev: %lf", fdb);
	printf("\nMerkezi fark turev: %lf", fdc);
	
	free(array);
	
}/*differentiation function ends*/



/*
 *F(x) Function
 *This function finds function value at a certain x value
 *@param *array: Coefficients of every element
 *@param equationDegree: Maximum exponent of variable
 *@param xValue: Compute y=f(x) at this x value
 */ 
double fx(double* array, int degree, double xValue){
	
	/*
	 *@factor: Computing pow(x, i) with iteratively
	 *@result: y=f(x) value
	 */ 
	
	/*Variable declarations*/
	double factor = 1, result = 0;
	int i;
	
	for(i=0; i <= degree; i++) {
			result += *(array+i) * factor;
			factor *= xValue;
	}
	
	/*Returns y=f(x) value to function*/
	return result;
		
}/*fx function ends*/



/*
 *sum function
 *Mathematical sigma symbol
 *This function finds all sums from
 *@param a
 *to
 *@param final
 *
 *@param h: Iteration amount
 *@param *array: Coefficients of every element
 *@param equationDegree: Maximum exponent of variable
 */
double sum(int a, int final, double h, double* array, int degree) {
	
	/*Variable declarations*/
	int k;
	double result = 0;
	
	for (k=1; k <= final; k++)
		result += fx(array,degree+1, a+k*h);
		
	return result;
	
}/*sum function ends*/



/*simpsonSum function starts*/
double simpsonSum(int start, int finish, double* array, int degree, double x0, double h) {
	
	int i;
	double result = 0;
	
	for(i=start; i <= finish; i+=2)
		result += fx(array, degree, x0 + i*h);
		
	return result;
	
}/*simpsonSum function ends*/
