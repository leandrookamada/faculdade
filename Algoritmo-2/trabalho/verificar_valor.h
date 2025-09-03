#include<stdio.h>
#include<stdlib.h>
#include"dados.h"

void verificar_valor(struct usuarios ListaDeUsuarios[]){
    printf("Perfeito, vamos vericar todos os valores que já entraram.\n");
    printf("OBS: Vale lembrar que cada jogo feito vale a bagatela de R$1.000, ou seja: \n O valor arrecadado é a somatória de todos os jogos.\n");

    int contador = 0;

    for(int i = 0; i <MAXIMO_DE_USUARIOS; i++){
        if(ListaDeUsuarios[i].existente == 1 && ListaDeUsuarios[i].quantidade >= 1){
            contador += ListaDeUsuarios[i].quantidade;
        }
    }
    int total = 1000*contador;
    printf("\nAté o momento, temos o montante de %d", total);
}