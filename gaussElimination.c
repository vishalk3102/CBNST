#include <stdio.h>
int main()
{
    float a[10][10], x[10], ratio;
    int n;
    printf("\nEnter the size of the matrix :");
    scanf("%d", &n);
    printf("\n Enter the data of the matrix :");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= (n + 1); j++)
        {
            printf("a[%d][%d] =", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                ratio = a[j][i] / a[i][i];
            }
            for (int k = 1; k <= (n + 1); k++)
            {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }

    x[n] = a[n][n + 1] / a[n][n];

    for (int i = n - 1; i >= 1; i--)
    {
        x[i] = a[i][n + 1];
        for (int j = i + 1; j <= n; j++)
        {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }

    printf("\n The solution is :");
    for (int i = 1; i <= n; i++)
    {
        printf("\n x[%d] = %f", i, x[i]);
    }

    return 0;
}
