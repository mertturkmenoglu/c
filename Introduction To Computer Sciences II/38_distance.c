/*
 *38) Distance: Write a program which takes the coordinates 
 *of two points from the user and print the distance 
 *of those two points
 */
 
#include <stdio.h>
#include <math.h>

int main(void){
	
	int x1, x2, y1, y2;
	double distance;
		
	printf("\nX value of the first point: ");
	scanf("%d", &x1);
	
	printf("\nY value of the first point: ");
	scanf("%d", &y1);
	
	printf("\nX value of the second point: ");
	scanf("%d", &x2);
	
	printf("\nY value of the first point: ");
	scanf("%d", &y2);
	
	distance = (double) (y2-y1)*(y2-y1) + (x2-x1)*(x2-x1);
	distance = (double) sqrt(distance);
	
	printf("\nDistance: %lf", distance);
	
	return 0;
	
}
