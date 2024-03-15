#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CEP 10

typedef struct cep_s {
    char cep[9];
    char estado[3];
    char cidade[50];
    char rua[100];
} cep_s;

void shellsort(cep_s v[], int t) {
    int i, j, h = 1;
    cep_s aux;

    while (h < t / 3)
        h = 3 * h + 1;
    while (h > 0) {
        for (i = h; i < t; i++) {
            aux = v[i];
            j = i;

            while (j >= h && strcmp(aux.cep, v[j - h].cep) < 0) {
                v[j] = v[j - h];
                j = j - h;
            }
            v[j] = aux;
        }
        h = (h - 1) / 3;
    }
}

cep_s criar_cep_nao_encontrado() {
    cep_s cep_nao_encontrado;
    strcpy(cep_nao_encontrado.cep, "-1");
    strcpy(cep_nao_encontrado.estado, "-1");
    strcpy(cep_nao_encontrado.cidade, "-1");
    strcpy(cep_nao_encontrado.rua, "-1");
    return cep_nao_encontrado;
}

cep_s busca_binaria(cep_s v[], int ini, int fim, char chave_busca[]) {
    int meio;
    if (ini <= fim) {
        meio = (ini + fim) / 2;
        if (strcmp(chave_busca, v[meio].cep) == 0)
            return v[meio];
        else if (strcmp(chave_busca, v[meio].cep) > 0)
            return busca_binaria(v, meio + 1, fim, chave_busca);
        else
            return busca_binaria(v, ini, meio - 1, chave_busca);
    }
    return criar_cep_nao_encontrado();
}

int main(){

    FILE *arquivo = fopen("ceps.txt", "r");  // Modo de leitura
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    int nmax = 10;
    char cep[15],sigla[15],cidade[255],endereco[255];

    cep_s vetor[nmax];

    int i = 0;

    while(fscanf(arquivo, "%[^;]; %2[^;]; %[^;]; %[^\n]\n",cep,sigla,cidade,endereco) != EOF){
        strcpy(vetor[i].cep,cep);
        strcpy(vetor[i].cidade,cidade);
        strcpy(vetor[i].estado,sigla);
        strcpy(vetor[i].rua,endereco);
        i++;
        if(i == nmax) break;
    }

            printf("Busca binaria\n");
            char temp[10];
            shellsort(vetor,nmax);
            printf("Insira cep: ");
            setbuf(stdin,NULL);
            scanf("%s", temp);
            cep_s aux = busca_binaria(vetor,0,nmax,temp);
            if(strcmp(aux.cep,"-1 ")) {
                printf("nao encontrado\n");
            }
            else{
                printf("CEP: %s \nSigla: %s\nNome Cidade: %s \nEndereco: %s \n",aux.cep,aux.estado,aux.cidade,aux.rua);

            }


    fclose(arquivo);  // Não esqueça de fechar o arquivo após a leitura

    return 0;
}
