#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void maxHeapify(int arr[], int n, int i) {
    int maior = arr[i];
    int filho_esquerda = i*2+1;
    while(filho_esquerda <= n){
        if(filho_esquerda < n) // O filho esquerda é menor que o total, entao tem o filho direita
            if(arr[filho_esquerda] < arr[filho_esquerda+1]) //analisando quem é MAIOR esq ou dir.
                filho_esquerda++; // ele se torna o filho da direita.
        if(maior < arr[filho_esquerda]){ // se o maior(PAI) for menor que um de seus filhos, deve-se trocar
            arr[i] = arr[filho_esquerda];
            i = filho_esquerda; // o i agora é o debaixo, para analisar seus filhos
            filho_esquerda = 2*i + 1; // o filho esquerda agora é o FILHO esquerdo DO FILHO.
        }
        else{
            filho_esquerda = n+1;
        }
    }
    arr[i] = maior; // antigo pai agora ocupa o lugar do filho MAIOR Q ELE
}

// Função principal do Heapsort
void heapSort(int arr[], int n) {
    // Constrói o heap, Build-max-heap
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual para o final
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        // Chama maxHeapify() na heap reduzida
        maxHeapify(arr, i, 0);
    }
}


#define MAXN 10000

int main() {
    //DECLARAÇÕES
    time_t ini;
    time_t fim;
    int i,j;
    int opcao,n=MAXN;
    int* vetor;
    double tempo_total;
    //FIM DECLARACOES
    do
    {
        printf("1: 10k, 2: 100k, 3: 500k\n");
        scanf("%d",&opcao);
        switch (opcao)
        {
        case 1:
            //10.000 TAM
            vetor = (int*) malloc(n*sizeof(int));
            break;
        case 2:
            //100.000 TAM
            n*=10;
            vetor = (int*) malloc(n*sizeof(int));
            break;
        case 3:
            //500.000 TAM
            n*=50;
            vetor = (int*) malloc(n*sizeof(int));
            break;
        }
    } while (opcao<1 || opcao>3);
    
    do
    {
        printf("1: ALEATORIA, 2: CRESCENTE, 3: DECRESCENTE\n");
        scanf("%d",&opcao);
        switch (opcao)
        {
        case 1:
            for (i = 0; i < n; i++)
            {
                vetor[i] = rand()%n;
            }

            
            break;
        case 2:
        for (i = 0; i < n; i++)
            {
                vetor[i] = i;
            }
            
            break;
        case 3:
        for (i = 0,j=n; i < n; i++,j--)
            {
                vetor[i] =j;
            }
            
            break;
        }
    } while (opcao<1 || opcao>3);
    
    ini = clock();
    heapSort_iterativo(vetor,n);
    fim = clock();


    tempo_total = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("heapSort - Tempo total = [%f]\n", tempo_total);
    printf("\n----\n");    

    return 0;
}
