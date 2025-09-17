// AQUI TEMOS O ARQUIVO MAIN, QUE VAI SER O ARQUIVO PRINCIPAL DO PROJETO, ONDE VAI TER A FUNÇÃO MAIN, E VAI SER RESPONSÁVEL POR CHAMAR TODAS AS OUTRAS FUNÇÕES
// ELA VAI SER RESPONSÁVEL POR CHAMAR O MENU, E REDIRECIONAR O USUÁRIO PARA O QUE ELE QUISER FAZER


// PROBLEMAS:
// 1- Não estou conseguindo passar o valor dos números sorteados para o arquivo "exibe_ganhadores.h",
// 2- Falta criar a função que calcula os acertos e mostra se o usuário ganhou algo ou não.
// 3- Falta criar a função que mostra o valor arrecadado e como ele é dividido entre os ganhadores.
// 4- Falta criar a função que explica como funciona o jogo.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"dados.h"
#include"criar_usuario.h"
#include"fazer_novo_jogo.h"
#include"verificar_jogos.h"
#include"verificar_valor.h"
#include"sortear_numeros.h"
#include"exibe_ganhadores.h"

// PROTÓTIPOS: Aqui eu estou fazendo uma declaração antecipada ao compilador sobre as próximas funçãos, que ainda não foram definidas, mas serão
void entender_como_funciona();
void menu();
int direcionamento_de_menu(struct usuarios usuario[], int numero_sorteado[6]);


// FUNÇÃO DE MENU: Está função vai ser responsável por delimitar, e facilitar tudo o que o usuário vai fazer e redirecionar ele para o que ele quiser
void menu(){
    printf("==============================================\n");
    printf("|              Voce deseja:                  |\n");
    printf("==============================================\n");
    printf("|   >>  1- Criar novo jogador                |\n");
    printf("|   >>  2- Fazer um novo jogo                |\n");
    printf("|   >>  3- Verificar seus cartoes de jogos   |\n");
    printf("|   >>  4- Verificar valor da MegaSena       |\n");
    printf("|   >>  5- Sortear MegaSena                  |\n");
    printf("|   >>  6- Entender como funciona o jogo     |\n");
    printf("==============================================\n");    
}

int direcionamento_de_menu( struct usuarios usuario[], int numero_sorteado[6]){
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
                cadastra_novo_usuario(usuario);
                break;
            case 2:
                fazer_novo_jogo(usuario);
                break;
            case 3:
                verificar_jogos(usuario);
                break;
            case 4:
                verificar_valor(usuario);
                break;
            case 5:
                sortear_numero(usuario);
                break;
            case 6:
                exibe_ganhadores();
                break;
            case 7:
                entender_como_funciona();
                break;
            
            default:
                break;
        }} while (opcao != 0); 
return 0;
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
    int numeros_sorteados[6];
    struct usuarios lista_de_usuarios[8];
    direcionamento_de_menu(lista_de_usuarios, numeros_sorteados);
    return 0;
}