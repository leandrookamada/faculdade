//EXERCÍCIO22
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
    float J, M;

    printf("\nEscreva uma medida em Jardas:\n");
    scanf("%f", &J);
    
    M = 0.91*J;
    
    printf("\nEssa medida em jardas equivale a %.2f em metros\n", M);
    
    return 0;
}
