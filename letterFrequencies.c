/*Assignment 3 Question 3
 *Read an expression
 *Find consecutive letter frequencies
 *Return values to main function
 *as a single string value
 */
 
#include <stdio.h>
#include <string.h>
#define SIZE 100

/*Function prototype*/
void freq(char [], int, char []);

/*Main function starts*/
int main(){
	
	/*Variable declarations
	 *@expression: Original expression
	 *@compressed: Keeps frequencies
	 *@len: Length of string
	 */
	char expression[SIZE];
	char compressed[SIZE];
	int len;
	
	/*Read expression*/
	printf("Please enter your expression: ");
	scanf("%[^\n]s", expression);
	
	/*Compute string length*/
	len = strlen(expression);
	
	/*Find frequencies*/
	freq(expression, len, compressed);
	
	/*Print results*/
	printf("\nYour expression was   : %s", expression);
	printf("\nCompressed version is : %s", compressed);
	
	/*Indicates successful termination*/
	return 0;
	
}/*Main function ends*/

/*freq function starts
 *@param expression[]: Original expression
 *@param compressed[]: Keeps frequencies
 *@param len: Length of string
 */
void freq(char expression[], int len, char compressed[]){

 	/*Variable declarations
 	 *@counter: Frequency of letter
 	 *@temp[]: Temporary string to use for strcat and sprintf
 	 */
	int i, counter=1;
	char temp[5];
	
	/*Compare each letter with next one and compute frequencies*/
	for(i=0; i<len; i++){
		if(expression[i] == expression[i+1])
			counter++;
		else{
			/*Turn frequency value and the letter 
			 *to string and 
		     *concatenate to @compressed string
		     */
			sprintf(temp, " %dx", counter);
			strcat(compressed, temp);
			sprintf(temp, "%c ", expression[i]);
			strcat(compressed, temp);
			counter = 1;
		}
	}
	
}/*freq function ends*/
