//EXERCÍCIO04
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
    float Q;

    printf("\n Digete um número(maior que 4)\n");
    scanf("%f", &Q);

    Q=Q/5;
    
    printf("\nA quinta parte do número que você escreveu é %.2f", Q);

    return 0;
}