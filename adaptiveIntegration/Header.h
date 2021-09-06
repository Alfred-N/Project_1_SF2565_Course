//Header file containing function declarations and dependencies
#pragma once
#include <iostream>
#include <cmath>
using namespace std;

/**
 * Integrate using adaptive Simpson quadrature
 *
 * \param a interval start
 * \param b interval end
 * \param f pointer to integrand function
 * \param tol error tolerance
 * \param counter counts recursion depth. needs to be equal to 0 on initial function call
 * \return approximate integral between a and b
 */
double adaptiveIntegration(double a, double b, double (*f)(double), double tol=1e-12, int counter =0);