/*
    Description: Secant Method to find the real root of a non-linear equation.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*  Define function f(x)  */
#define f(x) x *exp(x) - cos(x)
// #define f(x) tan(x) + tanh(x)
// #define f(x) pow(x, 3) - 4
// #define f(x) 3*x + sin(x) - exp(x)
// #define f(x) exp(x)-x*x*x - cos(25x)

int main()
{
    /*  Input   */
    float x0, x1, err;
    int maxitr;
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

    /*  Apply Secant Method */
    int itr = 1;
    float x2, fx0, fx1, fx2;
    do
    {
        fx0 = f(x0);
        fx1 = f(x1);
        if (fx0 == fx1)
        {
            printf("\n Mathematical Error!\n");
            exit(1);
        }
        x2 = x1 - (x1 - x0) * fx1 / (fx1 - fx0);
        fx2 = f(x2);
        printf("\t%d.\t\t%f\t%f\t%f\t%f\n", itr, x0, x1, x2, fx2);
        x0 = x1;
        x1 = x2;
        fx0 = fx1;
        fx1 = fx2;
        itr++;
        if (itr > maxitr)
        {
            printf("\n The Solution doesnot converge.\n");
            exit(1);
        }
    } while (fabs((fx2 > err)));
    printf("\n\tApproximate Root  = %0.9f", x2);
    printf("\n\tTolerable Error   = %f", err);
    printf("\n\tNo. of Iterations = %d\n\n", itr - 1);
    return 0;
}
