#include<stdio.h> 
#include<stdio.h>
#include"dados.h"

// aqui eu vou precisar verificar dentro de todos os jogadores, tenho duas opões, ou faço um por um, ou faço todos de uma vez
// criei uma variável int no struct para que eu possa manter dentro dos usuários o número de acertos que eles tiveram. 

void calcula_acertos(struct usuarios ListaDeUsuarios, int num[6]){

    // esse array vai percorrer todos os jogos
    for(int i = 0; i < 4; i++){

        // esse array vai percorrer todos os números que o usuário usou
        for(int j = 0; j < 12; j++){

            // esse array vai verificar se o número bate com algum dos sortidos
            for(int k = 0; k < 6; k++){
                
                // condição, se o número analisado bate com algum dos sortidos
                if(ListaDeUsuarios.jogo[i][j] == num[k]){

                    // adiciona um a variável acertos na posição do jogo(i)
                    ListaDeUsuarios.acerto[i] += 1;
                }
            }
        }
    }

    for(int i = 0; i < MAXIMO_DE_USUARIOS; i++){
        if(ListaDeUsuarios.existente == 1 && ListaDeUsuarios.quantidade >= 1){
            printf("O usuário %s, teve um acerto de %d números", ListaDeUsuarios.nome, ListaDeUsuarios.acerto);
        }
    }
}