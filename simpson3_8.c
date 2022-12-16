#include <stdio.h>
#include <math.h>

#define f(x) 1 / (1 + pow(x, 2))

int main()
{
    float lower, upper, k, stepSize, integration = 0.0;
    int i, subInterval;
    printf("\nEnter the value of lower limit :");
    scanf("%f", &lower);
    printf("\nEnter the value of upper limit :");
    scanf("%f", &upper);
    printf("\nEnter the value of sub interval :");
    scanf("%d", &subInterval);

    stepSize = (upper - lower) / subInterval;
    integration = f(lower) + f(upper);

    // integration = 3h/8 ((y0 + yn) + 3(y1 + y2 + y4 +...) + 2(y3 + y6 + y9 +......))
    for (int i = 1; i <= subInterval - 1; i++)
    {
        k = lower + i * stepSize;
        if (i % 3 == 0)
        {
            integration = integration + (2 * f(k));
        }
        else
        {
            integration = integration + (3 * f(k));
        }
    }
    integration = integration * ((3 * stepSize) / 8);
    printf("\nThe required value of integration is :%f", integration);
    return 0;
}