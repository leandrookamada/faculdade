#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"dados.h"
#include"criar_usuario.h"
#include"fazer_novo_jogo.h"
#include"verificar_jogos.h"
#include"verificar_valor.h"

// PROTÓTIPOS: Aqui eu estou fazendo uma declaração antecipada ao compilador sobre as próximas funçãos, que ainda não foram definidas, mas serão
void entender_como_funciona();
void sortear_jogo();
void menu();
void direcionamento_de_menu(struct usuarios usuario[]);


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
                fazer_novo_jogo(usuario);
                break;
            case 2:
                cadastra_novo_usuario(usuario);
                break;
            case 3:
                verificar_jogos(usuario);
                break;
            case 4:
                verificar_valor(usuario);
                entender_como_funciona();
                break;
            case 6:
                sortear_jogo();
                break;
            
            default:
                break;
        }} while (opcao != 0); 

}

void entender_como_funciona(){
    printf(" Função de entender jogos em desenvolvimento");
    return;
}
void sortear_jogo(){
    printf(" Função de sortear jogo em desenvolvimento");
    return;
}







int main(){
    struct usuarios lista_de_usuarios[8];
    direcionamento_de_menu(lista_de_usuarios);
    return 0;
}