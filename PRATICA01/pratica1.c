#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int V[], int tam)
{
    int i, j, temp;
    for (i = 0; i < tam - 1; i++)
    {
        int ver = 0;
        for (j = 0; j < tam - i - 1; j++)
        {
            if (V[j] > V[j + 1])
            {
                temp = V[j];
                V[j] = V[j + 1];
                V[j + 1] = temp;

                ver = 1;
            }
        }
        if (ver == 0)
        {
            break;
        }
    }
}

void InsertionSORT(int vet[], int tam)
{
    int i, j, temp;
    // Se ordenado O(N), se não O(N^2)
    for (i = 1; i < tam; i++)
    {
        temp = vet[i];
        for (j = i - 1; j >= 0 && vet[j] > temp; j--)
        {
            vet[j + 1] = vet[j];
        }
        vet[j + 1] = temp;
    }
}

void SelectionSort(int vet[], int t)
{
    int i, menor, indice, j;
    for (i = 0; i < t - 1; i++)
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

void shellsort(int v[], int t)
{
    int i, j, aux, h = 1;

    while (h < t / 3)
        h = 3 * h + 1;
    while (h > 0)
    {
        for (i = h; i < t; i++)
        {
            aux = v[i];
            j = i;

            while (j >= h && aux < v[j - h])
            {
                v[j] = v[j - h];
                j = j - h;
            }
            v[j] = aux;
        }
        h = (h - 1) / 3;
    }
}

#define N 10000

int main(void)
{
    time_t ini;
    time_t fim;
    double tempo_total;
    int *v, i;
    v = (int *)malloc(N * sizeof(int));
    
    for (i = 0; i < N; i++)
    {
        v[i] = rand() % N;
    }
    //BUBBLESORT
    
    ini = clock();
    bubbleSort(v, N);
    fim = clock();

    tempo_total = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("BUBBLESORT - Tempo total = [%f]\n", tempo_total);

    
    printf("\n----\n");
    
// INSERTIONSORT
    for (i = 0; i < N; i++)
    {
        v[i] = rand() % N;
    }

    ini = clock();
    InsertionSORT(v, N);
    fim = clock();

    tempo_total = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("INSERTIONSORT Tempo total = [%f]\n", tempo_total);
    
    printf("\n----\n");

// SELECTIONSORT
    for (i = 0; i < N; i++)
    {
        v[i] = rand() % N;
    }

    ini = clock();
    SelectionSort(v, N);
    fim = clock();

    tempo_total = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("SELECTIONSORT Tempo total = [%f]\n", tempo_total);
    
    printf("\n----\n");

// SHELLSORT
    for (i = 0; i < N; i++)
    {
        v[i] = rand() % N;
    }

    ini = clock();
    shellsort(v, N);
    fim = clock();

    tempo_total = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("SHELLSORT Tempo total = [%f]\n", tempo_total);
    
    printf("\n----\n");

    return 0;
}