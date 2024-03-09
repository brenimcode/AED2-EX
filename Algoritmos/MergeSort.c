#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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


int main(){
    int vet[6] = {6,5,4,3,2,1};
    int i;
    m_sort(vet,6); //passa-se pos de ultimo elemento   
    for (i = 0; i < 6; i++)
    {
        printf("[%d] ",vet[i]);
    }
    printf("\n");

    return 0;
}