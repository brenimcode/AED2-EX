#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

#define MAXN 10000

typedef struct{
    int vetor[MAXN];
    int tamanho_reap;
    int tamanho_vetor;
}V;

// EFICIENTES:

max_heapify(V a,int i){
        int dir,esq,maior;
        if(esq <= a.tamanho_reap && a.vetor[esq] > a.vetor[i]){
            maior = esq;
        }
        else{
            maior = i;
        }
        if(dir <= a.tamanho_reap && a.vetor[dir] > a.vetor[maior]){
            maior = dir;
        }
        if(maior != i){
            troca(a.vetor[i], a.vetor[maior]);
            max_heapify(a,maior);
        }


}

void build_max_heap(V a){
    a.tamanho_reap = a.tamanho_vetor;
    int i;
    for (i = a.tamanho_vetor/2; i >=1; i++)
    {
        max_heapify(a,i);
    }
    
}

void heapsort(V a, int N){
    build_max_heap(a);
    int i;
    for (i = a.tamanho_vetor; i >= 2; i--)
    {
        troca(V[1], V[i]);
        a.tamanho_reap--;
        max_heapify(V,1);
    }
    
}

void merge(int *V,int aux_ordenado[],int esq,int meio, int dir){
    int esq_fim = meio-1;  // [ini_left] ... [esq_fim]  Topo é inileft
    int i_aux = esq; // esse é o inicio do vetor ordenado
    int tamanho = dir-esq+1;

    int i;

    while( esq<=esq_fim && meio <= dir ){ // Repita enquanto tenha elementos na pilha esquerda ou na direita
        if(V[esq] <= V[meio]){
            aux_ordenado[i_aux] = V[esq];
            esq++; //Para seguir em frente na "pilha"
            i_aux++; // Para substituir o elemento da frente, nao o mesmo.
        }
        else{
            aux_ordenado[i_aux] = V[meio];
            meio++;
            i_aux++;
        }
    }

    while(meio <= dir){ //Caso uma das pilhas acaba, deve se copiar o restante da outra, pois n tem comparação
        aux_ordenado[i_aux] = V[meio];
        i_aux++;
        meio++;
    }

    while(esq <= esq_fim){//Caso uma das pilhas acaba, deve se copiar o restante da outra, pois n tem comparação
        aux_ordenado[i_aux] = V[esq];
        i_aux++;
        esq++;
    }

    for( i=0;i< tamanho; i++){
        V[dir] = aux_ordenado[dir];
        dir--;
    }
    
}

void mergeSort(int v[],int aux_ordenado[], int esq,int dir){
    int meio;
    if(dir > esq){ // O fim é maior q o inicio, ou seja se o fim == inicio, o vetor tem tamanho 1 e está ordenado, se não, ocorreu um erro
        meio = (esq+dir)/2;
        mergeSort(v,aux_ordenado,esq,meio); //Divide o vetor em dois
        mergeSort(v,aux_ordenado,meio+1,dir);
        merge(v,aux_ordenado,esq,meio+1,dir); //Junta as 2 sub-listas ordenando-as comparando as pilhas

    }

}

void m_sort(int* v, int n){
    int aux[n];

    mergeSort(v,aux,0,n-1);
}

// SIMPLES:

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