#include "Header.h"

double simpsonsRule(double a, double b, double (*f)(double));

const int maxDepth = 1000;
double adaptiveIntegration(double a, double b, double (*f)(double), double tol, int counter)
{
	counter++;
	//I2 splits the interval once for convergence checking purposes
	double I1 = simpsonsRule(a, b, f);
	double I2 = simpsonsRule(a, (a+b)/2.0, f) + simpsonsRule((a + b) / 2.0, b, f);

	if (counter == maxDepth)
	{
		printf("%s%d%s", "Warning, maximum recursion depth of ", maxDepth, " reached. Specified tolerance not guaranteed. \n");
		return I2;
	}

	// if the error is within tolerance, return I2
	double errest = abs(I1 - I2);
	if (errest < 15 * tol) return I2;

	// if the error is too large, split the interval further
	else return adaptiveIntegration(a, (a + b) / 2.0, f, tol, counter) + adaptiveIntegration((a + b) / 2.0, b, f, tol, counter);
}

/**
 * Simple integral approximation using Simpson's rule
 * 
 * \param a interval start
 * \param b interval end
 * \param f pointer to integrand function
 * \return 
 */
double simpsonsRule(double a, double b, double (*f)(double))
{
	return (b-a) / 6.0 * (f(a) + 4 * f((a + b) / 2.0) + f(b));
}

