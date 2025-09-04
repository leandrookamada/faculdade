#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"dados.h"


// Para fazer essa área eu encontrei muita dificuldade, a melhor saida que eu encontri foi buscar o usuário pelo cpf, 
// por isso eu precisei criar uma area apenas para buscar o cpf 

void fazer_novo_jogo(struct usuarios ListaDeUsuario[]){
    // essa variável eu vou usar para pegar o cpf que ele deseja fazer o jogo
    char busca_cpf[12];
    // essa variável eu vou usar para saber quemm que é o usuário que ele quer fazer o jogo
    int cpf_encontrado = -1; 

    printf("\n====================================================================================================\n");
    printf("|                                  FAZER NOVO JOGO                                                 |\n");
    printf("====================================================================================================\n");
    
    
    printf("\n  Para isso, precisamos do CPF do jogador.\n");
    printf("  >> Insira o CPF: ");
    fgets(busca_cpf, 12, stdin);
    //retirando o "\n"
    busca_cpf[strcspn(busca_cpf, "\n")] = 0;

    // for para procurar usuário, nos usuários cadastrado
    for(int i = 0; i < MAXIMO_DE_USUARIOS; i++){

        // condição para encontrar usuário cadastrado
        if(ListaDeUsuario[i].existente == 1 && strcmp(ListaDeUsuario[i].cpf , busca_cpf) == 0){
            cpf_encontrado = i;
            break;
        }
    }

    // parte de fazer o jogo de fato
    if(cpf_encontrado != -1){
        // para mostrar o nome dele eu usei a variável "cpf_encontrado", que armazena o indice dele
        printf("\n----------------------------------------------------------------------------------------------------\n");
        printf("  Show de bola %s, chegou a hora de mudar a sua vida na Mega!\n", ListaDeUsuario[cpf_encontrado].nome);
        printf("----------------------------------------------------------------------------------------------------\n");

        // variável para salvar a quantidadede de jogo
        int quantidade; 
         printf("\n  >> Quantos jogos você deseja fazer? (1 a 4): ");
        printf("\n   >> Lembre-se que é permitido fazer no máximo 4 jogos");


        // do para verificar se a quantidade de jogos está dentro do permitido.
        do {
            scanf("%d", &quantidade);
            int c; 
            while((c = getchar()) != '\n' && c != EOF);
            if(quantidade > 4 || quantidade < 1){
                printf("\n\t| ATENÇÃO: Você pode fazer de 1 a 4 jogos. Tente novamente.\n");

            }
        } while (quantidade > 4 || quantidade < 1);

        printf("\n Perfeito, %s!!, vamos fazer os jogos.\n", ListaDeUsuario[cpf_encontrado].nome);

        int quantidade_por_jogo;

        for(int i = 0; i < quantidade; i++){
            printf("\n  >> Jogo %d: quantos números você deseja colocar? (6 a 12): ", i+1);
            
            do {
                scanf("%d", &quantidade_por_jogo);
                int c; 
                while((c = getchar()) != '\n' && c != EOF);
                if(quantidade_por_jogo < 6 || quantidade_por_jogo > 12){
                    printf("Por favor, insira um número válido.\n");
                }
            } while (quantidade_por_jogo < 6 || quantidade_por_jogo > 12);

            

            for(int j = 0; j < quantidade_por_jogo; j++){
                printf("     - Insira o %dº número: ", j+1);
                scanf("%d", &ListaDeUsuario[cpf_encontrado].jogo[i][j]);
            }
             printf("\n  Pronto, vamos para o próximo jogo.\n");

        }
        ListaDeUsuario[cpf_encontrado].quantidade = quantidade;
        printf("\n====================================================================================================\n");
        printf("  Perfeito %s, finalizamos por aqui. O que deseja fazer agora?\n", ListaDeUsuario[cpf_encontrado].nome);
        printf("====================================================================================================\n");
    
    } else { 
        printf("\n| ERRO: CPF não encontrado. Por favor, tente novamente.\n");
    }

}

// quando eu terminei essa função, percebi que eu não fiz de uma forma que o usuário pudesse escolher a quantidade de números que ele gostaria de marcar.