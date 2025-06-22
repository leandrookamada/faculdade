#include <stdio.h>
#include <math.h>

// Função que verifica se um número é quadrado perfeito
int ehQuadradoPerfeito(int num) {
    if (num < 0) {
        return 0; // números negativos não são quadrados perfeitos
    }

    int raiz = (int)sqrt(num); // raiz quadrada inteira
    return (raiz * raiz == num); // verifica se o quadrado da raiz é igual ao número
}

int main() {
    int numero;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    if (ehQuadradoPerfeito(numero)) {
        printf("%d é um quadrado perfeito.\n", numero);
    } else {
        printf("%d NÃO é um quadrado perfeito.\n", numero);
    }

    return 0;
}