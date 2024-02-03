

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N10 1000

void bubbleMedia(int V[], int tam,int* compara, int* troca){
    int i, j, temp;
    for (i = 0; i < tam - 1; i++)
    {
        int ver = 0;
        for (j = 0; j < tam - i - 1; j++)
        {
            (*compara)++;
            if (V[j] > V[j + 1])
            {
                temp = V[j];
                V[j] = V[j + 1];
                V[j + 1] = temp;
                (*troca)++;
                ver = 1;
            }
        }
        if (ver == 0)
        {
            break;
        }
    }
}

void merge(int *V,int aux_ordenado[],int esq,int meio, int dir,int* compara,int* troca){
    int esq_fim = meio-1;  // [ini_left] ... [esq_fim]  Topo é inileft
    int i_aux = esq; // esse é o inicio do vetor ordenado
    int tamanho = dir-esq+1;

    int i;
    (*compara)++;
    while( esq<=esq_fim && meio <= dir ){ // Repita enquanto tenha elementos na pilha esquerda ou na direita
        (*compara)++;
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
    (*compara)++;
    while(meio <= dir){ //Caso uma das pilhas acaba, deve se copiar o restante da outra, pois n tem comparação
        (*compara)++;
        aux_ordenado[i_aux] = V[meio];
        i_aux++;
        meio++;
    }
    (*compara)++;
    while(esq <= esq_fim){//Caso uma das pilhas acaba, deve se copiar o restante da outra, pois n tem comparação
        (*compara)++;
        aux_ordenado[i_aux] = V[esq];
        i_aux++;
        esq++;
    }
    (*troca)+=tamanho;
    for( i=0;i< tamanho; i++){
        V[dir] = aux_ordenado[dir];
        dir--; 
    }
    
}

void mergeSort(int v[],int aux_ordenado[], int esq,int dir,int* compara,int* troca){
    int meio;
    if(dir > esq){ // O fim é maior q o inicio, ou seja se o fim == inicio, o vetor tem tamanho 1 e está ordenado, se não, ocorreu um erro
        meio = (esq+dir)/2;
        mergeSort(v,aux_ordenado,esq,meio,compara,troca); //Divide o vetor em dois
        mergeSort(v,aux_ordenado,meio+1,dir,compara,troca);
        merge(v,aux_ordenado,esq,meio+1,dir,compara,troca); //Junta as 2 sub-listas ordenando-as comparando as pilhas

    }

}

void m_sort(int* v, int n, int* compara,int* troca){
    int aux[n];

    mergeSort(v,aux,0,n-1,compara,troca);
}

void shellMedia(int v[], int t,int* compara,int* troca)
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
            (*compara)++;
            while (j >= h && aux < v[j - h])
            {
                v[j] = v[j - h];
                (*troca)++;
                j = j - h;
            }
            v[j] = aux;
        }
        h = (h - 1) / 3;
    }
}

int main(){

    int i,*v1,*v2,*v3,*v4,*v5,*v6,*v7,*v8,*v9,*v10;
    v1 = (int *) malloc(N10* sizeof(int));
    v2 = (int *) malloc(N10* sizeof(int));
    v3 = (int *) malloc(N10* sizeof(int));
    v4 = (int *) malloc(N10* sizeof(int));
    v5 = (int *) malloc(N10* sizeof(int));
    v6 = (int *) malloc(N10* sizeof(int));
    v7 = (int *) malloc(N10* sizeof(int));
    v8 = (int *) malloc(N10* sizeof(int));
    v9 = (int *) malloc(N10* sizeof(int));
    v10 = (int *) malloc(N10* sizeof(int));
    
    for (i = 0; i < N10; i++)
    {
        v1[i] = rand() % N10;
        v2[i] = rand() % N10;
        v3[i] = rand() % N10;
        v4[i] = rand() % N10;
        v5[i] = rand() % N10;
        v6[i] = rand() % N10;
        v7[i] = rand() % N10;
        v8[i] = rand() % N10;
        v9[i] = rand() % N10;
        v10[i] = rand() % N10;

    }

    int compara = 0,troca=0;
    bubbleMedia(v1,N10,&compara,&troca);
    bubbleMedia(v2,N10,&compara,&troca);
    bubbleMedia(v3,N10,&compara,&troca);
    bubbleMedia(v4,N10,&compara,&troca);
    bubbleMedia(v5,N10,&compara,&troca);
    bubbleMedia(v6,N10,&compara,&troca);
    bubbleMedia(v7,N10,&compara,&troca);
    bubbleMedia(v8,N10,&compara,&troca);
    bubbleMedia(v9,N10,&compara,&troca);
    bubbleMedia(v10,N10,&compara,&troca);
    printf("BUBBLE: Medio de compara = [%d]\nMedio de trocas = [%d]",compara/10,troca/10);

    printf("\n----\n");

// SHELLSORT

for (i = 0; i < N10; i++)
    {
        v1[i] = rand() % N10;
        v2[i] = rand() % N10;
        v3[i] = rand() % N10;
        v4[i] = rand() % N10;
        v5[i] = rand() % N10;
        v6[i] = rand() % N10;
        v7[i] = rand() % N10;
        v8[i] = rand() % N10;
        v9[i] = rand() % N10;
        v10[i] = rand() % N10;

    }

     compara = 0,troca=0;
    shellMedia(v1,N10,&compara,&troca);
    shellMedia(v2,N10,&compara,&troca);
    shellMedia(v3,N10,&compara,&troca);
    shellMedia(v4,N10,&compara,&troca);
    shellMedia(v5,N10,&compara,&troca);
    shellMedia(v6,N10,&compara,&troca);
    shellMedia(v7,N10,&compara,&troca);
    shellMedia(v8,N10,&compara,&troca);
    shellMedia(v9,N10,&compara,&troca);
    shellMedia(v10,N10,&compara,&troca);
    printf("SHELL: Medio de compara = [%d]\nMedio de trocas = [%d]",compara/10,troca/10);

    printf("\n----\n");
// mergeSORT

for (i = 0; i < N10; i++)
    {
        v1[i] = rand() % N10;
        v2[i] = rand() % N10;
        v3[i] = rand() % N10;
        v4[i] = rand() % N10;
        v5[i] = rand() % N10;
        v6[i] = rand() % N10;
        v7[i] = rand() % N10;
        v8[i] = rand() % N10;
        v9[i] = rand() % N10;
        v10[i] = rand() % N10;

    }

     compara = 0,troca=0;
    m_sort(v1,N10,&compara,&troca);
    m_sort(v2,N10,&compara,&troca);
    m_sort(v3,N10,&compara,&troca);
    m_sort(v4,N10,&compara,&troca);
    m_sort(v5,N10,&compara,&troca);
    m_sort(v6,N10,&compara,&troca);
    m_sort(v7,N10,&compara,&troca);
    m_sort(v8,N10,&compara,&troca);
    m_sort(v9,N10,&compara,&troca);
    m_sort(v10,N10,&compara,&troca);
    printf("MERGESORT: Medio de compara = [%d]\nMedio de trocas = [%d]",compara/10,troca/10);

    printf("\n----\n");

return 0;
}