// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Header.h"

int main()
{
    int N = 5;
    printf("%s %d %s", "N = ", N, "\n");
    double* xs = new double[7]{-1,1,2,3,5,10};

    for (double* x = xs; x!= &xs[6]; x++)
    {
        double mySin = sinTaylor(*x, N), mySin2 = sinTaylor(*x, N + 1);
        verifyErrorBounded(mySin, mySin2, *x, "sin");
    }

    for (double* x = xs; x != &xs[6]; x++)
    {
        double myCos = cosTaylor(*x, N), myCos2 = cosTaylor(*x, N + 1);
        verifyErrorBounded(myCos, myCos2, *x, "cos");
    }
    return 0;
}

