#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    float S, P, M;
    
    printf("\nInsira o valor do seu salário: ");
    scanf("%f", &S);

    printf("\nInsira o valor da prestação do empréstimo: ");
    scanf("%f", &P);

    M = S *0.2;

    if(P > M){
        printf("\n Emprestimo não concedido\n");
    } else{
        printf("\nEmprestimo concedido.\n");
    }
    return 0;
}