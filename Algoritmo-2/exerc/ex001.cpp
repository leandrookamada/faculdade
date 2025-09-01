#include<stdlib.h>
#include<stdio.h>

int main(){
    int x, y;

    printf("\nPor favor, insira o primeiro numero\n");
    scanf("%d", &x);

    printf("\n Por favor, insira o segundo numero:\n");
    scanf("%d", &y);

    int soma = x + y;
    printf("\nA soma dos valores é: %d", soma);
    int sub = x - y;
    printf("\nA subtração dos valores é: %d", sub);
    int mult = x*y;
    printf("\nA multiplicação dos valores é: %d", mult);
    float div;
    if(x > y){
        div = x/y;
        printf("\n A divisão dos valores é: %.2f", div);
    } else{
        div = y/x;
        printf("\n A divisão dos valores é: %.0f", div);
    }
    return 0;
}