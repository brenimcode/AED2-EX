#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar os valores de duas variáveis
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função que particiona o array e retorna o índice do pivô
int particiona(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim]; // Considera o último elemento como pivô
    int i = (inicio - 1); // Índice do menor elemento

    for (int j = inicio; j <= fim - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (vetor[j] <= pivo) {
            i++; // Incrementa o índice do menor elemento
            troca(&vetor[i], &vetor[j]); // Troca vetor[i] com vetor[j]
        }
    }
    // Troca vetor[i + 1] com vetor[fim] (pivô)
    troca(&vetor[i + 1], &vetor[fim]);
    return (i + 1);
}

// Função Quicksort
void quicksort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        // Obtém o índice do pivô após particionar o vetor
        int indice_pivo = particiona(vetor, inicio, fim);

        // Ordena os subvetores antes e depois do pivô recursivamente
        quicksort(vetor, inicio, indice_pivo - 1);
        quicksort(vetor, indice_pivo + 1, fim);
    }
}

void QuickBasico(int *v, int n){
    quicksort(v,0,n-1);
}
void reorganiza(int vet[], int aux[], int n)
{
    for (int i = 0; i < n; i++)
        vet[i] = aux[i];
}

int main()
{
    int i, k5 = 1000;
    double tempo;
    time_t ini;
    time_t fim;
    /*   --- ALEATORIO ---            */
    
        int vetor5[k5];
        for (i = 0; i < k5; i++)
        {
            vetor5[i] = i;
        }
        
        printf("BASICO: ");
        ini = clock();
        QuickBasico(vetor5, k5);
        fim = clock();
        tempo = (double) (fim - ini) / CLOCKS_PER_SEC;
        printf("[%lf]\n", tempo);
        

    return 0;
}