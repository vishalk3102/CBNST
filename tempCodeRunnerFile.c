#include <stdio.h>
#include <math.h>

int main()
{
    float x[100], y[100], xp, p, yp = 0;
    int n;
    printf("\nEnter the number of data :");
    scanf("%d", &n);
    printf("\nEnter the data :");
    for (int i = 1; i <= n; i++)
    {
        printf("\n x[%d] :", i);
        scanf("%f", &x[i]);
        printf("\n y[%d] :", i);
        scanf("%f", &y[i]);
    }
    printf("\nEnter the interpolation point :");
    scanf("%f", &xp);

    for (int i = 1; i <= n; i++)
    {
        p = 1;
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {

                p = p * (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp = yp + p * y[i];
    }
    printf("\nThe interpolated value  at %f is %f", xp, yp);
    return 0;
}