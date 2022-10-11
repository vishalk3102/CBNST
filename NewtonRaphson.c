#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
float fun(float x)
{
    return (x * x - 6);
}
float derivative(float x)
{
    return (2 * x);
}
int main()
{
    int maxItr, i;
    float x, x0, x1, x2;
    printf("Enter the maximum nnumber of iteration \n");
    scanf("%d", &maxItr);
    do
    {
        printf("Enter the value of x1 nad x2 :");
        scanf("%f%f", &x1, &x2);
        if (fun(x1) * fun(x2) > 0)
        {
            printf("interval are invalid\n");
            continue;
        }
        else
        {
            printf("Root lie between %f and %f \n", x1, x2);
            break;
        }
    } while (1);

    if (fabs(fun(x1)) < fabs(fun(x2)))
    {
        x0 = x1;
    }
    else
    {
        x1 = x2;
    }

    for (int i = 1; i <= maxItr; i++)
    {
        x = x0 - (fun(x0) / derivative(x0));
        if (fabs(x - x0) < EPSILON)
        {
            printf("iterations=%d  final Root =%f\n", i, x);
            return 0;
        }
        printf("iterations=%d   Root =%f\n", i, x);
        x0 = x;
    }
    printf("Root=%f  Total iteration =%d\n", x, --i);

    return 0;
}