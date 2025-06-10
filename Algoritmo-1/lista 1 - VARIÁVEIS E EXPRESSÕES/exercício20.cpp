//EXERCÍCIO20
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string>

int main(){
    float Q, L;

    printf("\nQuantos quilos você tem?\n");
    scanf("%f", &Q);

    L = Q / 0.45;

    printf("\n Isso equivale a %.2f libras", L);

    return 0;
}