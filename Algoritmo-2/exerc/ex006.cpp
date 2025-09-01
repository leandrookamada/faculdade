#include<stdio.h>

int calcula_fatorial(int num1){
    if (num1 == 1){
        return 1;
    } else {
        return(num1 * (calcula_fatorial(num1 - 1)));
    }
}

int main(){
    int num1;
    printf("Por favor, insira o valor de um numero: ");
    scanf("%d", &num1);

    int fatorial = calcula_fatorial(num1);

    printf("O fatorial do número inserido é: %d", fatorial);

    return 0;
}