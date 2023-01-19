/*
    Curve Fitting : y = a + bx
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 30

int main()
{

    int n;
    float x[N], y[N], sumx = 0, sumy = 0, sumx2 = 0, sumxy = 0;

    printf("\n\tFitting  Straight Line[y = a + b*x]\n");

    printf("\nEnter the number of points: ");
    scanf("%d", &n);
    printf("Enter respective values of x and y:\n");
    for (int i = 1; i <= n; i++)
    {
        printf("x[%d] = ",i);
        scanf("%f", &x[i]);
        printf("y[%d] = ",i);
        scanf("%f", &y[i]);
    }

    printf("The values you entered are as:\n");
    printf("\tx\t|\ty\n");
    printf("\t----------------------\n");
    for (int i = 1; i <= n; i++)
        printf("\t%0.2f\t|\t%0.2f\n", x[i], y[i]);

    for (int i = 1; i <= n; i++)
    {
        sumx = sumx + x[i];
        sumx2 = sumx2 + x[i] * x[i];
        sumy = sumy + y[i];
        sumxy = sumxy + x[i] * y[i];
    }

    float b = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx);
    float a = (sumy - b * sumx) / n;

    printf("\n\tValue of a = %0.4f\n", a);
    printf("\tValue of b = %0.4f\n", b);
    printf("The fitted regression Equation(y = a + bx) is: y = %0.4f + %0.4f*x\n\n", a, b);
}