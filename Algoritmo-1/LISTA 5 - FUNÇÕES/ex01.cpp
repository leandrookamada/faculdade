#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//AQUI EU ESTOU CRIANDO UMA FUNÇÃOO QUE VAI DUPLICAR O VALOR QUE ELA RECEBER
int dobro(int x){
    return x*2;
}
//CORPO DO PROJETO
int main(){
    //DECLARAÇÃO DA VARIÁVEL
    int x;
    //RECEBENDO UM VALOR E SALVANDO ELE NA VARIÁVEL
    printf("\nPor favor, insira um número: \n");
    scanf("%d", &x);

    //ATRIBUNDO OUTRO VALOR A VARIÁVEL, AGORA VAI RECEBER O VALOR DA FUNÇÃO "dobro", QUE USA COMO PARÂMETRO A VARIÁVEL "x"
    x = dobro(x);

    //AQUI ESTOU RETORNANDO O VALOR DE X, QUE AGORA JÁ É O DOBRO DO SEU INICIAL.
    printf("O dobro do valor inserido é %d", x);

    return 0;
}