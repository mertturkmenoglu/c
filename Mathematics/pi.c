#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main() {
	
	srand(time(NULL));
	int i, xpos, ypos;
	double pi, dist, r = 500, circle = 0, other = 0 ;
	
	for (i = 1; i < 1000000; i++) {
	
	xpos = rand() % 1000;
	ypos = rand() % 1000;
	
	dist = sqrt(xpos * xpos + ypos * ypos);
	
	if (dist <= r)
		circle++;
	else
		other++;
		
	pi = 4 * (circle / (other));
	
	}
	
	printf("%f", pi);
	
	return 0;	
	
}
