#include <cstdio> // scanf e printf 

#define MAXN 1100 // defino MAXN como 1100

int n; // declaroo inteiro n

int vetor[MAXN], aux[MAXN]; // declaro os vetores que vou usar

// declaro a função void merge_sort que recebe como parâmetros os índices de início e fim do intervalo a ser ordenado
void merge_sort(int ini, int fim){
	
	if(ini==fim) return; // se for um intervalo de um único elemento, já está ordenado
	
	// se não, divido o intervalo eo meio e ordeno as duas metades, com recursão
	merge_sort(ini, (ini+fim)/2);  //chamo o merge dos dois
	merge_sort((ini+fim)/2+1, fim);
	
	int tam=0; // declaro a variável tam, que é o tamanho do vetor que será criado
	int j=(ini+fim)/2+1; // declaro a variável j, o índice do segundo vetor que estou olhando   //é o topo do segundo
	
	for(int i=ini; i<=(ini+fim)/2; i++){ // para cada elemento do primeiro intervalo
		
		// enquanto o primeiro elemento não usado do segundo intervalo for menor que o do primeiro
		while(j<=fim && vetor[j]<vetor[i]){
			
			 aux[tam]=vetor[j]; // coloco nele o próximo elemento do segundo intervalo
			 tam++; // aumento o tamanho do vetor aux
			 j++; // passo para o próximo elemento do segundo intervalo
		}
		
		// feito isso
		aux[tam]=vetor[i]; // insiro nele o próximo elemento do primeiro intervalo
		tam++; // e aumento o tamanho do vetor
	}
	
	while(j<=fim){ // enquanto ainda houver elemento no segudo intervalo
		
		aux[tam]=vetor[j]; // insiro nele o próximo elemento do segundo intervalo
		j++; // e passo para o p´roximo elemento do segundo intervalo
		tam++; // aumento o tamanho do vetor aux
	}
	
	 // depois coloco os valores do vetor aux no intervalo que queria ordenar
	for(int i=ini; i<=fim; i++) vetor[i]=aux[i-ini]; // note que aux está indexado de 0 a n-1
}

int main(){
	
	scanf("%d", &n); // leio o valor de n, o tamanho do vetor
	
	for(int i=1; i<=n; i++) scanf("%d", &vetor[i]); // leio os elementos do vetor
	
	merge_sort(1, n); // ordeno o vetor da posição 1 até a posição n
	
	for(int i=1; i<=n; i++) printf("%d ", vetor[i]); // imprimo os elementos do vetor, já ordenado
	
	printf("\n"); // e imprimo a quebra de linha no fim da entrada
	
	return 0;
}