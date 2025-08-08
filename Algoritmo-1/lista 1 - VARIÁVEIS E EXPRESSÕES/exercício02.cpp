//EXERCÍCIO02
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    float R;

    printf("\nEscreva um número com duas casas decimais:\n");
    scanf("%f", &R);

    printf("%.2f", R);
    
    return 0;
}