#include <stdio.h>

// Função para trocar dois elementos de um array
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para fazer o heapify em uma subárvore com raiz em um índice 'i' em um heap de tamanho 'n'
void heapify(int arr[], int n, int i)
{

    while (1)
    {

        int maior = i;       // Inicializa o maior como a raiz
        int esq = 2 * i + 1; // índice do filho esquerdo
        int dir = 2 * i + 2; // índice do filho direito

        // Se o filho esquerdo é maior que a raiz
        if (esq < n && arr[esq] > arr[maior])
            maior = esq;

        // Se o filho direito é maior que o maior até agora
        if (dir < n && arr[dir] > arr[maior])
            maior = dir;

        // Se o maior não é a raiz
        if (maior != i)
        {
            swap(&arr[i], &arr[maior]);
            // Recursivamente heapify a subárvore afetada
            i = maior;
        }
        else
        {
            break;
        }
    }
}

// Função principal para classificar uma matriz de determinado tamanho
void heapSort(int arr[], int n)
{
    // Construir heap (reorganizar matriz)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrair elementos um por um do heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move a raiz atual para o final
        swap(&arr[0], &arr[i]);
        // Chama o heapify na heap reduzida
        heapify(arr, i, 0);
    }
}

// Função de utilidade para imprimir um array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função principal
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Array ordenado: \n");
    printArray(arr, n);
    return 0;
}
