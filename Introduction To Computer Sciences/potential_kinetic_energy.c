/*10) Klavyeden kutlesi hizi ve yerden yuksekligi verilen maddenin potansiyel ve kinetik enerjisini hesaplayan program*/

#include <stdio.h>

int main(){

	float mass, velocity, height, potential, kinetic;
	const float g = 9.8;
	printf("Please enter mass: ");
	scanf("%f", &mass);

	printf("Please enter velocity: ");
	scanf("%f", &velocity);

	printf("Please enter height: ");
	scanf("%f", &height);

	potential =mass*g*height;

	kinetic = (0.5)*mass*velocity*velocity;

	printf("Potential energy: %f\n", potential);
	printf("Kinetic energy  : %f\n", kinetic);

	return 0; 
}