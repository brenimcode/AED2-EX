#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int busca_sequencial_ordenada(int v[], int n, int chave_busca)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (v[i] == chave_busca)
        {
            return i; // chave_busca encontrada
        }
        else if (v[i] > chave_busca)
        {
            return -1; // interrompe busca
        }
    }
    return -1; // chave nao encontrada
}

int busca_sequencial(int v[], int n, int chave_busca)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (v[i] == chave_busca)
        {
            return i;
        }
    }
    return -1;
}

int busca_binaria(int v[], int n, int chave_busca){
    int inf =0, sup = n-1,meio;
    //versao iterativa
    while(inf<=sup){
        meio = (inf+sup)/2;
        if(chave_busca == v[meio])
            return meio;
        else{
            if(chave_busca > v[meio]){
                inf = meio+1;
            }
            else{
                sup = meio-1;
            }
        }
    }
    return -1;
}

void reorganiza_vetor(int vet[], int aux[], int n)
{
    for (int i = 0; i < n; i++)
        vet[i] = aux[i];
}

int main(){
    double tempo;
    time_t ini;
    time_t fim;
    int num_elementos;

    int *vetor5 = (int *)malloc(num_elementos * sizeof(int)); //vetor normal
    int *aux5 = (int *)malloc(num_elementos * sizeof(int)); //vetor auxiliar
    



    return 0;
}
