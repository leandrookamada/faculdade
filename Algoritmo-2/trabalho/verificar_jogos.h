#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dados.h"

void verificar_usuario_especifico(struct usuarios ListaDeUsuarios[]);
void verificar_todos_os_jogos(struct usuarios ListaDeUsuarios[]);

void verificar_usuario_especifico(struct usuarios ListaDeUsuarios[]){
    // seguindo a mesma ideia que usei para cadastrar novo jogo
    printf("Show de bola!! Vamos verificar os jogos feitos por um usuário específico então.");
    
    char busca_cpf[12];
    int cpf_encontrado = -1;

    printf("Por favor, insira o CPF do usuário que você deseja verificar: ");
    fgets(busca_cpf, 12, stdin);
    //retirando o "\n"
    busca_cpf[strcspn(busca_cpf, "\n")] = 0;
    // fu

    int c;
    while((c = getchar()) != '\n' && c != EOF);

    for(int i = 0; i < MAXIMO_DE_USUARIOS; i++){
        if(ListaDeUsuarios[i].existente == 1 && strcmp(ListaDeUsuarios[i].cpf, busca_cpf) == 0){
            cpf_encontrado = i;
            break;
        }
    }

    printf("Perfeito, vamos verificar os jogos do %s.", ListaDeUsuarios[cpf_encontrado].nome);
    printf("Esse usuário possue %d", ListaDeUsuarios[cpf_encontrado].quantidade);
    
    //for para mostrar o jogos
    for(int i = 0; i < ListaDeUsuarios[cpf_encontrado].quantidade; i++){
        for(int j = 0; j < 16; j++){
            printf("    %d", ListaDeUsuarios[cpf_encontrado].jogo[i][j]);
        }
        printf("\n");
    }
}

void verificar_todos_os_jogos(struct usuarios ListaDeUsuarios[]){
    printf("Positivo, vamos verificar todos os jogos\n");

    for(int i = 0; i < MAXIMO_DE_USUARIOS;i++){
        if(ListaDeUsuarios[i].existente == 1 && ListaDeUsuarios[i].quantidade >= 1){
            for(int j = 0; j < ListaDeUsuarios[i].quantidade; j++){
                for(int h = 0; h < 16; h++){
                    printf("    %d  ", ListaDeUsuarios[i].jogo[j][h]);
                }
            printf("\n");
            }
        }
    }
}

void verificar_jogos(struct usuarios ListaDeUsuarios[]){
    printf("Perfeito!! Vamos verificar os jogos que já foram feitos!!");
    
    int opcao;

    printf("Você deseja: \n 1) Verificar todos os jogos? \n 2) Verificar os jogos de um usuário específico?");
    scanf("%d", &opcao);

    int c;
    while((c = getchar()) != '\n' && c != EOF);

    switch (opcao)
    {
    case 1:
        verificar_todos_os_jogos(ListaDeUsuarios);
        break;
    case 2:
        verificar_usuario_especifico(ListaDeUsuarios);
        break;
    
    default:
        printf("\n Valor inserido inválido!");
        break;
    }
}