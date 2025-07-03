#include<stdio.h>
#include<math.h>
#include<stdbool.h>

//FUNÇAÕ RESPONSAVEL APENAS POR VALIDAR SE UM NÚMERO É PRIMO OU NÃO, RETORNANDO FALSO OU VERDADEIRO
bool ehPrimo(int num) {
    // O NÚMERO PRECISA SER MAIOR QUE UM, SE ELE FOR MENOR QUE UM A FUNÇÃO VAI RESPONDER FALSO
    if (num < 1) {
        return false;
    }
    // AQUI VOU CALCULAR SE O NÚMERO É PRIMO OU NÃO, ELE VAI VERIFICAR NÚMERO POR NÚMERO
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
int main(){
    int num[10];
    int incremento = 0;
    //AQUI VOU APENAS PEDIR PRO USUÁRIO INSERIR OS NÚMEROS
    for(int i = 0; i < 10; i++){
        printf("\nPor favor, insira o primeiro número: ");
        scanf("%d", &num[i]);
    }
    //AQUI EU VOU CHAMAR A FUNÇÃO, E QUANDO ELA ME RETORNAR TRUE ELA VAI INCREMENTAR UM NA VARIÁVEL "incremento" QUE SERVE PARA SABER QUANTOS NÚMERO SÃO IMPARES
    for(int i = 0; i < 10; i++){
        if(ehPrimo(num[i])){
            incremento ++;
        }
    }
    //AQUI VOU VOU MOSTRAR QUANTOS FOREM PRIMOS
    printf("\n Dos valores inseridos, %d são primos e eles estão nas posições:", incremento);
    //AQUI VOU PERCORRER TODOS OS NÚMEROS DO ARRAY E VOU MOSTRAR A POSIÇÃO SEMPRE QUE A FUNÇÃO RESPONDER COMO VERDADEIRO
    for( int i = 0; i < 10; i++){
        if(ehPrimo(num[i])){
            printf(" \n %d", i);
        }
    }
    return 0;
}