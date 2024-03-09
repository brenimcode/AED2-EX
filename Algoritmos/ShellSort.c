#include <stdio.h>

/*SHELLSORT
    .IN PLACE ( SEM AUXILIAR ),
    .NAO ESTAVEL(MUDA A ORDEM DE ELEMENTOS REPETIOS, 5 COM 5)
    .SEMELHANTE A INSERTION SORT

*/

void shellsort(int v[],int t){
    int i,j,aux,h=1;

    while(h < t/3)
        h = 3* h + 1;
    while(h>0){
        for(i=h;i<t;i++){
            aux = v[i];
            j=i;
            printf("[i == %d, j == %d, h == %d]\n",i,j,h);

            while(j>=h && aux < v[j-h]){
                v[j] = v[j-h];
                j = j - h;
            }
            v[j]=aux;
        }
        h = (h-1)/3;
    }
}

int main(){
    int vet[6] = {9,8,2,3,1,4};
    int i;
  
    for (i = 0; i < 6; i++)
    {
        printf("[%d] ",vet[i]);
    }
    printf("\n");

    shellsort(vet,6);

    for (i = 0; i < 6; i++)
    {
        printf("[%d] ",vet[i]);
    }
    printf("\n");


    return 0;
}