// Fac ̧a uma func ̧  ̃ao para verificar se um n  ́umero  ́e positivo ou negativo. Sendo que o valor
// de retorno ser  ́a 1 se positivo, -1 se negativo e 0 se for igual a 0

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void verificaValor(int x){
    if(x > 0){
        printf("\nNúmero positivo\n");
        return;
    }
    if(x < 0){
        printf("\nNúmero negativo");
        return;
    } else {
        printf("número igual a zero");
        return;
    }
}

int main(){
    int x;

    printf("\nInsira um valor: \n ");
    scanf("%d", &x);

    verificaValor(x);

    return 0; 
}