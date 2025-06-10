#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
    int N;

    printf("\nInsira um número:\n");
    scanf("%d", &N);

    if (N % 2 == 0){
        printf("\n O número inserido é par\n");
    } else{
        printf("\nO número inserido é impar\n");
    }
    return 0;
}