#include <stdio.h>
int main()
{
    float a[10][10], x[10], ratio;
    int n;
    printf("\n Enter the size of matrix :");
    scanf("%d", &n);
    printf("\nEnter the values of matrix :");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= (n + 1); j++)
        {
            printf("\na[%d][%d] =", i, j);
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
                for (int k = 1; k <= (n + 1); k++)
                {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }

    printf("\n The solution is  :");
    for (int i = 1; i <= n; i++)
    {
        x[i] = a[i][n + 1] / a[i][i];
        printf("x[%d] =%f :", i, x[i]);
    }

    return 0;
}