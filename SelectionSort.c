#include <stdio.h>

int main(){
    int vet[6] = {6,5,4,3,2,1};
    int i,j,menor=vet[0],indice;
     // SELECTION SORT EM ORDEM CRESCENTE

    for (i = 0; i < 5; i++)
    {
        //ACHA O MENOR ELEMENTO
        menor = vet[i];
        indice = i;
        for (j = i; j < 6; j++)
        {
            if(vet[j] < menor){
                menor = vet[j];
                indice = j;
                }
        }
        //Troca o menor elemento com o i-ésimo elemento
        vet[indice] = vet[i]; //o menor é vet[indice] 
        vet[i] = menor;

    }

    for (i = 0; i < 6; i++)
    {
        printf("[%d] ",vet[i]);
    }
    printf("\n");
}