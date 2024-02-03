#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao_implementa.c"

#define N5 50000
#define N10 100000

int main(){
    time_t ini;
    time_t fim;
    time_t ini2;
    time_t fim2;
    double tempo_total;
    int *v_50mil, i,*v_100mil;
    v_50mil = (int *) malloc(N5 * sizeof(int));
    v_100mil = (int *) malloc(N10* sizeof(int));

    int *aux50 = malloc(N5*sizeof(int));
    int *aux100 = malloc(N10*sizeof(int));

    for (i = 0; i < N5; i++)
    {
        v_50mil[i] = rand() % N5;
        aux50[i] = v_50mil[i];
    }

    for (i = 0; i < N10; i++)
    {
        v_100mil[i] = rand() % N10;
        aux100[i] = v_100mil[i];
    }

    double tempo_total2;

    ini = clock();
    bubbleSort(v_50mil, N5);
    fim = clock();

    ini2 = clock();
    bubbleSort(v_100mil, N10);
    fim2 = clock();

    tempo_total = (double)(fim - ini) / CLOCKS_PER_SEC;
    tempo_total2 = (double)(fim2 - ini2) / CLOCKS_PER_SEC;
    printf("BUBBLESORT - Tempo total PARA 50MIL = [%f]\n", tempo_total);
    printf("BUBBLESORT - Tempo total PARA 100MIL = [%f]\n", tempo_total2);

    
    printf("\n----\n");

// SHELLSORT

   for (i = 0; i < N5; i++)
    {
        v_50mil[i] = aux50[i]; 
    }
    for (i = 0; i < N10; i++)
    {
        v_100mil[i] = aux100[i]; 
    }

    ini = clock();
    shellsort(v_50mil, N5);
    fim = clock();

    ini2 = clock();
    shellsort(v_100mil, N10);
    fim2 = clock();

    tempo_total = (double)(fim - ini) / CLOCKS_PER_SEC;
    tempo_total2 = (double)(fim2 - ini2) / CLOCKS_PER_SEC;
    printf("shellsort - Tempo total PARA 50MIL = [%f]\n", tempo_total);
    printf("shellsort - Tempo total PARA 100MIL = [%f]\n", tempo_total2);
    
    printf("\n----\n");


// MERGESORT
    for (i = 0; i < N5; i++)
    {
        v_50mil[i] = aux50[i]; 
    }
    for (i = 0; i < N10; i++)
    {
        v_100mil[i] = aux100[i]; 
    }

    ini = clock();
    m_sort(v_50mil, N5);
    fim = clock();

    ini2 = clock();
    m_sort(v_100mil, N10);
    fim2 = clock();

    tempo_total = (double)(fim - ini) / CLOCKS_PER_SEC;
    tempo_total2 = (double)(fim2 - ini2) / CLOCKS_PER_SEC;
    printf("MERGESORT - Tempo total PARA 50MIL = [%f]\n", tempo_total);
    printf("MERGESORT - Tempo total PARA 100MIL = [%f]\n", tempo_total2);
    
    printf("\n----\n");

}