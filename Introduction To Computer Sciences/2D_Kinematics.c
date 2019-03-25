/*11) Yerden yuksekligi ve ilk hizi girilen cismin havada kalma suresini, yatayda alacagi yolu ve yere carpma hizini hesaplayan program
*/


/* h= 1/2 g t^2

	t = (2h/g)^1/2
	x = v.t
	vx vy
	vx = x
	vy = gt



*/
#include <stdio.h>
#include <math.h>

int main(){

	const float g = 9.8;

	float height, velocity, time, xdist, vy, vfinal;

	printf("Please enter height: ");
	scanf("%f", &height);

	printf("Please enter velocity: ");
	scanf("%f", &velocity);

	time = sqrt(2*height/g);
	xdist = velocity*time;
	vy = g*time;
	vfinal = sqrt(vy*vy+velocity*velocity);

	printf("Time: %f", time);

	printf("X distance: %f", xdist);

	printf("velocity: %f", vfinal);

	return 0;



}