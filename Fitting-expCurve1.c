/*
    Curve Fitting : y = a*e^(bx)
*/
#include <stdio.h>
#include <math.h>

#define S 50

int main()
{
    int n, i;
    float x[S], y[S],Y[S], sumX = 0, sumX2 = 0, sumY = 0, sumXY = 0;


    printf("\n\tFitting  Curve[y = a*e^(bx)]\n");
    /* Input */
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter data:\n");
    for (i = 1; i <= n; i++)
    {
        printf("x[%d]=", i);
        scanf("%f", &x[i]);
        printf("y[%d]=", i);
        scanf("%f", &y[i]);
    }
    for (i = 1; i <= n; i++)
    {
        Y[i] = log(y[i]);
    }
    /* Calculating Required Sum */
    for (i = 1; i <= n; i++)
    {
        sumX = sumX + x[i];
        sumX2 = sumX2 + x[i] * x[i];
        sumY = sumY + Y[i];
        sumXY = sumXY + x[i] * Y[i];
    }
    /* Calculating a and b */
    float b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    float A = (sumY - b * sumX) / n;
    float a = exp(A);

    /* Displaying value of a and b */
    printf("\nValues are: a = %0.2f and b = %0.2f", a, b);
    printf("\nEquation of best fit is: y = %0.2f + %0.2fx \n", a, b);

    return (0);
} 































