/*33) kendi hanelerine tam bolunebilen 11-99 arasi sayıları listeleyen program
*/

#include <stdio.h>

int main(){

	int i;

	for(i=11; i<100; i++){
		if((i%10 != 0)&&(i%(i%10) == 0)&&(i%(i/10)==0))
			printf("%d\n", i);
	}

	return 0;
}
