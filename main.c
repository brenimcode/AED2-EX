#include <stdio.h>
#include <stdlib.h>
#include "ordenacao_implementa.c"

int main(){
    int vet[6] = {6,5,4,3,2,1};
    int i;
    m_sort(vet,6); //passa-se pos de ultimo elemento
    for (i = 0; i < 6; i++)
    {
        printf("[%d] ",vet[i]);
    }
    printf("\n");

}