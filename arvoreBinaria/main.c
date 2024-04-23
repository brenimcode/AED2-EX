#include "abb.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pause()
{
    printf("Aperte enter para continuar\n");
    getchar();
    // system("clear");
}
TipoDicionario Dicionario;

void mostraArvores()
{
    printf("\n------------------------------------\n");
    printf("--- ARVORE BINARIA -- em POS-ordem: --\n");
    PosFixado(&Dicionario);
    printf("--- ARVORE BINARIA -- em PRE-ordem: --\n");
    PreFixado(&Dicionario);
    printf("--- ARVORE BINARIA -- em IN-ordem: --\n");
    Central(&Dicionario);
    printf("\n------------------------------------\n");
}

int main()
{
    Registro aux;
    FILE *arquivo = fopen("numeros.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1; // Retorna 1 para indicar erro
    }

    Inicializa(&Dicionario);

    while (fscanf(arquivo, "%d", &aux.Chave.num) != EOF)
    {
        Insere(aux, &Dicionario);
    }

    fclose(arquivo);
    printf("----\n");
    int conta = 0;
    contaNos(&Dicionario, &conta);
    printf("Nos = [%d]\n", conta);
    conta = 0;
    NosNaoFolha(&Dicionario, &conta);
    printf("Nos Nao folha = [%d]\n", conta);

    conta = 0;
    NosFolha(&Dicionario, &conta);
    printf("Nos folha = [%d]\n", conta);

    printf("ALTURA DA ARVORE = [%d]\n", alturaArvore(&Dicionario));
    conta = 0;
    buscaImpar(&Dicionario, &conta);
    printf("Busca impar = [%d]\n", conta);
    printf("Maior NUM = [%d]\n", maiorNUM(&Dicionario));

    mostraArvores();
    excluiPares(&Dicionario);
    mostraArvores();

    return 0;
}
