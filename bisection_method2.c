/*
    Bisection Method
*/
#include <stdio.h>
#include <math.h>

float f(float x)
{
    return (x * x * x - 4 * x - 9);
}

void bisect(float *x, float a, float b, int *itr)
{
    *x = (a + b) / 2;
    ++(*itr);
    printf("Iteration no. %3d X = %7.5f\n", *itr, *x);
}

int main()
{
    int itr = 0, maxitr;
    float x, a, b, aerr, x1;
    printf("Enter the values of a and b:\n");
    scanf("%f%f", &a, &b);
    printf("Enter allowed error: ");
    scanf("%f", &aerr);
    printf("Enter maximum iterations: ");
    scanf("%d", &maxitr);
    printf("\n");

    bisect(&x, a, b, &itr);

    do
    {
        if (f(a) * f(x) < 0)
            b = x;
        else
            a = x;
        bisect(&x1, a, b, &itr);
        if(fabs(x1-x)<aerr)
        {
            printf("\nAfter %d iterations, root = %6.4f\n\n",itr,x1);
            return 0;
        }
        x = x1;

    } while (itr < maxitr);
    printf("Solution does not converge, iterations not sufficient\n");
    return 1;
}