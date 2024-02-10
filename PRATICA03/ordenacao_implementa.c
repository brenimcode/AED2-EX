#include <stdio.h>
#include <stdlib.h>

void maxHeapify(int arr[], int n, int i) {
    int maior = i; // Inicializa o maior como raiz
    int left = 2 * i + 1; // índice do filho esquerdo
    int right = 2 * i + 2; // índice do filho direito

    // Se o filho esquerdo for maior que a raiz
    if (left < n && arr[left] > arr[maior])
        maior = left;

    // Se o filho direito for maior que o maior até agora
    if (right < n && arr[right] > arr[maior])
        maior = right;

    // Se o maior não for a raiz
    if (maior != i) {
        // Troca a raiz com o maior
        int temp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = temp;

        // Chama recursivamente a função em subárvore afetada
        maxHeapify(arr, n, maior);
    }
}

// Função principal do Heapsort
void heapSort(int arr[], int n) {
    // Constrói o heap, Build-max-heap
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // Extrai um por um dos elementos do heap e joga pro final.
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual para o final
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Chama maxHeapify() na heap reduzida
        maxHeapify(arr, i, 0);
    }
}

//shellsort

void shellsort(int v[], int t)
{
    int i, j, aux, h = 1;

    while (h < t / 3)
        h = 3 * h + 1;
    while (h > 0)
    {
        for (i = h; i < t; i++)
        {
            aux = v[i];
            j = i;

            while (j >= h && aux < v[j - h])
            {
                v[j] = v[j - h];
                j = j - h;
            }
            v[j] = aux;
        }
        h = (h - 1) / 3;
    }
}