#include <stdio.h>
#include <math.h>
#define f(x) 1 / (1 + pow(x, 2))
int main()
{
    float upper, lower, stepSize, k, integration = 0.0;
    int i, subinterval;
    printf("\nEnter the value of lower limit :");
    scanf("%f", &lower);
    printf("\nEnter the value of upper limit :");
    scanf("%f", &upper);
    printf("\nEnter the value of sub interval :");
    scanf("%d", &subinterval);

    stepSize = (upper - lower) / subinterval;
    integration = (f(lower) + f(upper)) / 2;

    // integration = h[(y0 + yn)/2 + (y1 + y2 + ...... + yn-1)]
    for (int i = 1; i <= subinterval - 1; i++)
    {
        k = lower + i * stepSize;
        integration = integration + f(k);
    }
    integration = integration * stepSize;
    printf("\nThe required answer is : %f", integration);
    return 0;
}