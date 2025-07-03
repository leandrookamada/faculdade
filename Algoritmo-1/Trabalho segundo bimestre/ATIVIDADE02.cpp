#include<stdio.h>
#include<math.h>
#include<stdbool.h>

// Questão 02 - Leia 10 números inteiros e armazene-os em um vetor.
// Em seguida, identifique e  exiba os elementos que são números primos, juntamente com suas 
// respectivas posições no vetor.

bool ehPrimo(int num) {
    if (num < 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
int main(){
    int num[10];
    int incremento = 0;

    for(int i = 0; i < 10; i++){
        printf("\nPor favor, insira o primeiro número: ");
        scanf("%d", &num[i]);
    }
    for(int i = 0; i < 10; i++){
        if(ehPrimo(num[i])){
            incremento ++;
        }
    }

    printf("\n Dos valores inseridos, %d são primos e eles estão nas posições:", incremento);
    for( int i = 0; i < 10; i++){
        if(ehPrimo(num[i])){
            printf(" \n %d", i);
        }
    }
    return 0;
}