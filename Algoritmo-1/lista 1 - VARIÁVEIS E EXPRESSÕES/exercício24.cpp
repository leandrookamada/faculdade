//EXERCÍCIO24
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
    float M, A;

    printf("\nEscreva um valor em metros quadrados?\n");
    scanf("%f", &M);

    A = M*0.000247;

    printf("\nIsso equivale a %.5f acres.\n", A);
    
    return 0;
}