/*         ALGORITMOS DE ORDENACAO   */

/* EFICIENTES 
    -QUICK
    -MERGE
   SIMPLES
    -BUBBLESORT
    -SELECTIONSORT
    -INSERTIONSORT
*/

// QUICK SORT
void troca(int *v, int a, int b);
int particao(int vet[], int ini, int fim);
void quicksort(int vet[], int ini, int fim);
void QuickBasico(int vet[], int n);

// MERGE SORT

void m_sort(int* v, int n);

void mergeSort(int v[],int aux_ordenado[], int esq,int dir);

void merge(int *V,int aux_ordenado[],int esq,int meio, int dir);

//      SHELLSORT, SELECTION, INSERTION, BUBBLE
void shellsort(int v[],int t);

void InsertionSORT(int vet[], int tam);

void SelectionSort(int vet[], int t);

void bubbleSort(int V[], int tam);