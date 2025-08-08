#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
    float R, Q, N;

    printf("\nInsira um numero:\n");
    scanf("%f", &N);

    if(N>0){
        R = sqrt(N);
        Q = pow(N, 2);
        printf("\n O número inserido era posivo,\n aqui está a sua raiz e o seu quadrado \n Raiz:%.2f \nQuadrado:%f.2", R, Q);
    }
    return 0;
}