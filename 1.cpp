#include <bits/stdc++.h>

using namespace std;

float cosseno(float x) {
    float resultado = 1.0; // Inicializa o resultado com o primeiro termo da série
    float termo = 1.0;     // Inicializa o próximo termo com o primeiro termo da série
    float precisao = 0.00001;

    for (int k = 2; fabs(termo) >= precisao; k += 2) {
        termo = (-1)*termo * x * x / (k * (k - 1)); // Calcula o próximo termo da série
        resultado += termo;                      // Adiciona o próximo termo ao resultado
    }

    return resultado;
}

int main() {
    float angulo;
    cout << "Digite o angulo em graus: ";
    cin >> angulo;

    // Converte o ângulo de graus para radianos
    float radianos = angulo * M_PI / 180.0;

    // Calcula o cosseno do ângulo usando a função cosseno
    float resultado = cosseno(radianos);

    cout << "O cosseno de " << angulo << " graus é: " << resultado << endl;

    return 0;
}
