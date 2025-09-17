// Aqui temos a função para verificar os jogos feitos e mostrar eles para o usuário


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dados.h"

void verificar_usuario_especifico(struct usuarios ListaDeUsuarios[]);
void verificar_todos_os_jogos(struct usuarios ListaDeUsuarios[]);

void verificar_usuario_especifico(struct usuarios ListaDeUsuarios[]){
    // seguindo a mesma ideia que usei para cadastrar novo jogo
    printf("\n========================================================\n");
    printf("|          VERIFICAR JOGOS DE USUARIO ESPECIFICO       |\n");
    printf("========================================================\n");
    
    char busca_cpf[12];
    int cpf_encontrado = -1;

    printf("\n  >> Por favor, insira o CPF do usuario: ");
    fgets(busca_cpf, 12, stdin);
    //retirando o "\n"
    busca_cpf[strcspn(busca_cpf, "\n")] = 0;

    for(int i = 0; i < MAXIMO_DE_USUARIOS; i++){
        if(ListaDeUsuarios[i].existente == 1 && strcmp(ListaDeUsuarios[i].cpf, busca_cpf) == 0){
            cpf_encontrado = i;
            break;
        }
    }

    if(cpf_encontrado != -1){
        printf("\n  >> Perfeito, vamos verificar os jogos do(a) %s.\n", ListaDeUsuarios[cpf_encontrado].nome);
        printf("  >> Esse usuario possui %d jogos cadastrados.\n", ListaDeUsuarios[cpf_encontrado].quantidade);
    
    
        //for para mostrar o jogos
        for(int i = 0; i < ListaDeUsuarios[cpf_encontrado].quantidade; i++){
            printf("\n  - Jogo %d:", i + 1);
            for(int j = 0; j < 12; j++){
                printf(" %d", ListaDeUsuarios[cpf_encontrado].jogo[i][j]);
            }
            printf("\n");
        }}
}

void verificar_todos_os_jogos(struct usuarios ListaDeUsuarios[]){
    printf("\n========================================================\n");
    printf("|                VERIFICAR TODOS OS JOGOS              |\n");
    printf("========================================================\n");
    printf("\n");

    for(int i = 0; i < MAXIMO_DE_USUARIOS;i++){
        if(ListaDeUsuarios[i].existente == 1 && ListaDeUsuarios[i].quantidade >= 1){
             printf("  >> Jogos de %s (CPF: %s):\n", ListaDeUsuarios[i].nome, ListaDeUsuarios[i].cpf);
            for(int j = 0; j < ListaDeUsuarios[i].quantidade; j++){
                printf("\t- Jogo %d:", j + 1);
                for(int h = 0; h < 12; h++){
                    printf(" %d", ListaDeUsuarios[i].jogo[j][h]);
                }
            printf("\n");
            }
        }
    }
    printf("\n");
}

void verificar_jogos(struct usuarios ListaDeUsuarios[]){
    printf("\n========================================================\n");
    printf("|             VERIFICAR JOGOS CADASTRADOS              |\n");
    printf("========================================================\n");
    
    int opcao;

    printf("\n  >> Você deseja: \n");
    printf("     1) Verificar todos os jogos\n");
    printf("     2) Verificar os jogos de um usuario especifico\n");
    
    printf("  >> Escolha uma opcao: ");
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
        printf("\n| ERRO: Opcao invalida. Por favor, tente novamente.\n");
        break;
    }
}