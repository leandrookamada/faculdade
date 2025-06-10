//EXERCÍCIO23
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
    float M, J;

    printf("\nquantos metros tem a sua casa?\n");
    scanf("%f", &M);

    J = M/0.91;
    printf("\nIsso equivale a %.2f em jardas.", J);

    return 0;
}