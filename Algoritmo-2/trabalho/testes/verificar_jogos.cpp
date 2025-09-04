#include<stdio.h>
#include<stdlib.h> 
#include<time.h> 

struct usuarios{
    int numero;
    int jogos[4][12];
};

void verificar_numero(struct usuarios ListaDeUsuarios, int num[6] ){
    int contador = 0;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 12; j++){
            for(int k = 0; k < 6; k++){
                if(ListaDeUsuarios.jogos[i][j] == num[k]){
                    contador++;
                }
            }
        }
    }
    printf("O número de acertos foi: %d \n", contador);
}
// void preencher_jogos_manualmente(int jogo[4][12], int valor_inicial) {
//     for(int i = 0; i < 4; i++){
//         for(int j = 0; j < 12; j++){
//             jogo[i][j] = valor_inicial;
//             valor_inicial++;
//         }
//     }
// }
int gerar_numero(){
    int num;

     // isso vai fazer gerar o número aleatório todas as vezes. se eu colocar dentro do for, ele vai gerar o mesmo número todas as vezes.

    num = (rand()%59) + 1;


    return num;
}
int main(){
    struct usuarios teste1;
    struct usuarios teste2;
    struct usuarios teste3;

    int numero1 = 1;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 12; j++){
            teste1.jogos[i][j] = numero1;
            numero1++;
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 12; j++){
            teste2.jogos[i][j] = numero1;
            numero1++;
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 12; j++){
            teste3.jogos[i][j] = numero1;
            numero1++;
        }
    }

    int num[6];

    srand(time(NULL));
    for(int i = 0; i < 6; i++){
        num[i] = gerar_numero();
        printf("Número gerado: %d \n", num[i]);
    }
    verificar_numero(teste1, num);
    verificar_numero(teste2, num);
    verificar_numero(teste3, num);


    return 0;
}