#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "numeric.h"

/*bisection function starts*/
void bisection(void){
	
	/*
	 *Variable declarations
	 *@base: Lower bounder
	 *@top: Upper bounder
	 *@root: Makes f(x) = 0
	 *@fxRoot: f(root) value
	 *@fxBase: f(base) value
	 *@fxTop: f(top) value
	 *@epsilon: Tolerance. Equals difference between last x values
	 *@degree: Maximum exponent of variable
	 *@ *array: Coefficient array's pointer
	*/
	double base, top, root, fxRoot, fxBase, fxTop, epsilon, *array;
	int i, degree;
	
	system("clear");
	
	printf("Sayisal Analiz Kok Bulma Yontemleri Bisection Metodu");
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
	
	/*Read epsilon-base-top values*/
	printf("\nLutfen epsilon degerini giriniz:\t"); 
	scanf("%lf", &epsilon);
	printf("\nLutfen alt degeri giriniz(a):\t"); 
	scanf("%lf", &base);
	printf("\nLutfen ust degeri giriniz(b):\t"); 
	scanf("%lf", &top);
	
	do{
		
		/*
		 *Estimated value for root is 
		 *arithmetic mean of base and top values
		 */
		root = (base + top) / 2;
		
		/*Compute F(base), F(top), F(root) values*/
		fxBase = fx(array, degree, base);
		fxTop  = fx(array, degree, top);
		fxRoot = fx(array, degree, root);	
		
		/*Print x and F(x)*/
		printf("\nAlt deger: %lf\t F(x): %lf", base, fxBase);
		printf("\nUst deger: %lf\t F(x): %lf", top, fxTop);
		printf("\nKok: %lf\t F(x): %lf", root, fxRoot);
		printf("\n--------------------\n");
		/*If there is a zero crossing between two F(x) values, root must be inside that interval*/
		if(fxBase * fxRoot <= 0)
			top = root;
		else
			base = root;
			
	}while( fabs( fxRoot ) > epsilon );
	
	/*Print estimated root value*/
	printf("\n\n\nKok: %lf", root);
	
	free(array);
	
}/*bisection function ends*/