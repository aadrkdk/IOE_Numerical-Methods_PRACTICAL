/* Gauss Elimination Method */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, j, k;

    /* Input : size of matrix and elements of Augmented Matrix. */
    printf("\nEnter the number of unknowns(n): ");
    scanf("%d", &N);
    float a[N][N + 1], x[N], Ratio, sum;
    printf("Enter elements of the augmented matrix row-wise:\n");
    for (i = 0; i < N; i++)
        for (j = 0; j < N + 1; j++)
        {
            printf("\ta[%d][%d] = ", i + 1, i + 1); //
            scanf("%f", &a[i][j]);
        }

    /* Change into upper triangular form */
    for (j = 0; j < N - 1; j++)
        for (i = j + 1; i < N; i++)
        {
            Ratio = a[i][j] / a[j][j];
            for (k = 0; k < N + 1; k++)
                a[i][k] = a[i][k] - a[j][k] * Ratio;
        }

    /* Displaying Upper Triangular Matrix */
    printf("\nThe upper triangular matrix is:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N + 1; j++)
            printf("%10.4f", a[i][j]);
        printf("\n");
    }

    /* Perform Back Substitution */
    for (i = N - 1; i >= 0; i--)
    {
        sum = 0;
        for (j = i + 1; j < N; j++)
            sum = sum + a[i][j] * x[j];
        x[i] = (a[i][N] - sum) / a[i][i];
    }

    /* Display solution */
    printf("\nThe solution is: \n");
    for (i = 0; i < N; i++)
        printf("\tx[%d] = %7.4f\n", i + 1, x[i]);

    return 0;
}