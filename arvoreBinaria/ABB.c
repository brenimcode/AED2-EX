#include "ABB.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Inicializa(Apontador *Dicionario) { *Dicionario = NULL; }

int Vazio(Apontador *Dicionario) { return (Dicionario == NULL); }

void PosFixado(Apontador *p)
{
    if (*p == NULL)
        return;
    PosFixado(&(*p)->Esq);
    PosFixado(&(*p)->Dir);
    // OPERAÇÃO VISITA
    printf("%d\n", (*p)->Reg.Chave.num);
}

void Central(Apontador *p)
{
    if (*p == NULL)
        return;
    Central(&(*p)->Esq);
    // Operação VISITA
    printf("%d\n", (*p)->Reg.Chave.num);
    Central(&(*p)->Dir);
}

void PreFixado(Apontador *p)
{
    if (*p == NULL)
        return;
    // OPERACAO VISITA
    printf("%d\n", (*p)->Reg.Chave.num);
    PreFixado(&(*p)->Esq);
    PreFixado(&(*p)->Dir);
}

Registro *Pesquisa(char *x, Apontador *p)
{
    if (*p == NULL)
        return NULL;

    if (*x < (*p)->Reg.Chave.num)
        return Pesquisa(x, &(*p)->Esq);

    else if (*x > (*p)->Reg.Chave.num)
        return Pesquisa(x, &(*p)->Dir);

    else
        return &(*p)->Reg;
}

void Insere(Registro x, Apontador *p)
{
    if (*p == NULL)
    {
        *p = (Apontador)malloc(sizeof(No));
        (*p)->Reg = x;
        (*p)->Esq = NULL;
        (*p)->Dir = NULL;
        return;
    }
    if (x.Chave.num < (*p)->Reg.Chave.num)
    {
        Insere(x, &(*p)->Esq);
        return;
    }
    if (x.Chave.num > (*p)->Reg.Chave.num)
        Insere(x, &(*p)->Dir);
}

void Antecessor(Apontador q, Apontador *r)
{
    if ((*r)->Dir != NULL)
    {
        Antecessor(q, &(*r)->Dir);
        return;
    }
    q->Reg = (*r)->Reg;
    q = *r;
    *r = (*r)->Esq;
    free(q);
}

void Retira(Registro x, Apontador *p)
{
    Apontador Aux;
    if (*p == NULL)
    {
        printf("Erro: Registro nao esta na arvore \n");
        return;
    }
    if (x.Chave.num < (*p)->Reg.Chave.num)
    {
        Retira(x, &(*p)->Esq);
        return;
    }
    if (x.Chave.num > (*p)->Reg.Chave.num)
    {
        Retira(x, &(*p)->Dir);
        return;
    }
    if ((*p)->Esq != NULL)
    {
        Antecessor(*p, &(*p)->Esq);
        return;
    }
    Aux = *p;
    *p = (*p)->Dir;
    free(Aux);
}

Registro *Menor(Apontador *p)
{
    if ((*p)->Esq == NULL)
    {
        return &((*p)->Reg);
    }
    return Menor(&((*p)->Esq));
}

Registro *Maior(Apontador *p)
{
    if ((*p)->Dir == NULL)
    {
        return &((*p)->Reg);
    }
    return Maior(&((*p)->Dir));
}

int AlturaMax(Apontador *p)
{
    if (*p == NULL)
        return 0;

    int alturaD = AlturaMax(&((*p)->Dir));
    int alturaE = AlturaMax(&((*p)->Esq));

    if (alturaD > alturaE)
        return 1 + alturaD;

    return 1 + alturaE;
}

void contaNos(Apontador *p, int *count)
{
    if (*p == NULL)
        return;
    contaNos(&(*p)->Esq, count);
    contaNos(&(*p)->Dir, count);
    // OPERAÇÃO VISITA
    (*count)++;
}

int NosNaoFolha(Apontador *p, int *count)
{
    if (*p == NULL)
        return 0;
    int ver = 0;
    ver += NosNaoFolha(&(*p)->Esq, count);
    ver += NosNaoFolha(&(*p)->Dir, count);
    // OPERAÇÃO VISITA
    if (ver)
        (*count)++;
    return 1;
}

int NosFolha(Apontador *p, int *count)
{
    if (*p == NULL)
        return 0;
    int ver = 0;
    ver += NosFolha(&(*p)->Esq, count);
    ver += NosFolha(&(*p)->Dir, count);
    // OPERAÇÃO VISITA
    if (!ver)
        (*count)++;
    return 1;
}

int alturaArvore(Apontador *p){
    if (*p == NULL){
        return 0;
    }
    int height=0,height2=0;
    height += alturaArvore(&(*p)->Esq);
    height2 += alturaArvore(&(*p)->Dir);
    // OPERAÇÃO VISITA
    if(height > height2) return 1 + height;
    return 1 + height2;

}

void buscaImpar(Apontador *p, int* impar){
    if (*p == NULL){
        return;
    }
    buscaImpar(&(*p)->Esq, impar);
    buscaImpar(&(*p)->Dir, impar);
    // OPERAÇÃO VISITA
    int num = (*p)->Reg.Chave.num;
    if( num % 2 != 0) *impar = num;

}

int maiorNUM(Apontador *p){
    if (*p == NULL){
        return 0;
    }
    int maior = 0,maior2 = 0;
    maior = maiorNUM(&(*p)->Esq);
    maior2 = maiorNUM(&(*p)->Dir);
    // OPERAÇÃO VISITA
    int aux = 0;
    aux = (*p)->Reg.Chave.num;
    if(maior2 > maior) maior = maior2;
    if(aux > maior ) return aux;
    return maior;
}

void excluiPares(Apontador *p){
    if (*p == NULL){
        return;
    }
    excluiPares(&(*p)->Esq);
    excluiPares(&(*p)->Dir);
    // OPERAÇÃO VISITA
    int num = (*p)->Reg.Chave.num;
    if(!(num%2))
        Retira((*p)->Reg,p);

}