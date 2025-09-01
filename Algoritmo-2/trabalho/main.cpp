#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXIMO_DE_USUARIOS 10;


// FUNÇÃO DE MENU: Está função vai ser responsável por delimitar, e facilitar tudo o que o usuário vai fazer e redirecionar ele para o que ele quiser
void menu(){
    printf("----------------------------------------\n");
    printf("|              Voce deseja:            |\n");
    printf("----------------------------------------\n");
    printf("| 1- Fazer um novo jogo                |\n");
    printf("| 2- Criar novo jogador                |\n");
    printf("| 3- Verificar seus cartoes de jogos   |\n");
    printf("| 4- Sortear MegaSena                  |\n");
    printf("| 5- Verificar valor da MegaSena       |\n");
    printf("| 6- Entender como funciona o jogo     |\n");
    printf("----------------------------------------\n");
}

// STRUCT PARA USUÁRIOS
// O struct é um tipo de "estrutura", uma forma de armazenar diferentes tipos de dados.
struct usuario{
    char nome[50];
    int cpf;
    // Aqui, a ideia é que ele possa fazer até 8 jogos, que seriam as linhas, e pode marcar até 15 números, que seria as colunas.
    int jogo[8][15];
    int existente; // Aqui a minha ideia é verificar se o usuário já existe, isso serve para a criação de novos usuários
};

void cadastrar_novo_usuario(){

}

int main(){
    menu();
    return 0;
}