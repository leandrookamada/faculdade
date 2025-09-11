#include<stdio.h> 
#include<stdlib.h>
#include<time.h>

#include"dados.h"

// essa foi sem dúvidas a função mas difícil pra criar.

void sortear_numero(){
    int sorteio[6];
    int opcao;

    switch (opcao)
    {
    case 1:
        sorteio_automatico(sorteio);
        break;
    
    case 2:
        sorteio_manual(sorteio);
        break;
    
    default:
        break;
    }

    printf("Números sortidos:");
    for(int i = 0; i < 6; i++){
        printf("%dº número: %d \n",i + 1,  sorteio[i]);
    }
}


void sorteio_manual(int sorteio[6]){
    printf("\nShow de bola!! Vamos gerar o sorteio manualmente.\n");
    

    for(int i = 0; i < 6; i++){
        printf("\nPor favor, insira o %dº número do sorteio: ", i+1);
        scanf("%d", &sorteio[i]);
    }
}


// A IDEIA DESSA FUNÇÃO É A SEGUINTE:
// eu tenho uma variável chamado "num", que é um array que vai armazenar todos os números sortidos,
// mas quando eu estava criando essa função eu percebi um problema, e se ele sortesse números repetidos?? 4
// para evitar esse problema a minha ideia foi a seguinte: 
// criar um variável que armazenasse todas as possibilidades (numeros de um a sessenta), 
// cada indice dessa variável seria um número a ser tirado. 
// depois, eu "tiro" essa variável do jogo, como? diminuindo o valor dela para o anterior.
void sorteio_automatico(int sorteio[6]){
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
        sorteio[i] = embaralhamento[indice];
        // removendo o número sortido
        embaralhamento[indice] = embaralhamento[tamanho_atual - 1];
        // diminuindo o tamaho atual
        tamanho_atual--;
    }
}