#include <stdio.h>
#include <math.h>

#define f(x) 1 / (1 + pow(x, 2))

int main()
{
    float lower, upper, k, stepSize;
    float integration = 0;
    int i, subInterval;
    printf("\nEnter the value of lower limit :");
    scanf("%f", &lower);
    printf("\nEnter the value of upper limit :");
    scanf("%f", &upper);
    printf("\nEnter the value of sub Interval :");
    scanf("%d", &subInterval);

    stepSize = (upper - lower) / subInterval;
    integration = (f(lower) + f(upper));

    // integration = h/3 ((y0 + yn) + 4(y1 + y3 + y5 +...) + 2(y2 + y4 + y6 +......))
    for (int i = 1; i <= subInterval - 1; i++)
    {
        k = lower + i * stepSize;
        if (i % 2 == 0)
        {

            integration = integration + 2 * (f(k));
        }
        else
        {
            integration = integration + 4 * (f(k));
        }
    }
    integration = integration * stepSize / 3;
    printf("\nThe required annswer is :%f", integration);
    return 0;
}