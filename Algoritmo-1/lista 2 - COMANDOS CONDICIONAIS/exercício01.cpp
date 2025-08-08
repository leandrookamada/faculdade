#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
    int MAIOR, num_VALORES[2];//
    printf("\n Preciso que você insira 2 valores:\n");
           for(int i=0; i < 2; i++){
            printf("\nInsira o %dº", i + 1);
            scanf("%d", &num_VALORES[i]);
        }
    printf("\n Os valores inderidos foram:");
    for(int i = 0; i < 2; i ++){
        printf("\n Valor %d: %d.", i+1, num_VALORES[i]);
    }
    if(num_VALORES[0] > num_VALORES[1]){
        MAIOR = num_VALORES[0];
    } else {
        MAIOR = num_VALORES[1];
    }
    printf("\nE entre eles, o maior valor é %d.", MAIOR);
    return 0;
}
//                          OU
//int main(){
//    int VALOR1, VALOR2, MAIOR;
//
//    printf("\nInsira um valor:");
//   scanf("%d", &VALOR1);
//
//    printf("\nInsira Outro valor:");
//    scanf("%d", &VALOR2);
//
//    if(VALOR1 > VALOR2){
//        MAIOR = VALOR1;
//    } else {
//        MAIOR = VALOR2;
//    }
//    
//    printf("\nO maior valor entre eles é %d", MAIOR);
//    return 0;
//}