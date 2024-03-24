//BRENO OLIVEIRA CAVALCANTE 12221BCC011
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CEP 585882

typedef struct cep_s {
    char cep[9];
    char estado[3];
    char cidade[50];
    char rua[100];
} cep_s;

void shellsort(cep_s v[], int t) {
    int h = 1;
    cep_s aux;

    // Calcula o valor inicial de h
    while (h < t / 3)
        h = 3 * h + 1;

    // Loop para cada intervalo de h
    while (h > 0) {
        // Insertion Sort modificado para intervalo h
        for (int i = h; i < t; i++) {
            aux = v[i];
            int j = i;

            // Desloca os elementos em intervalos de h
            while (j >= h && strcmp(aux.cep, v[j - h].cep) < 0) {
                v[j] = v[j - h];
                j -= h;
            }
            v[j] = aux;
        }
        // Reduz o intervalo h
        h /= 3;
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
    if (ini <= fim) {
        int meio = (ini + fim) / 2;
        if (strcmp(chave_busca, v[meio].cep) == 0)
            return v[meio];
        else if (strcmp(chave_busca, v[meio].cep) > 0)
            return busca_binaria(v, meio + 1, fim, chave_busca);
        else
            return busca_binaria(v, ini, meio - 1, chave_busca);
    }
    return criar_cep_nao_encontrado();
}

int main() {
    FILE *arquivo = fopen("ceps.txt", "r");  // Modo de leitura
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int nmax = MAX_CEP;
    //cep_s *vetor = malloc(nmax*sizeof(cep_s));
    cep_s vetor[nmax];
    int i = 0;

    while (i < nmax && fscanf(arquivo, "%9[^;]; %2[^;]; %[^;]; %99[^\n]\n", vetor[i].cep, vetor[i].estado, vetor[i].cidade, vetor[i].rua) != EOF) {
        i++;
    }

   
printf("--------------\n");
    shellsort(vetor, nmax);
while (1) {
        printf("Busca binaria INSIRA -1 PARA ENCERRAR O PROGRAMA.\n");
        char temp[15];
        printf("Insira cep: ");
        fgets(temp, sizeof(temp), stdin);
        temp[strcspn(temp, "\n")] = '\0'; // Remova o caractere de nova linha
        if (strcmp(temp, "-1") == 0)
            break;
        cep_s aux = busca_binaria(vetor, 0, nmax, temp);
        if (strcmp(aux.cep, "-1") == 0) {
            printf("Não encontrado\n");
        } else {
            printf("CEP: %s\nSigla: %s\nNome Cidade: %s\nEndereco: %s\n", aux.cep, aux.estado, aux.cidade, aux.rua);
        }
    }

    fclose(arquivo);
    //free(vetor);
    return 0;
}
