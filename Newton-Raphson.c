/*
    Newton Raphson Method
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float);
float df(float);
void newtonraphson(float x0, int maxitr, float err);

int main()
{
    int maxitr;
    float x0, err;
    printf(" Enter [x0, allowed error and maximum iterations] respectively: \n");
    scanf("%f%f%d", &x0, &err, &maxitr);
    newtonraphson(x0, maxitr, err);
    return 0;
}

float f(float x) // function f(x)
{
    return x * log(x) - 1.2;
}

float df(float x) // derivvative of function f(x)
{
    return 1 + log(x);
}

void newtonraphson(float x0, int maxitr, float err)
{
    for (int i = 1; i <= maxitr; i++)
    {
        float h = f(x0) / df(x0);
        float x1 = x0 - h;
        printf(" Iteration No.  %3d,\tX = %9.6f\n", i, x1);
        if (fabs(h) < err)
        {
            printf("\n No. of iterations = %d\n Tolerable error = %8.6f\n Root\t\t = %8.6f\n\n", i, err, x1);
            exit(1);
        }
        x0 = x1;
    }
    printf("\n Iterations Not sufficient, solution does not converge\n\n");
}