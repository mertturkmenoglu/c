/*
 * Mert TURKMENOGLU
 * Numerical Analysis Semester Project
 * IMPORTANT: This version uses windows.h library
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#define SIZE 100

double sum(int, int, double, double* , int);
double simpsonSum(int, int, double* , int, double, double);
double fx(double* , int, double);
double matrixSum(int, double [][SIZE], double [SIZE], int);
void graphic(); 
void bisection();
void regulaFalse();
void newtonRhapson();
void matrixInverse();
void gaussElimination();
void trapez(); 			
void simpson(); 		
void differentiation();	

/*Main function starts*/
int main(void){
	
	int selection;
	
	do{
		
		system("CLS");
		printf("Sayisal Analiz Araci\'na hosgeldiniz\n\n");
		
		printf("\n---Kok Bulma Yontemleri---\n\n");
		printf("\t1. Grafik Yontemi\n");
		printf("\t2. Yariya Bolme Yontemi\n");
		printf("\t3. Regula False Yontemi\n");
		printf("\t4. Newton Rhapson Yontemi\n");
		
		printf("\n---Matris Islemleri---\n\n");
		printf("\t5. Matris inversinin alinmasi\n");
		
		printf("\n---Dogrusal Denklem Takimlarinin Cozumu---\n\n");
		printf("\t6. Gauss Eliminasyon Yontemi\n");
		
		printf("\n---Numerik Integral---\n\n");
		printf("\t7. Trapez Yontemi\n");
		printf("\t8. Simpson Yontemi\n");
		
		printf("\n---Numerik Turev---\n\n");
		printf("\t9. Numerik Turev\n");
	
		do{
		
			printf("\nLutfen isleminizin numarasini giriniz: ");
			scanf("%d", &selection);
		
		}while((selection<1)||(selection>9));
	
		switch(selection){
		
			case 1: graphic(); 			break;
			case 2: bisection(); 		break;
			case 3: regulaFalse(); 		break;
			case 4: newtonRhapson(); 	break;
			case 5: matrixInverse(); 	break;
			case 6: gaussElimination(); break;
			case 7: trapez(); 			break;
			case 8: simpson(); 			break;
			case 9: differentiation(); 	break;
	
		}
		
		printf("\nAraci tekrar kullanmak icin 1 giriniz. Cikis icin 0 giriniz\n");
		scanf("%d", &selection);
		
	}while(selection == 1);
	
	/*Indicates successful termination*/
	return 0;
	
}/*Main function ends*/



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
	
	system("CLS");
	
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
	
	system("CLS");
	
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
	
	system("CLS");
	
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
	
	system("CLS");
	
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



/*matrixInverse function starts*/
void matrixInverse(void){
	
	int i, j, k, size;
	double temp;
	double matrix[SIZE][SIZE];
	double inverseMatrix[SIZE][SIZE];
	double identityMatrix[SIZE][SIZE];
	double unifiedMatrix[SIZE][2*SIZE];
	
	system("CLS");
	
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
	double mtr[SIZE][SIZE], temp, c[SIZE], root[SIZE];
	int i, j, k, l, size;
	
	system("CLS");
	
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
	
	system("CLS");
	
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
	
	system("CLS");
	
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
	
	system("CLS");
	
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



/*matrixSum function starts*/
double matrixSum(int start, double mtr[][SIZE], double root[SIZE], int size){
	
	int i=start-1,j;
	double sum=0;
	
	for(j=start; j<size; j++)
		sum += mtr[i][j] * root[j];
		
	return sum;
	
}/*matrisSum function ends*/

