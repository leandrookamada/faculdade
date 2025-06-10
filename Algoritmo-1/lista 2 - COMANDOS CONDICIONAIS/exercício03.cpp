#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
    float R, Q, N;

    printf("\nInsira um número:\n");
    scanf("%f", &N);

    if(N > 0){
        R=sqrt(N);
        printf("\n O número inserido era positivo. Ai está o sua raiz: %.2f", R);
    } else{
        Q = pow(N, 2);
        printf("\n O número inserido era negativo. Ai está o seu quadrado: %.2f", Q);
    }
    return 0;
}