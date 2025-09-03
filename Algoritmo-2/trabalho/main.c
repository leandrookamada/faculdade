#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"dados.h"
#include"criar_usuario.h"

// PROTÓTIPOS: Aqui eu estou fazendo uma declaração antecipada ao compilador sobre as próximas funçãos, que ainda não foram definidas, mas serão
void fazer_novo_jogo();
void verificar_jogos();
void verificar_valor();
void entender_como_funciona();
void sortear_jogo();
void menu();
void direcionamento_de_menu(struct usuarios usuario[]);

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
void fazer_novo_jogo(){
    printf("Que bom que você deseja fazer um jogo!!");
    
    return;
}
void verificar_jogos(){
    printf(" Função de Verificar jogos em desenvolvimento");
    return;
}
void verificar_valor(){
    printf(" Função de Verficar valor em desenvolvimento");
    return;
}
void entender_como_funciona(){
    printf(" Função de entender jogos em desenvolvimento");
    return;
}
void sortear_jogo(){
    printf(" Função de sortear jogo em desenvolvimento");
    return;
}


void direcionamento_de_menu( struct usuarios usuario[]){
    int opcao;
    
    do { 

        // aqui eu estou chamando a função menu, e vou salvar a opção que o usuário desejar acessar 
        menu();
        scanf("%d", &opcao);

        // neste momento eu estou limpando o buffer!!! isso é importante pois eu vou usar a função fgets para salvar uma string, 
        //e como ela lê o que vem do teclado ela acaba tendo erro o scanf, que por padrão lê o que eu inseri, porém quando ele quebra a linha, isso permanece no buffer.
        int c; 
        while((c = getchar()) != '\n' && c != EOF);

        // aqui eu estou criando um switch para direcionar o usuário conforme o que ele for querer fazer.
        switch (opcao)
        {
            case 1:
                fazer_novo_jogo();
                break;
            case 2:
                criar_novo_usuario(usuario);
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
        }} while (opcao != 0); 

}




int main(){
    struct usuarios lista_de_usuarios[8];
    direcionamento_de_menu(lista_de_usuarios);
    return 0;
}