#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int N, S=0, D, num = 0, Quantidade[num];

    printf("\nInsira um número inteiro:\n");
    scanf("%d", &N);
    while(N>0){
        D = N % 10;
        S = S + D;
        N = N/10;
        num++;
    }
    for(int i = 0; i > num; i++){
        Quantidade[i] = D;
    }
    printf("\n A soma dos números e: %d. \n", S);
    while(){
        printf("\n%d", Quantidade[i]+1);
    }

    return 0;
}