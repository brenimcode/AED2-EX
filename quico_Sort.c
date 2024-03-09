#include <stdio.h>
#include <stdlib.h>



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
        printf("i = [%d]  j = [%d]\n",i,j);
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


int main(){
    int vet[5] = {1,2,3,4,5};

    quicksort(vet,0,5);



    return 0;
}