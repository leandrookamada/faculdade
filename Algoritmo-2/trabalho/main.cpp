#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXIMO_DE_USUARIOS 8

// PROTÓTIPOS: Aqui eu estou fazendo uma declaração antecipada ao compilador sobre as próximas funçãos, que ainda não foram definidas, mas serão
void cadastra_novo_usuario(struct usuarios usuario[], int MAX_DE_USUARIOS);
void fazer_novo_jogo();
void verificar_jogos();
void verificar_valor();
void entender_como_funciona();
void sortear_jogo();
void menu();

struct usuarios{
    // STRUCT PARA USUÁRIOS
    // O struct é um tipo de "estrutura", uma forma de armazenar diferentes tipos de dados.
    char nome[50];
    int cpf;
    // Aqui, a ideia é que ele possa fazer até 8 jogos, que seriam as linhas, e pode marcar até 15 números, que seria as colunas.
    int jogo[8][15];
    int existente; // Aqui a minha ideia é verificar se o usuário já existe, isso serve para a criação de novos usuários
};

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

void direcionamento_de_menu(int opcao, struct usuarios usuario[], int maximo){
    int opcao;
    menu();
    scanf("%d", &opcao);


    do { 
    switch (opcao)
    {
    case 1:
        fazer_novo_jogo();
        break;
    case 2:
        cadastra_novo_usuario(usuario, maximo);
        break;
    case 3:
        verificar_jogos();
        break;
    case 4:
        verificar_valor();
        break;
    case 5:
        entender_como_funciona();
        break;
    case 6:
        sortear_jogo();
        break;
    
    default:
        break;
    }}
}


void cadastra_novo_usuario(struct usuarios usuario[], int MAX_DE_USUARIOS){
    int i; // COMO EU VOU USAR ESSA VARIÁVEL EM OUTROS MOMENTOS, FORA DO FOR, EU PRECISO DECLARAR ELA FORA, PARA PODER USAR ELA POR TODA A FUNÇÃO

    for( i = 0; i < MAX_DE_USUARIOS; i++){
        if(usuario[i].existente == 0){
            break;
        }
    }

    if(i < MAX_DE_USUARIOS){
        printf("Insira o nome do seu %dº usuário: ", i+1);
        fgets(usuario[i].nome, 50, stdin);
        printf("Por favor, insira o seu CPF: ");
        scanf("%d", &usuario[i].cpf);
        
    } else {
        printf("Vocẽ já atingiu o número máximo de usuários.\n Aconselho você a ir para o jogo e tentar sua sorte!");
    }
}

int main(){
    menu();
    return 0;
}