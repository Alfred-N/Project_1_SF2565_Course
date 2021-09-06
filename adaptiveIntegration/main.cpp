// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Header.h"

//integrand
double f(double x) { return 1 + sin(exp(3 * x)); }

int main()
{
	//array of different tolerances
	double* tols = new double[]{ 1e-2, 1e-3, 1e-4 };

	for (double *tol = tols; tol < &tols[3]; tol++)
	{
		//call the adaptive integration algorithm
		double I = adaptiveIntegration(-1, 1, f, *tol);
		//print result
		printf("%s%.0e", "tol = ", *tol);
		printf("%s%.10f%s", " adaptive I = ", I, "\n");
	}
    
    return EXIT_SUCCESS;
}

