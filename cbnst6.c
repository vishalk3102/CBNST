#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n;
    float a[100][101] = {0};
    printf("Enter the number of equations you have\n");
    scanf("%d", &n);
    int in_i = 0; // index i for setting the row int xyz=0;
    while (n--)
    {
        char s[200];
        printf("Enter the equation\n");
        scanf("%s", s);
        // printf("%s\n",s); bool flag=false;
        int num = 0;
        int cont = 0; // for setting the value of the constant int sign=1;
        for (int i = 0; i < strlen(s); i++)
        {
            if (flag && (s[i] >= '0' && s[i] <= '9'))
            {
                cont = cont * 10 + (s[i] - '0');
                // printf("%d ",cont);
            }
            if (s[i] == '=') // now constant needs to be evaluated flag=true;
                else if (s[i] == '-') sign = -1;

            else if (s[i] == 'x')
            {
                // alt[ptr++]=sign*num==0?1:sign*num; a[in_i][0]=sign*num==0?1:sign*num; num=0;
                xyz++;
                sign = 1;
            }
            else if (s[i] == 'y')
            {
                // alt[ptr++]=sign*num==0?1:sign*num; a[in_i][1]=sign*num==0?1:sign*num;
                num = 0;
                if (xyz == 0)
                    a[in_i][0] = 0;
                xyz++;
                sign = 1;
            }
            else if (s[i] == 'z')
            {
                // alt[ptr++]=sign*num==0?1:sign*num; a[in_i][2]=sign*num==0?1:sign*num;
                num = 0;
                if (xyz == 0)
                {
                    a[in_i][0] = 0;
                    a[in_i][1] = 0;
                }
                if (xyz == 1)
                {
                    if (a[in_i][1] == '\0')
                        a[in_i][1] = 0;
                    else
                        a[in_i][0] = 0;
                }
                sign = 1;
                xyz++;
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + (s[i] - '0');
            }
        }
        a[in_i][3] = sign * cont;
        in_i++;
    }
    // float a[3][4], t; float t;
    int i, j, k;
    printf("Equation 1: (%.0f)x+(%.0f)y+(%.0f)z=%.0f\n", a[0][0], a[0][1], a[0][2], a[0][3]);
    printf("Equation 2: (%.0f)x+(%.0f)y+(%.0f)z=%.0f\n", a[1][0], a[1][1], a[1][2], a[1][3]);
    printf("Equation 3: (%.0f)x+(%.0f)y+(%.0f)z=%.0f\n", a[2][0], a[2][1], a[2][2], a[2][3]);
    printf("\n\n");
    printf("Augmented Matrix: \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)

        {
            printf("%f ", a[i][j]);
        }
        printf(" \n");
    }
    printf("\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i != j)

            {
                t = a[j][i] / a[i][i];

                for (k = 0; k < 4; k++)
                    a[j][k] = a[j][k] - (a[i][k] * t);
            }
        }
    }
    printf("Final Matrix form : \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)

        {
            printf("\t %.0f", a[i][j]);
        }
        printf("\n");
    }
    printf("\n\nSolution is :\n ");
    for (i = 0; i < 3; i++)
    {
        printf("%f ", a[i][3] / a[i][i]);
    }
}
