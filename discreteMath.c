/*
 *Subsets of a given set
 *Finding powerset
 *Discrete Mathematics HW
 *Mert TURKMENOGLU
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



/*Function declaration*/
void binaryIncrement(int* , int);
int setElementControl(int* set, int index);



/*main function starts*/
int main(void) {

	/*
	 * Variable declarations
	 * @set: Pointer of the set array
	 * @cardinality: Cardinality of the set. Array length
	 * @i, @j: Loop indices
	 * @subSetNumber: Holds the subset number information
	 * @truth: Pointer of the truth array. Row of the truth table
	 * @comaFlag: Helps writing comas between elements.
	 */
	int *set, *truth;
	int cardinality, subSetNumber = 1, comaFlag;
	int i = 0, j;

	/*Read cardinality number*/
	do{
		
		printf("Please enter the cardinality of the set: ");
		scanf("%d", &cardinality);
		
	}while(cardinality<0);
	
	/*
	 * Dynamic memory allocation
	 * truth can be allocated with calloc function but 
	 * there is a problem with GCC 4.9.2 64-bit Compiler
	 * So I use malloc for either allocation 
	 * then i reset truth array manually
	 */
	set = (int*) malloc(cardinality * sizeof(int));
	truth = (int*) malloc(cardinality *sizeof(int));
	
	/*Error control*/
	if( (set == NULL) || (truth == NULL) ) {

		printf("\nError! Memory is not allocated!\n");
		exit(0);

	}
	
	for(i=0; i<cardinality; i++)
		*(truth+i) = 0;
		

	printf("Please enter only integer values");
	i=0;
	
	/*Read set elements*/
	while(i<cardinality) {
		
		printf("\nA[%d]:" , i+1);
		scanf("%d", (set+i));

		if(setElementControl(set, i))
			i++;
		else
			printf("You entered a wrong value. Values can not repeat. Please enter again.");

	}

	/*Subset number = 2^n*/
	subSetNumber = pow(2, cardinality);

	for(i=0; i<subSetNumber; i++) {

		printf("\n{");
		comaFlag = 0;
		
		for(j=0; j<cardinality; j++) {

			/*
			 *If corresponding truth value
			 *is 1 print the set element
			 */
			if ( *(truth+j) ) {

				if((i>2)&&(comaFlag))
					printf(",");
				
				printf("%d", *(set+j));
				comaFlag = 1;

			}

		}

		printf("}");

		binaryIncrement(truth, cardinality);

	}

	/*Frees the memory dynamicaly allocated*/
	free(set);
 	free(truth);

	/*Indicates successful termination*/
	return 0;

}/*main function ends*/



/*
 * binaryIncrement function starts
 * Takes an array (truth) and treats it like a binary number
 * Increases the number.
 * @param truth: Pointer of the truth array
 * @param cardinality: Cardinality of the set
 */
void binaryIncrement(int* truth, int cardinality) {
	
	
	/*
	 * Variable declaration
	 * i = Loop indice which starts from end of the binary number
	 * flag = loop control variable
	 */
	int i = cardinality-1, flag = 1;

	while(flag &&(i>=0)) {

		/*Increase the digit*/
		(*(truth+i))++;

		/*
		 * In binary system, a digit can take only 1 or 0 values. 
		 * It can not be 2D, so there is carry
		 * Controls the number, if it is equal to 2D, sets to zero and 
		 * jumps to next digit
		 */
		if(*(truth+i) == 2) {

			*(truth+i) = 0;
			i--;

		} else {
			/*There is no carry. Operations are completed*/
			flag = 0;
		}

	}

}/*binaryIncrement function ends*/



/*
 * setElementControl function starts
 * In a set, elements can not repeat
 * Function checks for repetiton
 * Returns 1 if there is no repetition
 * Returns 0 if there is repetiton
 * @param set: Pointer of the set array
 * @param index: Indicates the last elements location
 */
int setElementControl(int* set, int index) {

	int i = 0;

	while(i<index) {
		
		/* If numbers are not equal 
		 * continue to loop
		 * else return unsuccessful value
		 */
		if(*(set+i) != *(set+index))
			i++;
		else
			return 0;

	}
	
	/*Number does not repeat return successful value*/
	return 1;

}/*setElementControl function ends*/
