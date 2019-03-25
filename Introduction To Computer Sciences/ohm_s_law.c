/*14) Klavyeden bir iletkenin direnciyle icinden akan akımı girildiğinde uçlarındaki gerilimi hesaplayan program (Ohm Kanunu)*/

#include <stdio.h>

int main(){

	float resistor, current, voltage;

	printf("Please enter resistor value: ");
	scanf("%f", &resistor);

	printf("Please enter current value: ");
	scanf("%f", &current);

	voltage = resistor*current;

	printf("Voltage: %f", voltage);

	return 0;
}