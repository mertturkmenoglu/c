/*Assignment 3 Question 1
 *Read a mathematical expression
 *and check balanced parantheses
 */
 
#include <stdio.h>
#include <string.h>
#define SIZE 100

/*Function prototypes*/
void push(char, int*, char []);
int pop(char, int*, char []);
int isEmpty(int* );

/*Main function starts*/
int main(){
	
	/*Variable declarations
	 *@expression[]: Mathematical expression given by user
	 *@stack[]: Add or remove parantheses 
	 *@len: Length of expression
	 *@index: Stack index. 
	 */
	char expression[SIZE];
	char stack[SIZE];
	int i = 0, len, index = -1, check = 1;
	
	/*Read mathematical expression*/
	printf("Please enter your mathematical expression: ");
	scanf("%[^\n]s", expression);
	
	/*Find expression length*/
	len = strlen(expression);
	
	/*Search for parantheses
	 *add them into stack 
	 *or remove their pair from stack
	 *find if parantheses balanced or not
	 */
	while((i<len+1)&&(check == 1)){
	
		/*If element is a bracket*/
		switch(expression[i]){
			
			/*Add to stack*/
			case '{': push('{', &index, stack); break;
			case '[': push('[', &index, stack); break;
			case '(': push('(', &index, stack); break;
			
			/*Remove from stack*/
			case ')': check = pop(')', &index, stack); break;
			case ']': check = pop(']', &index, stack); break;
			case '}': check = pop('}', &index, stack); break;
		}
		i++;
	}
	
	/*Print results*/
	if((check == 1)&&(index == -1))
		printf("\nBalanced\n");
	else
		printf("\nNot balanced\n");
	
	/*Indicates successful termination*/		
	return 0;
	
}/*Main function ends*/

/*push function starts
 *@param element: Parantheses to add
 *@param *index: Memory address of index variable
 *@param stack[]: Stack to operate
 */
void push(char element, int* index, char stack[]){
	/*First increase the index
	 *then add the element
	 *to the stack
	 */
	(*index)++;
	stack[*index] = element;
	
}/*push function ends*/

/*pop function starts
 *@param element: Parantheses to check
 *@param *index: Memory address of index variable
 *@param stack[]: Stack to operate
 */
int pop(char element, int* index, char stack[]){
	
	/*If stack is empty, return false*/
	if(isEmpty(index) != 1){
		
		/*Check element and the top data item*/
		if((element == '}')&&(stack[*index] == '{'))
			(*index)--; 
		else if((element == ']')&&(stack[*index] == '['))		
				(*index)--;
			else if((element == ')')&&(stack[*index] == '('))
					(*index)--;
				else
					return 0;
		
		/*An element has added to the stack*/
		return 1;					
	}
	
	return 0;
	
}/*pop function ends*/

/*isEmpty function starts
 *@param *index: Memory address of index variable
 */
int isEmpty(int* index){
    
	/*Stack must be empty
	 *if stack index is equal to -1
	 *and can not pop any item
	 *from stack
	 */	
	if(*index == -1)
		return 1;
	else 
		return 0;
		
}/*isEmpty function ends*/
