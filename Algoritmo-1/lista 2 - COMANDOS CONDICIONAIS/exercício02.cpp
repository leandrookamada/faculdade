#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    float R, N;

    printf("\nEscreva um número:\n");
    scanf("%f", &N);

    if(N > 0){
       R=sqrt(N);
        printf("\nA raiz quadrada do número inserido é %.2f", R);
    }else{
        printf("\nO número inserido é negativo.");
    }
    return 0;
}