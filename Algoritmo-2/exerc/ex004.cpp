// 22/08/2025
#include<stdio.h>

float divisao(int a, int b){
    float resultado;
    if (a == 0 || b == 0){
        printf("Nao e possivel fazer a divisao por zero. \n");
        return 0.0f;
    } else  if (a < b){
        resultado = b/a;
        printf("O resultado da divisao do menor pelo maior número é: %f", resultado);
        return 0.0f;
    } else {
        resultado = a/b;
        printf("O resultado da divisao do menor pelo maior número é: %f", resultado);
        return 0.0f;
    }
}

int main( ){
    float num1, num2;
    printf("Por favor, insira o primeiro número: ");
    scanf("%f", &num1);
    printf("Por favor, insira o segundo número: ");
    scanf("%f", &num2);

    float resultado = divisao(num1, num2);

    printf("%.2f", resultado);

    return 0;
}