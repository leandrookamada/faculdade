#include<stdio.h> 
#include<stdlib.h>
#include<time.h>

#include"dados.h"

// essa foi sem dúvidas a função mas difícil pra criar.



// A IDEIA DESSA FUNÇÃO É A SEGUINTE:
// eu tenho uma variável chamado "num", que é um array que vai armazenar todos os números sortidos,
// mas quando eu estava criando essa função eu percebi um problema, e se ele sortesse números repetidos?? 4
// para evitar esse problema a minha ideia foi a seguinte: 
// criar um variável que armazenasse todas as possibilidades (numeros de um a sessenta), 
// cada indice dessa variável seria um número a ser tirado. 
// depois, eu "tiro" essa variável do jogo, como? diminuindo o valor dela para o anterior.
void sortear_numero(int numeros_sorteados[6]){
    int num[6];

    // essa variável 
    int tamanho_atual = 60;

    // aqui eu estou criando uma variavel que vai armazenar todos os números (de um a 60)    
    int embaralhamento[60];
    for(int i = 0; i > 60; i++){
        embaralhamento[i] = i+1;
    }

    srand(time(NULL)); // isso vai fazer gerar o número aleatório todas as vezes. se eu colocar dentro do for, ele vai gerar o mesmo número todas as vezes.

    for(int i = 0; i < 6; i++){
        // salvando o que vai servir como indice
        int indice = (rand()%59) + 1;
        // adicionando o número sortido ao array
        num[i] = embaralhamento[indice];
        // removendo o número sortido
        embaralhamento[indice] = embaralhamento[tamanho_atual - 1];
        // diminuindo o tamaho atual
        tamanho_atual--;
    }

    printf("Números sortidos:");
    for(int i = 0; i < 6; i++){
        printf("%dº número: %d \n",i + 1,  num[i]);
    }
}


// aqui eu vou precisar verificar dentro de todos os jogadores, tenho duas opões, ou faço um por um, ou faço todos de uma vez
// criei uma variável int no struct para que eu possa manter dentro dos usuários o número de acertos que eles tiveram. 

void calcula_acertos(struct usuarios ListaDeUsuarios, int num[6]){

    // esse array vai percorrer todos os jogos
    for(int i = 0; i < 4; i++){

        // esse array vai percorrer todos os números que o usuário usou
        for(int j = 0; j < 12; j++){

            // esse array vai verificar se o número bate com algum dos sortidos
            for(int k = 0; k < 6; k++){
                
                // condição, se o número analisado bate com algum dos sortidos
                if(ListaDeUsuarios.jogo[i][j] == num[k]){

                    // adiciona um a variável acertos na posição do jogo(i)
                    ListaDeUsuarios.acerto[i] += 1;
                }
            }
        }
    }

    for(int i = 0; i < MAXIMO_DE_USUARIOS; i++){
        if(ListaDeUsuarios.existente == 1 && ListaDeUsuarios.quantidade >= 1){
            printf("O usuário %s, teve um acerto de %d números", ListaDeUsuarios.nome, ListaDeUsuarios.acerto);
        }
    }
}