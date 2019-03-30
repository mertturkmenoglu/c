/*
 * Mert TURKMENOGLU
 * Numerical Analysis Semester Project
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "numeric.h"

int main(void) {
	
	int selection;
	
	do {
		
		system("clear");
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
	
		do {
		
			printf("\nLutfen isleminizin numarasini giriniz: ");
			scanf("%d", &selection);
		
		} while ((selection < 1) || (selection > 9));
	
		switch (selection) {
		
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
		
	} while (selection == 1);
	
	/*Indicates successful termination*/
	return 0;
	
}/*Main function ends*/
