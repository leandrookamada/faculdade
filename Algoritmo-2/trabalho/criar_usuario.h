

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dados.h"


void criar_novo_usuario(struct usuarios *u){


        printf("Insira o nome do seu usuário: \n" );
        fgets(u->nome, 50, stdin);
        // removendo o "\n" para não ter erro
        u->nome[strcspn(u->nome, "\n")] = 0;


        printf("Por favor, insira o seu CPF: ");
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
        printf("Perfeito!! Vamos cadastrar um novo usuário na posição %dº \n ", i);
        criar_novo_usuario(&ListaDeUsuarios[i]);
        ListaDeUsuarios[i].existente = 1;

        // ADICIONE ESTA LINHA DE DEBUG AQUI
        printf("\n[DEBUG] DADOS SALVOS: NOME='<%s>', CPF='<%s>'\n\n", ListaDeUsuarios[i].nome, ListaDeUsuarios[i].cpf);

    } else {
        printf("Infelizmente o número máximo de usuários já está completo... \n Aconselho a iniciar o jogo.");
    }
    
}