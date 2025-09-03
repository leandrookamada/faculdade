

#include<stdio.h>
#include<stdlib.h>
#include"dados.h"


void criar_novo_usuario(struct usuarios *u){


        printf("Insira o nome do seu usuário: \n" );
        fgets(u->nome, 50, stdin);

        //LIMPEZA DO BUFFER
        int c;
        while((c = getchar()) != '\n' && c != EOF);

        printf("Por favor, insira o seu CPF: ");
        scanf("%d", &u->cpf);
        

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
        printf("Perfeito!! Vamos cadastrar um novo usuário na posição %dº", i+1);
        criar_novo_usuario(&ListaDeUsuarios[i]);
        ListaDeUsuarios[i].existente = 1;
    } else {
        printf("Infelizmente o número máximo de usuários já está completo... \n Aconselho a iniciar o jogo.");
    }
    
}