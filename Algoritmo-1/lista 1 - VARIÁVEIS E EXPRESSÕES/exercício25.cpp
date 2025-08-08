//EXERCÍCIO25
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
    float A, M;

    printf("\nEscreva o ultimo valor em acres\n");
    scanf("%f", &A);

    M = A/0.000247;

    printf("\n Isso é %.5f em metros.\n", M);
    
    return 0;
}