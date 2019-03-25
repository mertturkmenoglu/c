/*Assignment 3 Question 4
 *N element array 
 *Use function to read array elements
 *Another function returns memory address
 *of extremum element
 */

#include <stdio.h>
#include <stdlib.h>

/*Function prototypes*/

int* fextremum(int* , int );
void readArray(int* , int );

/*Main function starts*/
int main(){
	
	/*Variable declarations*/
	int *array, len, *location;
	
	/*Read array length*/
	printf("Please enter array size: ");
	scanf("%d", &len);
	
	array = (int*) malloc(len * sizeof(int));
	
	if(array == NULL){
		printf("\nError!Memory is not allocated\n");
		exit(0);
	}
	
	readArray(array, len);
	location = fextremum(array, len);
	
	printf("\nLocation: %x", location);
	printf("\nValue: %d", *(location));
	
	free(array);
	
	/*Indicates successful termination*/
	return 0;
	
}/*Main function ends*/

/*readArray function starts*/
void readArray(int* array, int len){
	
	/*This function reads array elements*/
	
	int i;
	
	for(i=0; i<len; i++){
		printf("\nPlease enter %d -th element: ", i+1);
		scanf("%d", (array+i));
	}
	
}/*readArray function ends*/

/*fextremum function starts*/
int* fextremum(int* array, int len){
	
	/*This function finds minumum element
	 *of the array and return its
	 *memory location to main function
	 */
	 
	/*Variable declarations*/
	int i, j, min;

	/*Shows memory locations*/
	for(i=0; i<len; i++)
		printf("\nArray[%d]= %d\t\tLocation= %x", i+1, *(array+i), (array+i));
	
	/*Finds minimum element*/
	min=0;
	for(i=1; i<len; i++){
		if( *(array+i) < *(array+min) )
			min = i;
	}
	
	return (array+min);

}/*fextremum function ends*/
