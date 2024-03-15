#include <bits/stdc++.h>

using namespace std;

#define MAXN 10


int v[MAXN], p[MAXN], n, C;

int brute(vector<int> atual, int i) {
	// se chegamos ao fim realiso a operação que queremos checar e retorno o valor
	if(i == n+1) {
		// as funções peso e valor não são explicitadas para evitar poluir o código
		// porém calculam exatamente o que o nome de cada uma indica
		if(peso(atual) <= C) return valor(atual);
		return 0; // o conjunto não é valido logo dizemos que seu valor é 0
	}
	// senao tenho um item para considerar, o qual posso adicionar ou não ao meu conjunto
	
	// não adiciono o item atual ao meu conjunto
	int ans = brute(atual, i+1);
	
	// adiciono o item atual ao meu conjunto
	atual.push_back(i);
	ans = max(ans, brute(atual, i+1));
	
	return ans;
}