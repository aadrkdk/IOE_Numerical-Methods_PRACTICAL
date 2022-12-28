/*
    Description: Write a program to find a real root of the non-linear equation:
                 4 * exp(-x) * sin(x) - 1 = 0 using Bisection method
*/
#include <stdio.h>
#include <math.h>

// define problem to be solved
#define f(x) 4 * exp(-x) * sin(x) - 1

// define  tolerable error
#define e 0.00001

float a, b, c;
float fa, fb, fc;
int step = 1;

void input();
void table_header();
void display_result();
void table_data();

int main()
{
    input();
    if (fa * fb > 0)
    {
        printf(" Incorrect Guesses!\n");
        input();
    }
    table_header();
    do
    {
        fa = f(a);
        fb = f(b);
        c = (a + b) / 2;
        fc = f(c);
        if (fa * fc < 0)
            b = c;
        else
            a = c;
        table_data();
        step = step + 1;
    } while (fabs(fc) > e);
    display_result();
    return 0;
}

void input()
{
    printf("\n\tIn Bisection Method, Enter:\n");
    printf("\tLower guess(a): ");
    scanf("%f", &a);
    printf("\tUpper guess(b): ");
    scanf("%f", &b);
}

void table_header()
{
    printf("\n\t\t\t Iteration Table\n");
    printf("\t\t\t-----------------\n\n");
    printf("\t|---------|--------------|----------------------|\n");
    printf("\t|Iteration|\tRoot(c)\t |\tf(c)\t\t|\n");
    printf("\t|---------|--------------|----------------------|\n");
}

void table_data()
{
    printf("\t|   %d\t  |\t%0.4f\t |\t%f\t|\n", step, c, fc);
}

void display_result()
{
    printf("\t|---------|--------------|----------------------|\n");
    printf("\n\tNo. of Iterations = %d", step - 1);
    printf("\n\tApproximate Root  = %f", c);
    printf("\n\tf(c)\t\t  = %f\n", fc);
    printf("\tTolerable Error   = %f\n\n", e);
}