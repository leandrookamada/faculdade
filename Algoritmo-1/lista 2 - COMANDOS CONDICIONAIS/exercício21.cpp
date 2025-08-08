#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float somar(float num1, float num2){
    return num1 + num2;
}
float subtrair(float num1, float num2){
    if (num1 > num2){
        return num1 - num2;
    } else {
        return num2 - num1;
    }
}
float multiplicar(float num1, float num2){
    return num1 * num2;
}
float dividir(float num1, float num2){
    if (num2>0){
        return num1 / num2;
    } else {
        printf("\nValor inesistente!");
    }
}

int main(){
    int MENU;
    float resultado, num1, num2;

    printf("\n----------------------------------------\n");
    printf("\nEscolha uma opção:\n");
    printf("\n 1- Soma de 2 números\n");
    printf("\n 2- Diferença de 2 números\n");
    printf("\n 3- Produto de 2 números\n");
    printf("\n 4- divisão de 2 númeors\n");
    printf("\n----------------------------------------\n");
    scanf("%d", &MENU);

    switch (MENU){
    case 1:
        printf("\nInsira o primeiro número:\n");
        scanf("%f", &num1);
        printf("\nInsira o segundo número:\n");
        scanf("%f", &num2);
        resultado = somar(num1, num2);
        printf("\nO resultado a operação escolhida é: %.1f", resultado);
        break;
    case 2:
        printf("\nInsira o primeiro número:\n");
        scanf("%f", &num1);
        printf("\nInsira o segundo número:\n");
        scanf("%f", &num2);
        resultado = subtrair(num1, num2);
        printf("\nO resultado a operação escolhida é: %.1f", resultado);
        break;
    case 3:
        printf("\nInsira o primeiro número:\n");
        scanf("%f", &num1);
        printf("\nInsira o segundo número:\n");
        scanf("%f", &num2);
        resultado = multiplicar(num1, num2);
        printf("\nO resultado a operação escolhida é: %.1f", resultado);
        break;
    case 4:
        printf("\nInsira o primeiro número:\n");
        scanf("%f", &num1);
        printf("\nInsira o segundo número:\n");
        scanf("%f", &num2);
        if (num2>0){
        resultado = dividir(num1, num2);
        printf("\nO resultado a operação escolhida é: %.1f", resultado);
        } else {
            printf("\nValor insistente.");
        }
        break;
    default:
        printf("\nValor inválido.");
        break;
    }

    return 0;
}