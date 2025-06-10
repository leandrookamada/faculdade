// Faça um algoritmo utilizando o comando while que mostra uma contagem regressiva
// na tela, iniciando em 10 e terminando em 0. Mostrar uma mensagem “FIM!” ap  ́os a
// contagem.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int i = 10;
    while(i >= 0){
        printf("\n%d", i);
        i--;
    }
    printf("\nFIM");
    return 0;
}