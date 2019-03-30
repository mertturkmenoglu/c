#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "numeric.h"

/*regulaFalse function starts*/
void regulaFalse(void){
	
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
	double base,top,root,fxBase,fxRoot,fxTop,B,T,epsilon, *array;
	int i,degree;
	
	system("clear");
	
	printf("Sayisal Analiz Kok Bulma Yontemleri Regula False Metodu");
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
		
		fxBase = fx(array, degree, base);
		fxTop = fx(array, degree, top);	
		root = (top*fxBase-fxTop*base)/(fxBase-fxTop);
		
		printf("%lf", root);
		fxRoot = fx(array, degree, root);
		
		printf("\nAlt: %lf\tF(a): %lf", base,fxBase);
		printf("\nUst: %lf\tF(b): %lf", top, fxTop);
		printf("\nKok: %lf\tF(c): %lf", root, fxRoot);
		printf("\n--------------\n");
		
		if(fxBase*fxRoot<=0)
			top = root;
		else
			base = root;
			
	}while(fabs(fxRoot)>epsilon);
	
	printf("\n\n\nKok:\t%lf", root);
	
	free(array);
	
}/*regulaFalse function ends*/