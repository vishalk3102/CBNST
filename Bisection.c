#include <stdio.h>
#include <math.h>

// #define e 2.718281828459045
// float fun(float x)
// {
//     return (3 * x + sin(x) - exp(x));
// }
float fun(float x)
{
    return (x * x - 20);
}
void bisection(float *x, float a, float b, int *itr)
{
    *x = (a + b) / 2;
    ++(*itr);
    printf("Iteration no %d X = %7.5f \n", *itr, *x);
}

int main()
{
    int itr = 0, maxItr;
    float x, a, b, err, x1;
    printf("Enter the value of a,b,err and max iteration :");
    scanf("%f %f %f %d", &a, &b, &err, &maxItr);

    if (fun(a) * fun(b) > 0)
    {
        printf("Root not possible");
        return 0;
    }
    bisection(&x, a, b, &itr);
    do
    {
        if (fun(a) * fun(x) < 0)
        {
            b = x;
        }
        else
        {
            a = x;
        }
        bisection(&x1, a, b, &itr);
        if (fabs(x1 - x) < err)
        {
            printf("After %d the iterations ,root = %6.4f \n", itr, x1);
            return 0;
        }
        x = x1;
    } while (itr < maxItr);
    printf("Error");
    return 0;
}