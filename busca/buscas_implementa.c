
// BUSCA SEQUENCIAL PIOR CASO: O(N), MELHOR CASO O(1), CASO MEDIO O(N/2)=O(N)
// Busca sequencial em VETOR
int busca_sequencial(int v[], int n, int chave_busca)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (v[i] == chave_busca)
        {
            return i;
        }
    }
    return -1;
}

// Busca sequencial em LISTA
/*
t_elem *pesquisaLista(t_elem *prim,int chave_busca){
    t_elem *aux;
    for(aux = prim;aux!=NULL;aux->prox){
        if(aux->campo == chave_busca)
            return aux;
    }
    return NULL;
}*/

// Pesquisa Sequencial Ordenada Pior caso: O(N), melhor O(1)
//EM VETOR:
int busca_sequencial_ordenada(int v[], int n, int chave_busca)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (v[i] == chave_busca)
        {
            return i; // chave_busca encontrada
        }
        else if (v[i] > chave_busca)
        {
            return -1; // interrompe busca
        }
    }
    return -1; // chave nao encontrada
}

//BUSCA BINARIA pior caso: O(log N), caso medio O(log N), melhor caso O(1)

int busca_binaria(int v[], int n, int chave_busca){
    int inf =0, sup = n-1,meio;
    //versao iterativa
    while(inf<=sup){
        meio = (inf+sup)/2;
        if(chave_busca == v[meio])
            return meio;
        else{
            if(chave_busca > v[meio]){
                inf = meio+1;
            }
            else{
                sup = meio-1;
            }
        }
    }
    return -1;
}

