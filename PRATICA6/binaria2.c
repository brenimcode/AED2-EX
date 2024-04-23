#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contaNo(Apontador* p) {
    if (*p == NULL)
        return 0;
    return 1 + contaNo(&(*p)->Esq) + contaNo(&(*p)->Dir);
}


typedef int TipoChave;
typedef struct Registro
{
    TipoChave Chave;
    /*outros componentes */
    char cep[20];
    char uf[3];
    char cidade[50];
    char endereco[100];

} Registro;


typedef struct No *Apontador;
typedef struct No
{
    Registro Reg;
    Apontador Esq, Dir;
} No;
typedef Apontador TipoDicionario;

void Inicializa(Apontador *Dicionario)
{
    *Dicionario = NULL;
}

int Vazio(Apontador *Dicionario)
{
    return (Dicionario == NULL);
}

void Central(Apontador p)
{
    if (p == NULL)
        return;
    Central(p->Esq);
    printf("%d\n", p->Reg.Chave);
    Central(p->Dir);
}
void PosFixado(Apontador p)
{
    if (p == NULL)
        return;
    PosFixado(p->Esq);
    PosFixado(p->Dir);
    printf("%d\n", p->Reg.Chave);
}

void PreFixado(Apontador p)
{
    if (p == NULL)
        return;
    printf("%d\n", p->Reg.Chave);
    PreFixado(p->Esq);
    PreFixado(p->Dir);
}

int alturaArvore(Apontador raiz) {
    if (raiz == NULL) {
        return -1; // Altura de uma árvore vazia é -1
    } else {
        int alturaEsq = alturaArvore(raiz->Esq);
        int alturaDir = alturaArvore(raiz->Dir);
        return 1 + (alturaEsq > alturaDir ? alturaEsq : alturaDir);
    }
}

Registro Menor(Apontador p){
    if(p->Esq == NULL){
        return p->Reg;
    }
    Menor(p->Esq);
}

Registro maior(Apontador p){
    if(p->Dir == NULL){
        return p->Reg;
    }
    maior(p->Dir);
}

void Pesquisa(Registro *x, Apontador *p)
{
    if (*p == NULL)
    {
        printf("Erro: Registro nao esta na arvore \n");
        return;
    }
    if (x->Chave < (*p)->Reg.Chave)
    {
        Pesquisa(x, &(*p)->Esq);
        return;
    }
    if (x->Chave > (*p)->Reg.Chave)
        Pesquisa(x, &(*p)->Dir);
    else
        *x = (*p)->Reg;
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
    if (x.Chave < (*p)->Reg.Chave)
    {
        Insere(x, &(*p)->Esq);
        return;
    }
    if (x.Chave > (*p)->Reg.Chave)
        Insere(x, &(*p)->Dir);
    else
        printf("Erro: Registro ja existe na arvore \n");
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
    if (x.Chave < (*p)->Reg.Chave)
    {
        Retira(x, &(*p)->Esq);
        return;
    }
    if (x.Chave > (*p)->Reg.Chave)
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


int main()
{
    TipoDicionario Dicionario;
    Registro x;
    Inicializa(&Dicionario);
    scanf(" %d", &x.Chave);
    while (x.Chave > 0)
    {
        Insere(x, &Dicionario);
        scanf(" %d", &x.Chave);
    }
    return 0;
}
