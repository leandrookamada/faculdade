#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int A[6], SOMA;
    
    for(int i=0; i < 6; i++){
        printf("por favor, insira %dº valor: \n", i+1);
        scanf("%d", &A[i]);
    }
    SOMA = A[0] + A[1] + A[5];
    A[4] = 100;

    for(int i = 0; i < 6; i++){
        printf("\nPOSIÇÃO %d: %d\n", i+1, A[i]);
    }
    printf("A SOMA DO PRIMEIRO, TERCEIRO E SEXTO TERMO É: %d", SOMA);
    return 0;
}