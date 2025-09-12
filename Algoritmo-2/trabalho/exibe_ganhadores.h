#include<stdio.h> 
#include<stdio.h>
#include"dados.h"

// aqui eu vou precisar verificar dentro de todos os jogadores, tenho duas opões, ou faço um por um, ou faço todos de uma vez
// criei uma variável int no struct para que eu possa manter dentro dos usuários o número de acertos que eles tiveram. 
void exibe_ganhadores(struct usuarios ListaDeUsuarios){
    int opcao;
    printf("Você deseja: \n");
    printf("    >> 1) Ver os acertos de cada jogador;\n");
    printf("    >> 2) Ver cada classe de ganhos.");

    do {
        scanf("%d", &opcao);
        int c;
        while((c = getchar()) != '\n' && c != EOF);

        if(opcao < 1 && opcao > 2){
            printf("Por favor, escolha uma opção válida.\n");
        }
    } while (opcao < 1 && opcao > 2);

    switch (opcao)
    {
        case 1: 
            calcula_acertos(ListaDeUsuarios);
            break;
        case 2:
            break;
        default:
            break;
    }
}

void calcula_acertos(struct usuarios ListaDeUsuarios){
    int num[6];
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
            printf("O usuário %s, ", ListaDeUsuarios.nome);
            printf("teve um acerto %d de números ",  *ListaDeUsuarios.acerto);
        }
    }
}
void classe_de_ganhos(struct usuarios ListaDeUsuarios){
        int num[6];
    for(int i = 0; i < 4; i++){

        for(int j = 0; j < 12; j++){

            for(int k = 0; k < 6; k++){
                
                if(ListaDeUsuarios.jogo[i][j] == num[k]){

                    ListaDeUsuarios.acerto[i] += 1;
                }
            }
        }
    }
    for(int i = 0; i < )
}