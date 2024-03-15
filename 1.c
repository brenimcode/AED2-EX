#include <stdio.h>
#include <stdlib.h>

int main()
{
    int M[4][4] = {{16, 3, 2, 13},
                   {5, 10, 11, 8},
                   {9, 6, 7, 12},
                   {4, 15, 14, 1}};
    int n = 4, i, j, magico = 1;
    int soma1 = 0, soma2 = 0, soma3 = 0;

    for (i = 0; i < n; i++)
    {
        soma1 += M[i][i];
        soma2 += M[i][n - 1 - i];
    }

    if (soma1 != soma2)
    {
        magico = 0;
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            soma2 = 0;
            soma3 = 0;
            for (j = 0; j < n; j++)
            {
                soma2 += M[i][j];
                soma3 += M[j][i];
            }
            if (soma2 != soma3 || soma1 != soma2)
            {
                magico = 0;
                break;
            }
        }
    }

    if (magico)
    {
        printf("A matriz e um quadrado magico.\n");
    }
    else
    {
        printf("A matriz nao e um quadrado magico.\n");
    }

    return 0;
}
