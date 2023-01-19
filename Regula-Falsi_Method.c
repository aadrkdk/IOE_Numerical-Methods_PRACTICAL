/*
    Description: METHOD OF FALSE POSITION or REGULA-FALSI METHOD or INTERPOLATION METHOD
                 to find the real root of a non-linear equation.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*  Define function f(x)    */
// #define f(x) x *log10(x) - 1.2
#define f(x) cos(x) - x *exp(x)
// #define f(x) pow(x, 3) - 2 * x - 5
// #define f(x) x *exp(x) - cos(x)
// #define f(x) tan(x) + tanh(x)
// #define f(x) pow(x, 3) - 4
// #define f(x) 3*x + sin(x) - exp(x)
// #define f(x) exp(x)-x*x*x - cos(25x)

void regula(float *x, float x0, float x1, float fx0, float fx1, int *itr);

int main()
{
    /*  Input   */
    float x0, x1, x2, x3, err;
    int itr = 0, maxitr;
    printf(" Enter initial guesses:\n");
    printf(" x0 = ");
    scanf("%f", &x0);
    printf(" x1 = ");
    scanf("%f", &x1);
    printf(" Enter tolerable error: ");
    scanf("%f", &err);
    printf(" Enter maximum Iterations: ");
    scanf("%d", &maxitr);

    /*  Iteration table header  */
    printf("\n\t-------------------------------------------------------------------------");
    printf("\n\tIterations\tx0\t\tx1\t\tx2\t\tf(x2)");
    printf("\n\t-------------------------------------------------------------------------\n");

    //     /*  Apply METHOD OF FALSE POSITION  */
    regula(&x2, x0, x1, f(x0), f(x1), &itr);
    do
    {
        if (f(x0) * f(x2) < 0)
            x1 = x2;
        else
            x0 = x2;
        regula(&x3, x0, x1, f(x0), f(x1), &itr);
        if (fabs(x3 - x2) < err)
        {
                printf("\n\n\tApproximate Root  = %0.9f", x3);
                printf("\n\tTolerable Error   = %f", err);
                printf("\n\tNo. of Iterations = %d\n\n", itr);
                return 0;
        }
        x2 = x3;
    } while (itr<maxitr);

    printf("Solution does not converge, Iterations not sufficient\n\n");

 return 0;
}

void regula(float *x, float x0, float x1, float fx0, float fx1, int *itr)
{
    *x = x0 - (x1 - x0) * fx0 / (fx1 - fx0);
    ++(*itr);
    printf("\n\t%d.\t\t%f\t%f\t%f\t%f", *itr, x0, x1, *x, f(*x));
}



