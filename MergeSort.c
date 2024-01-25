#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void merge(int *V,int inicio,int meio, int fim){
    int *temp,p1,p2,tamanho,i,j,k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio-1;
    p1 = inicio;
    p2 = fim;
    temp = (int*) malloc(tamanho*sizeof(int));
    if(temp!=NULL){
        for (i = 0; i < tamanho; i++)
        {
            if()
        }
        
    }

}

void mergeSort(int v[],int inicio,int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSort(v,inicio,meio); //Divide o vetor em dois
        mergeSort(v,meio+1,fim);
        merge(v,inicio,meio,fim); //Junta as 2 sub-listas ordenando-as


    }

}

int main(){
    int vet[6] = {9,8,2,3,1,4};
    int i;
    mergeSort(vet,0,5);
    for (i = 0; i < 6; i++)
    {
        printf("[%d] ",vet[i]);
    }
    printf("\n");

    return 0;
}