/*Assignment 3 Question 2
 *Read N
 *N element array
 *Read elements and add them
 *to array.
 *Array must be sorted.
 */
 
#include <stdio.h>
#include <stdlib.h>

/*Function prototypes*/
void fprint(int* array,int);
void fadd(int, int*,int);

/*Main function starts*/
int main(){
	
	/*Variable declarations*/
	int temp, i, *array,len;
	
	//printf("DO NOT ENTER 0\n");
	
	printf("Please enter array size: ");
	scanf("%d", &len);
	
	array = (int*) malloc(len * sizeof(int));
	
	if(array == NULL){
		printf("\nError! Memory is not allocated\n");
		exit(0);
	}
	
	printf("\n");
	
	
	/*Read numbers and add them to array*/
	for(i=0; i<len; i++){
		
		printf("Please enter the %d -th number: ", i+1);
		scanf("%d", &temp);
		
		fadd(temp, array, len);
		fprint(array, len);
		
		printf("\n");
		
	}
	
	free(array);
	
	/*Indicates successful termination*/
	return 0;
	
}/*Main function ends*/

/*fadd function starts
 *@param temp: Entered number
 *@param array[]: Array that contains other numbers 
 */
void fadd(int temp, int* array,int len){
	
	/*Variable declarations*/
	int i = 0, j;
	
	/*Find this numbers position in this array*/
	while(( *(array+i) <= temp )&&( *(array+i) !=0 ))
		i++;
		
	/*Shift every number on the 
	 *right side of this number
	 *to 1 block right
	 */
	for(j=len-2; j>=i; j--)
		*(array+j+1) = *(array+j);

	/*Add number to array*/
	*(array+i) = temp;
	
}/*fadd function ends*/

/*fprint function starts*/
void fprint(int* array,int len){
	
	int i;

	/*Print numbers with 1 tab gap*/
	for(i=0; i<len; i++)
		printf("%d\t", *(array+i));
	
}/*fprint function ends*/
