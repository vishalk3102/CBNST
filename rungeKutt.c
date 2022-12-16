#include <stdio.h>
#include <math.h>

#define f(x, y) (y * y - x * x) / (y * y + x * x)
int main()
{
    float x0, y0, k1, k2, k3, k4, k, xn, yn, h;
    int i, n;

    printf("\nEnter the initial value of x0 :");
    scanf("%f", &x0);
    printf("\nEnter the initial value of y0 :");
    scanf("%f", &y0);
    printf("\nEnter the calculation point xn :");
    scanf("%f", &xn);
    printf("\nEnter the  value  of step  :");
    scanf("%d", &n);

    h = (xn - x0) / n;

    for (int i = 0; i < n; i++)
    {
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + h / 2, y0 + k1 / 2);
        k3 = h * f(x0 + h / 2, y0 + k2 / 2);
        k4 = h * f(x0 + h, y0 + k3);
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        yn = y0 + k;
        printf("\n x0 : %f \t y0:%f \t yn:%f", x0, y0, yn);
        y0 = yn;
        x0 = x0 + h;
    }

    return 0;
}
