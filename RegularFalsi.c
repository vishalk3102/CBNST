#include <stdio.h>
#include <math.h>
double fun(double x)
{
    return (x * x - 20);
}
int main()
{
    float x0, x1, x2, f0, f1, f2, e;
    int step = 1;
    printf("Enter two initial guesses:\n");
    // scanf("%f%f ", &x0, &x1);
    scanf("%f%f", &x0, &x1);

    printf("Enter the tolerable error \n");
    scanf("%f", &e);
    f0 = fun(x0);
    f1 = fun(x1);
    if (f0 * f1 > 0)
    {
        printf("incorrect initial guesses \n");
        return 0;
    }
    printf("\n step \t\t\t x0 \t \t \tx1 \t \t\t x2 \t \t\t f(x2)\n ");
    do
    {
        x2 = x0 - (x0 - x1) * f0 / (f0 - f1);
        f2 = fun(x2);
        printf("\n %d \t\t %.4f \t \t %.4f \t \t %.4f \t \t %.4f \n ", step, x0, x1, x2, f2);
        if (f0 * f2 < 0)
        {
            x1 = x2;
            f1 = f2;
        }
        else
        {
            x0 = x2;
            f0 = f2;
        }
        step = step + 1;
    } while (fabs(f2) > e);
    printf("\n Root is : %f", x2);

    return 0;
}