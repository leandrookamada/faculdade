#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

#define MAXIMO_DE_USUARIOS 10

struct usuario{
    // STRUCT PARA USUÁRIOS
    // O struct é um tipo de "estrutura", uma forma de armazenar diferentes tipos de dados.
    char nome[50];
    int cpf;
    // Aqui, a ideia é que ele possa fazer até 8 jogos, que seriam as linhas, e pode marcar até 15 números, que seria as colunas.
    int jogo[8][15];
    int existente; // Aqui a minha ideia é verificar se o usuário já existe, isso serve para a criação de novos usuários
};

void CriarUsuarios(struct usuario *u){
    printf("\nPor favor, digite o nome do usuário:\n");
    fgets(u->nome, 50, stdin);
    printf("Por favor, insira o seu CPF:\n Obs: todos os dados são sigilosos e protegidos(rs)\n");
    scanf("%d", &u->cpf);
}

int main(){
    struct usuario teste1;

    CriarUsuarios(&teste1);

    printf("Nome: %s \n", teste1.nome);
    printf("CPF: %d \n", teste1.cpf);

    return 0;
}