#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int N;
    float L;

    printf("\nEscrve aum número inteiro:\n");
    scanf("%d", &N);

    if (N > 0){
        L = log(N);
        printf("\nO log do número inserido é: %f", L);
    } else {
        printf("\nO número inserido é negativo\n");
    }
    
    return 0;
}