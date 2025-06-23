// #include <stdio.h>
// #include <math.h>

// // Função que verifica se um número é quadrado perfeito
// int ehQuadradoPerfeito(int num) {
//     if (num < 0) {
//         return 0; // números negativos não são quadrados perfeitos
//     }

//     int raiz = (int)sqrt(num); // raiz quadrada inteira
//     return (raiz * raiz == num); // verifica se o quadrado da raiz é igual ao número
// }

// int main() {
//     int numero;

//     printf("Digite um número inteiro: ");
//     scanf("%d", &numero);

//     if (ehQuadradoPerfeito(numero)) {
//         printf("%d é um quadrado perfeito.\n", numero);
//     } else {
//         printf("%d NÃO é um quadrado perfeito.\n", numero);
//     }

//     return 0;
// }


#include<stdio.h>
#include<math.h>

int verificador (int num){
    if (num < 0){
        printf("Números negativos não são considerados.\n");
        return 0;
    }
    int raiz = (int)sqrt(num);
    return (raiz * raiz == num); // SE EU COLOCASSE A FUNÇÃO COMO VOID, ELA NÃO RETORNARIA NADA, NESSE CASO ELA RETOR UM "true", OU UM "false"
}
int main(){
    int numero;
    printf("\nPor favor, insira um valor: \n");
    scanf("%d", &numero);

    if(verificador(numero)){
        printf("\nO número %d eh um quadrado perfeito", numero);
    }
    else{
        printf("\nO número %d no é um quadrado perfeito.", numero);
    }

    return 0;
}