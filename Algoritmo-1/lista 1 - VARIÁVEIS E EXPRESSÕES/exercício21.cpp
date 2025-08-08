//EXERCÍCIO21
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
    float Q, L;

    printf("\n Quantas libras você possue?\n");
    scanf("%f", &L);

    Q=L*0.45;

    printf("\n Isso equivale a %.2f em quilogramas", Q);

    return 0;
}