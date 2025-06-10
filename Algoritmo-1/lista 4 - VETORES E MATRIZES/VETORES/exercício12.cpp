#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int A[5], MAIOR = 0, MENOR = 10;
    for(int i = 0; i < 5; i++){
        printf("\nInsira o %dº valor: ", i + 1);
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < 5; i++){
        if(A[i] > MAIOR){
            MAIOR = A[i];
        }
        if(A[i] < MENOR){
            MENOR = A[i];
        }
        if(A[i] < 0){
            printf("o %dº número é um número negativo(%d)\n", i + 1,A[i] );
        }
    }
    printf("o Maior número é: %d \n o Menor número é: %d ", MAIOR, MENOR);
    return 0;
}