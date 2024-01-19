#include <stdio.h>

int main(){
    int vet[6] = {9,8,2,3,1,4};
    int i,j,temp;
    int ver;
     // BUBBLE SORT EM ORDEM CRESCENTE
     printf("Crescente:\n");
    for (i = 0; i < 5; i++)
    {
        ver = 0;
        for (j = 0; j < 5-i; j++)
        {
            if(vet[j] > vet[j+1]){
                temp = vet[j+1];
                vet[j+1] = vet[j];
                vet[j] = temp;
                ver = 1;
            }
        }
        if(!ver)
            break;
    }

    for (i = 0; i < 6; i++)
    {
        printf("[%d] ",vet[i]);
    }
    printf("\n");
   
     printf("Decrescente:\n");
    for (i = 0; i < 5; i++)
    {
        ver = 0;
        for (j = 0; j < 5-i; j++)
        {
            if(vet[j] < vet[j+1]){
                temp = vet[j+1];
                vet[j+1] = vet[j];
                vet[j] = temp;
                ver = 1;
            }
        }
        if(!ver)
            break;
    }

    for (i = 0; i < 6; i++)
    {
        printf("[%d] ",vet[i]);
    }
    printf("\n");
}