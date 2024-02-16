#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int *v, int a, int b)
{
    int aux;
    aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

int particao(int vet[], int ini, int fim)
{
    int elemento_pivo = vet[fim];
    int i = ini; // i é a barra amarela
    int j;
    for (j = ini; j < fim; j++)
    {
        if (vet[j] <= elemento_pivo)
        {
            // trocar o elemento i com j e andar com a barra i
            troca(vet, j, i);
            i++;
        }
    }
    // por fim troca o 1º elemento (>) que PIVO com PIVO. para assim ficar:
    //  [1,2,3,12,5,6,PIVO] -> [1,2,3,PIVO,5,6,4] PIVO=4
    troca(vet, vet[i], vet[fim]);
    return i;
}

void quicksort(int vet[], int ini, int fim)
{
    if (ini < fim)
    {
        // [i] e [] já está ordenado.
        int pivo;
        pivo = particao(vet, ini, fim);
        quicksort(vet, ini, pivo - 1);
        quicksort(vet, pivo + 1, fim);
    }
}

void QuickBasico(int vet[], int n)
{
    quicksort(vet, 0, n - 1);
}

// ALEATORIZADO
int pivo_aleatorio(int ini, int fim)
{
    double r;                      // pega um pivo aleatorio em [ini,fim]
    r = (double)rand() / RAND_MAX; // valor entre 0.01 e 0.99
    return (int)(ini + r * (fim - ini));
}

void quickAleatorizado(int vet[], int ini, int fim)
{
    if (ini < fim)
    {
        int pivo;
        troca(vet, pivo_aleatorio(ini, fim), ini);
        pivo = particao(vet, ini, fim);
        quickAleatorizado(vet, ini, pivo - 1);
        quickAleatorizado(vet, pivo + 1, fim);
    }
}

void quickAleatorio(int v[], int t)
{
    quickAleatorizado(v, 0, t - 1);
}

// MEDIANA

void quicksort_mediana_tres(int v[], int esq, int dir)
{
    if (dir <= esq)
        return;
    int i;
    troca(v, (esq + dir) / 2, esq + 1);
    if (v[esq] > v[esq + 1])
        troca(v, esq, esq + 1);
    if (v[esq] > v[dir])
        troca(v, esq, dir);
    if (v[esq + 1] > v[dir])
        troca(v, esq + 1, dir);
    i = particao(v, esq + 1, dir - 1);
    quicksort_mediana_tres(v, esq, i - 1);
    quicksort_mediana_tres(v, i + 1, dir);
}

void mediana_de_tres(int *v, int n)
{
    quicksort_mediana_tres(v, 0, n - 1);
}

// Tres partes:
void particao3(int v[], int esq, int dir, int *lt, int *gt)
{
    int pivot = v[esq]; // Pivot é o primeiro elemento do array
    int i = esq + 1;
    *lt = esq;
    *gt = dir;

    int k = esq + 1;
    while (k <= *gt)
    {
        if (v[k] < pivot)
        {
            troca(v, k, *lt);
            (*lt)++;
            k++;
        }
        else if (v[k] > pivot)
        {
            troca(v, k, *gt);
            (*gt)--;
        }
        else
        {
            k++;
        }
    }
}
void quicksort3(int v[], int esq, int dir)
{
    if (esq >= dir)
        return; // Caso base

    int lt, gt;
    particao3(v, esq, dir, &lt, &gt); // Particiona o array em 3 partes

    quicksort3(v, esq, lt - 1); // Ordena a parte menor que o pivô
    quicksort3(v, gt + 1, dir); // Ordena a parte maior que o pivô
}
void quicksort_tres_partes(int *v, int t)
{
    quicksort3(v, 0, t - 1);
}

void reorganiza(int vet[], int aux[], int n)
{
    for (int i = 0; i < n; i++)
        vet[i] = aux[i];
}

int main()
{
    int i, k5 = 5000;
    double tempo;
    time_t ini;
    time_t fim;
    /*   --- ALEATORIO ---            */
    for (int c = 0; c < 2; c++)
    {
        printf("---------------------------%d' Parte-------------------------------\n",c+1);
        int *vetor5 = (int *)malloc(k5 * sizeof(int));
        int *aux5 = (int *)malloc(k5 * sizeof(int));
        printf("\n-----    VETOR TAMANHO %d ALEATORIO:    -----\n\n", k5);
        for (i = 0; i < k5; i++)
        {
            vetor5[i] = rand() % k5;
            aux5[i] = vetor5[i];
        }
        /* APLICA ALGORITMOS e REEORDENA*/
        printf("BASICO: ");
        ini = clock();
        QuickBasico(vetor5, k5);
        fim = clock();
        tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
        printf("[%lf]\n", tempo);
        reorganiza(vetor5, aux5, k5);

        printf("Aleatorio: ");
        ini = clock();
        quickAleatorio(vetor5, k5);
        fim = clock();
        tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
        printf("[%lf]\n", tempo);
        reorganiza(vetor5, aux5, k5);

        printf("Mediana de tres: ");
        ini = clock();
        mediana_de_tres(vetor5, k5);
        fim = clock();
        tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
        printf("[%lf]\n", tempo);
        reorganiza(vetor5, aux5, k5);

        printf("Particao em tres vias: ");
        ini = clock();
        quicksort_tres_partes(vetor5, k5);
        fim = clock();
        tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
        printf("[%lf]\n", tempo);
        /*   --- ORDENADO ---            */
        printf("\n-----    VETOR TAMANHO %d ORDENADO:    -----\n\n", k5);
        for (i = 0; i < k5; i++)
        {
            vetor5[i] = i;
            aux5[i] = vetor5[i];
        }
        /*  APLICA ALGORITMOS e REEORDENA */
        printf("BASICO: ");
        ini = clock();
        QuickBasico(vetor5, k5);
        fim = clock();
        tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
        printf("[%lf]\n", tempo);
        reorganiza(vetor5, aux5, k5);

        printf("Aleatorio: ");
        ini = clock();
        quickAleatorio(vetor5, k5);
        fim = clock();
        tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
        printf("[%lf]\n", tempo);
        reorganiza(vetor5, aux5, k5);

        printf("Mediana de tres: ");
        ini = clock();
        mediana_de_tres(vetor5, k5);
        fim = clock();
        tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
        printf("[%lf]\n", tempo);
        reorganiza(vetor5, aux5, k5);

        printf("Particao em tres vias: ");
        ini = clock();
        quicksort_tres_partes(vetor5, k5);
        fim = clock();
        tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
        printf("[%lf]\n", tempo);

        /*   --- INVERTIDA ---            */
        printf("\n-----    VETOR TAMANHO %d INVERTIDO:    -----\n\n", k5);
        for (i = k5 - 1; i >= 0; i--)
        {
            vetor5[i] = i;
            aux5[i] = vetor5[i];
        }
        /* APLICA ALGORITMOS e REEORDENA*/
        printf("BASICO: ");
        ini = clock();
        QuickBasico(vetor5, k5);
        fim = clock();
        tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
        printf("[%lf]\n", tempo);
        reorganiza(vetor5, aux5, k5);

        printf("Aleatorio: ");
        ini = clock();
        quickAleatorio(vetor5, k5);
        fim = clock();
        tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
        printf("[%lf]\n", tempo);
        reorganiza(vetor5, aux5, k5);

        printf("Mediana de tres: ");
        ini = clock();
        mediana_de_tres(vetor5, k5);
        fim = clock();
        tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
        printf("[%lf]\n", tempo);
        reorganiza(vetor5, aux5, k5);

        printf("Particao em tres vias: ");
        ini = clock();
        quicksort_tres_partes(vetor5, k5);
        fim = clock();
        tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
        printf("[%lf]\n", tempo);

        /*     --- MUITAS REPETICOES ---          */
        printf("\n-----    VETOR TAMANHO %d C/ MUITAS REPETICOES:    -----\n\n", k5);
        for (i = 0; i < k5; i += 2)
        {
            vetor5[i] = rand() % k5;
            vetor5[i + 1] = vetor5[i];
            aux5[i] = vetor5[i];
            aux5[i + 1] = vetor5[i];
            // Os elementos i e i+1 recebem o mesmo elemento, assim tendo muitas repetições.
        }

        /* APLICA ALGORITMOS e REEORDENA*/
        printf("BASICO: ");
        ini = clock();
        QuickBasico(vetor5, k5);
        fim = clock();
        tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
        printf("[%lf]\n", tempo);
        reorganiza(vetor5, aux5, k5);

        printf("Aleatorio: ");
        ini = clock();
        quickAleatorio(vetor5, k5);
        fim = clock();
        tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
        printf("[%lf]\n", tempo);
        reorganiza(vetor5, aux5, k5);

        printf("Mediana de tres: ");
        ini = clock();
        mediana_de_tres(vetor5, k5);
        fim = clock();
        tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
        printf("[%lf]\n", tempo);
        reorganiza(vetor5, aux5, k5);

        printf("Particao em tres vias: ");
        ini = clock();
        quicksort_tres_partes(vetor5, k5);
        fim = clock();
        tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
        printf("[%lf]\n", tempo);

        free(vetor5);
        free(aux5);
        k5 = 50000;
        
    }

    return 0;
}