//EXERCÍCIO19
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
    float M, L;

    printf("\nEscreva uma quatidade em litros:\n");
    scanf("%f", &M);

    L = M/1000;

    printf("\n Isso equivale a %.2f em metros cúbicos", L);

    return 0;
}