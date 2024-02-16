#include <stdio.h>
#include <stdlib.h>

int max(int vet[], int tamanho,int pos_maior){
    //CASO BASE
    if(tamanho == 0){
        return vet[pos_maior];
        // Durante a recursão vamos alterando esse valor, caso desejavel
    }// Vamos sempre reduzindo o vetor, fazendo as comparações do vet[maior],vet[tamanho-1] até que retorne o 
    else{
        if(vet[tamanho-1] > vet[pos_maior]){
            return max(vet,tamanho-1,tamanho-1);
        }
        else{
            return max(vet,tamanho-1,pos_maior);
        }
    }
}

int main(){
    int A[5] = {5,4,7,2,1};
    
    printf("MAIOR = [%d]",max(A,5,0));
    return 0;

}