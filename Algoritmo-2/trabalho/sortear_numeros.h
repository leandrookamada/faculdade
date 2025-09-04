#include<stdio.h> 
#include<stdlib.h>
#include<time.h>

#include"dados.h"

// essa foi sem dúvidas a função mas difícil pra criar.

void calcula_acertos(struct usuarios ListaDeUsuarios[]){
    
}

void sortear_numero(){
    int num[6];

    srand(time(NULL)); // isso vai fazer gerar o número aleatório todas as vezes. se eu colocar dentro do for, ele vai gerar o mesmo número todas as vezes.

    for(int i = 0; i < 6; i++){
        num[i] = (rand()%59) + 1;
    }

    for(int i = 0; i < 6; i++){
        printf("%dº número: %d \n",i + 1,  num[i]);
    }
}
