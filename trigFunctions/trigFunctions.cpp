#include "Header.h"
double getSinCoeff(int n, double prev_coeff);
double getCosCoeff(int n, double prev_coeff);


double cosTaylor(double x_in, int N, int idx, double prev, bool useMod)
{
	if (N == 0) { return 1; } //special case for N = 0
	if (idx == N) { return prev + x_in * x_in * getCosCoeff(idx, prev); } //return the last term
	else if (idx == 0) // return the value of the polynomial as a function of the next parenthesis
	{
		if (useMod) { x_in = fmod(x_in, 2 * M_PI); }
		return cosTaylor(x_in, N, idx + 1, prev);
	}
	else //return the value of the current parenthesis as a function of the next parenthesis
	{
		double currCoeff = getCosCoeff(idx, prev);
		return prev + x_in * x_in * cosTaylor(x_in, N, idx + 1, currCoeff);
	}
}

double sinTaylor(double x_in, int n, int idx, double prev, bool useMod)
{
	if (n == 0) { return x_in; } //special case for N = 0
	if (idx == n) { return prev + x_in * x_in * getSinCoeff(idx, prev); } //return the last term

	else if (idx == 0) // return the value of the polynomial as a function of the next parenthesis
	{
		if (useMod) { x_in = fmod(x_in, 2 * M_PI); }
		return x_in * sinTaylor(x_in, n, idx+1, prev);
	}
	else  //return the value of the current parenthesis as a function of the next parenthesis
	{
		double currCoeff = getSinCoeff(idx, prev);
		return prev + x_in * x_in * sinTaylor(x_in, n, idx + 1, currCoeff);
	}
	
}

/**
 * Calculate Taylor coefficient of sine \n
 * Utilizes a recurrence relation to avoid explicit evaluation of the factorial.
 * 
 * \param n index of the current term
 * \param prev_coeff previous Taylor coefficient
 * \return current Taylor coefficient
 */
double getSinCoeff(int n, double prev_coeff)
{
	assert(n >= 0 && "n must be geq than 0");
	if (n == 0) { return 1; }
	else { return (double)-1 / ((2 * n + 1) * (2 * n)) * prev_coeff; }
}

/**
 * Calculate Taylor coefficient of cosine \n
 * Utilizes a recurrence relation to avoid explicit evaluation of the factorial.
 *
 * \param n index of the current term
 * \param prev_coeff previous Taylor coefficient
 * \return current Taylor coefficient
 */
double getCosCoeff(int n, double prev_coeff)
{
	assert(n >= 0 && "n must be geq than 0");
	if (n == 0) { return 1; }
	else { return (double)-1 / ((2 * n) * (2 * n - 1)) * prev_coeff; }
}


void verifyErrorBounded(double myTrig1, double myTrig2, double x_in, string trigFunc)
{
	double stdTrig;
	if (trigFunc == "sin") { stdTrig = sin(x_in); }
	else if (trigFunc == "cos")	{ stdTrig = cos(x_in); }
	else { throw std::invalid_argument("Trig function must be cos or sin"); }
	
	double error = abs(myTrig1 - stdTrig);
	double nextTerm = abs(myTrig2 - myTrig1);
	const double tol =1e-8;

	if (error<=nextTerm || abs(error-nextTerm)<tol)
	{
		cout << trigFunc << "Taylor(" << x_in << ") = "  << flush;
		printf("%.5f", myTrig1);
		printf("%s%.2e%s%.2e%s", "\t (OK!) E(", error, ") <= N+1 term (", nextTerm, ")\n");
	}
	else
	{
		cout << trigFunc << "Taylor(" << x_in << ") = " << flush;
		printf("%.5f", myTrig1);
		printf("%s%.2e%s%.2e%s", "\t (BAD.) Error (", error, ") > N+1 term (", nextTerm, ")\n");
	}
}