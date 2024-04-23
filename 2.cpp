#include <bits/stdc++.h>

using namespace std;

double senox(double x) {
    // Convertendo graus para radianos
    double radianos = x * M_PI / 180.0;

    double termo = radianos; // Inicializa o primeiro termo da série como x
    double resultado = termo; // Inicializa o resultado como o primeiro termo da série
    int k = 1;
    const double precisao = 0.00001;
	double coisa = -1.0 * radianos * radianos;
    // Soma os termos da série até que o valor absoluto de um termo seja menor que a precisão
    while (abs(termo) >= precisao) {
        // Calcula o próximo termo da série
        termo *= coisa / ((2 * k) * (2 * k + 1));
        
        // Adiciona o próximo termo ao resultado
        resultado += termo;

        // Incrementa o contador k
        k++;
    }

    return resultado;
}

int main() {
    double angulo;
    cout << "Digite o valor do angulo em graus: ";
    cin >> angulo;
    double x;
    // Calcula e exibe o seno do ângulo
    cout << "O seno de " << angulo << " graus eh: " << senox(angulo) << endl;


    return 0;
}
