#include<stdio.h>
#include<stdlib.h>
#include"dados.h"

void verificar_valor(struct usuarios ListaDeUsuarios[]){
    printf("\n========================================================\n");
    printf("|                VERIFICAR VALOR ARRECADADO            |\n");
    printf("========================================================\n");

    printf("\n  | OBS: Cada jogo cadastrado vale R$ 1.000,00.          |\n");
    printf("  | O valor total é a soma de todos os jogos ja feitos. |\n");
    printf("  |-----------------------------------------------------|\n");

    int contador = 0;

    for(int i = 0; i <MAXIMO_DE_USUARIOS; i++){
        if(ListaDeUsuarios[i].existente == 1 && ListaDeUsuarios[i].quantidade >= 1){
            contador += ListaDeUsuarios[i].quantidade;
        }
    }
    int total = 1000*contador;
    if(contador > 0){
        printf("\n  - Total de jogos cadastrados: %d\n", contador);
        printf("  - O montante total arrecadado é: R$ %d,00\n", total);
    } else{
        printf("\n  - Nenhum jogo foi cadastrado ainda. O montante total é R$ 0,00\n");
    }
    printf("\n========================================================\n");
}