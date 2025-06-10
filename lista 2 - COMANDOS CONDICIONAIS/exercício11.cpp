#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
    int N, S = 0, D;

    printf("\nInsira um número inteiro:\n");
    scanf("%d", &N);

    while(N>0){
        D = N % 10; // aqui eu vou encontrar quanto que vale o valor 
        S = S + D; // somo o último digito na variável "S", que inicialmente tem o valor igual a zero.
        N = N / 10; //Aqui eu tiro o ultimo numéro, colocando ele em uma casa flutuante, porem a variavel "N" é inteira, e por isso ela ignora a casa fluante.
    }
    printf("\n%d", S);
    return 0;
}