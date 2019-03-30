#ifndef NUMERIC_H
#define NUMERIC_H

#ifndef NUMERICSIZE
#define NUMERICSIZE 100
#endif

double sum(int, int, double, double* , int);
double simpsonSum(int, int, double* , int, double, double);
double fx(double* , int, double);
double matrixSum(int, double [][NUMERICSIZE], double [NUMERICSIZE], int);
void graphic(); 
void bisection();
void regulaFalse();
void newtonRhapson();
void matrixInverse();
void gaussElimination();
void trapez(); 			
void simpson(); 		
void differentiation();	

#endif