#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
$t0 = indice
$t1 = low
$t2 = temporario
$t3 = high
$t4 = middle
$t5 = pivot
$t6 = i
$t7 = j

*/

void quicksort(int *array, int low, int high)
{
    int i = low, j = high, mid;
    mid = (low + high-1) / 2;
    int pivot = array[mid]; // pivot = middle value
    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            int temp = array[i];
            array[i] = array[j]; // swap array[i]
            array[j] = temp;     // with array[j]
            i++;
            j--;
        }
    }

    if (low < j)
        quicksort(array, low, j); // Recursive call 1
    if (i < high)
        quicksort(array, i, high); // Recursive call 2
}

int main()
{
    int vet[10] = {6, 5, 4, 1, 2, 11, 12, 0, 17, 18};
    int i;
    quicksort(vet,0,9);
    for (i = 0; i < 10; i++)
    {
            printf("[%d] ",vet[i]);

    }
}