#include <stdio.h>

void InsertionSORT(int vet[], int tam){
    int i,j,temp;
    // Se ordenado O(N), se não O(N^2)
    for (i = 1; i < tam; i++)
    {
        temp = vet[i];
        for (j = i-1; j >= 0 && vet[j] < temp; j--)
        {
            vet[j+1] = vet[j];
        }
        vet[j+1] = temp;
        
    }
    

}

int main(){
    //InsertionSORT
    int vet[7] = {9,3,5,2,1,12,0};  

    InsertionSORT(vet,7);
    for (int i = 0; i <7; i++)
    {
        printf("[%d] ", vet[i]);
    }
     
    return 0;
}