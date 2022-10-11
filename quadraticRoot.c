#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c, D, root1, root2, realPart, imgPart;
    int ch;
    do
    {
        printf("Enter the coefficient of the equation :\n");
        scanf("%lf %lf %lf", &a, &b, &c);
        D = ((b * b) - (4 * a * c));
        if (D == 0)
        {
            root1 = root2 = (-b) / (2 * a);
            printf("\nEquations has real and equal roots :");
            printf("\nRoot1 and Root2 are : %.2lf", root1);
        }
        else if (D > 0)
        {
            root1 = (-b + sqrt(D)) / (2 * a);
            root2 = (-b - sqrt(D)) / (2 * a);
            printf("\nEquations has real and unequal roots :");
            printf("\nRoot1 : %.2lf", root1);
            printf("\nRoot2 : %.2lf", root2);
        }
        else
        {
            printf("\nEquations has  unreal roots  ");
            realPart = (-b / (2 * a));
            imgPart = (sqrt(-D) / (2 * a));
            printf("\nRoot1 : %.2lf+%.2lfi", realPart, imgPart);
            printf("\nRoot2 : %.2lf-%.2lfi", realPart, imgPart);
        }
        printf("\nEnter 1 to continue process :");
        scanf("%d", &ch);
    } while (ch == 1);

    return 0;
}