#include <stdio.h>

void SelectionSort(int vet[], int t)
{
    int i, menor, indice,j;
    for (i = 0; i < t-1; i++)
    {
        // ACHA O MENOR ELEMENTO
        menor = vet[i];
        indice = i;
        for (j = i; j < t; j++)
        {
            if (vet[j] < menor)
            {
                menor = vet[j];
                indice = j;
            }
        }
        // Troca o menor elemento com o i-ésimo elemento
        vet[indice] = vet[i]; // o menor é vet[indice]
        vet[i] = menor;
    }
}

int main()
{
    int vet[6] = {6, 5, 4, 3, 2, 1};
    int i;
    // SELECTION SORT EM ORDEM CRESCENTE
    SelectionSort(vet,6);

    for (i = 0; i < 6; i++)
    {
        printf("[%d] ", vet[i]);
    }
    printf("\n");
}