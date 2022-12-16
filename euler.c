#include <stdio.h>

#define f(x, y) (x + y + x * y)

int euler(float x0, float y0, float h, float x, int n)
{
    float y = 0.0;
    while (x0 < x)
    {
        y = y0 + h * f(x0, y0);
        y0 = y;
        x0 = x0 + h;
    }
    printf("The approximate solution at %f is %f", x, y);
}
int main()
{
    float x0, y0, x, h;
    int n;
    printf("\n Enter the initial value of x0 :");
    scanf("%f", &x0);
    printf("\n Enter the initial value of y0 :");
    scanf("%f", &y0);
    printf("\n Enter the  calculation point xn :");
    scanf("%f", &x);
    printf("\n Enter the value of step  :");
    scanf("%d", &n);

    h = (x - x0) / n;
    euler(x0, y0, h, x, n);

    return 0;
}