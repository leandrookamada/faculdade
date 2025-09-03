

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dados.h"


void criar_novo_usuario(struct usuarios *u){


        printf("========================================\n");
        printf("        CADASTRO DE NOVO USUARIO        \n");
        printf("========================================\n\n");
        printf("   >> Insira o nome do seu usuario: ");
        fgets(u->nome, 50, stdin);
        // removendo o "\n" para não ter erro
        u->nome[strcspn(u->nome, "\n")] = 0;


        printf("   >> Por favor, insira o seu CPF: ");
        fgets(u->cpf, 12, stdin);

        // removendo o "\n" para não ter outros erros:
        u->cpf[strcspn(u->cpf, "\n")] = 0;
        

}

void cadastra_novo_usuario(struct usuarios ListaDeUsuarios[]){
    int i; // COMO EU VOU USAR ESSA VARIÁVEL EM OUTROS MOMENTOS, FORA DO FOR, EU PRECISO DECLARAR ELA FORA, PARA PODER USAR ELA POR TODA A FUNÇÃO

    // Aqui eu estou procurando onde, na minha lista de usuários, eu tenho um usuário vazío.
    for(i = 0; i < MAXIMO_DE_USUARIOS; i++){
        if(ListaDeUsuarios[i].existente == 0 ){
            break;
        }
    }

    if(i < MAXIMO_DE_USUARIOS){
        printf("======================================================================\n");
        printf("   Perfeito!! Vamos cadastrar um novo usuario na posicao %d.\n", i + 1);
         printf("=====================================================================\n\n");
        criar_novo_usuario(&ListaDeUsuarios[i]);
        ListaDeUsuarios[i].existente = 1;


    } else {
        printf("\n========================================\n");
        printf("  | Limite de usuarios atingido. | \n");
        printf("  |  Aconselho a iniciar o jogo. |\n");
        printf("========================================\n\n");
    }
    
}