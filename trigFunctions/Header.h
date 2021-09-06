#pragma once
#define _USE_MATH_DEFINES
using namespace std;
#include <iostream>
#include <cmath>
#include <cassert>
#include <stdexcept>

/**
 * Calculate cosine \n
 * Recursively evaluates the Taylor expansion using Horner's scheme
 *
 * \param x_in the point the polynomial is evaluated at
 * \param N number of terms starting from 0
 * \param idx counter to keep track of the current term
 * \param prev previous coefficient
 * \param useMod if true apply modulo 2*pi to input. improves result for large inputs
 * \return cos(x_in)
 */
double cosTaylor(double x_in, int N, int idx = 0, double prev = 1, bool useMod = false);
/**
 * Calculate sine \n
 * Recursively evaluates the Taylor expansion using Horner's scheme
 *
 * \param x_in the point the polynomial is evaluated at
 * \param N number of terms starting from 0
 * \param idx counter to keep track of the current term
 * \param prev previous coefficient
 * \param useMod if true apply modulo 2*pi to input. improves result for large inputs
 * \return sin(x_in)
 */
double sinTaylor(double x_in, int N, int idx = 0, double prev = 1, bool useMod = false);

/**
 * Verify that the error is bounded the next term in the Tailor expansion.
 *
 * \param myTrig1 value of sinTaylor(x_in, N)
 * \param myTrig2 value of sinTaylor(x_in, N+1)
 * \param x_in the point of evaluation
 * \param trigFunc either "cos" or "sin"
 */
void verifyErrorBounded(double myTrig1, double myTrig2, double x_in, string trigFunc = "sin");

