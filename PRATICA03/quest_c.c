#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao_implementa.c"

#define MAXN 10000

int main() {
    //DECLARAÇÕES
    time_t ini;
    time_t fim;
    int i,j;
    int opcao,n=MAXN;
    int* vetor,*aux;
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
            aux = (int*) malloc(n*sizeof(int));
            break;
        case 2:
            //100.000 TAM
            n*=10;
            vetor = (int*) malloc(n*sizeof(int));
            aux = (int*) malloc(n*sizeof(int));
            break;
        case 3:
            //500.000 TAM
            n*=50;
            vetor = (int*) malloc(n*sizeof(int));
            aux = (int*) malloc(n*sizeof(int));
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
                aux[i] = vetor[i];
            }

            
            break;
        case 2:
        for (i = 0; i < n; i++)
            {
                vetor[i] = i;
                aux[i] = vetor[i];
            }
            
            break;
        case 3:
        for (i = 0,j=n; i < n; i++,j--)
            {
                vetor[i] =j;
                aux[i] = vetor[i];
            }
            
            break;
        }
    } while (opcao<1 || opcao>3);
    
    ini = clock();
    heapSort(vetor,n);
    fim = clock();


    tempo_total = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("heapSort - Tempo total = [%f]\n", tempo_total);
    printf("\n----\n");

    ini = clock();
    shellsort(aux,n);
    fim = clock();
    tempo_total = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("shellSort - Tempo total = [%f]\n", tempo_total);
    

   /*   QUESTAO 1:
        - A)    O segundo maior elemento pode estar no segundo nível, o segundo maior elemento nao pode estar no 1º Nível
        O terceiro maior deve estar no 2º nivel, Não pode estar no 1º e nem no 3º, dado que os elementos sao distintos.

        - B) nao, heap-max é crescente. [9,8,7], 9 é raiz e 8 que é indice(left) é menor que o pai, e 7 é indice(right).    
   
        - C) o HeapSort ele não é estavel, pois sempre altera a ordem dos elementos, fazendo o heap-max,
        e adicionando ao final o maior elemento, a final-1 o 2º maior elemento... 
  
        QUESTÃO 2:
            heapSort: Ele é um algoritmo que demora O(N log N) SEMPRE para ordenar, independente da organizacao inicial do vetor.
            ShellSort: É mais eficientes em alguns casos, como por exemplo quando o vetor esta "quase ordenado".
            Embora, não saibamos sua complexidade, estima-se que está em torno de O(N^1.25) e O(N LOG(N^2)).
    */

    return 0;
}
