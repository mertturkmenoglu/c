/*32) 7 den buyuk bir tamsayiyi 3a+5b seklinde yazan program.
*/

#include <stdio.h>

int main(){

    int number, i, check=0;

    printf("Please enter the number: ");
    scanf("%d", &number);

    i=0;
    while((i<number)&&(check != 1)){
        if( (number-3*i)%5 == 0 )
            check = 1;
        i++;
    }
	i--;
    printf("%d = 3*%d + 5*%d", number, i, (number-(i)*3)/5);

    return 0;

}
