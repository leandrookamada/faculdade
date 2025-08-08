#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    float a, b, media;
    printf("\nInsira o valor da primeira nota:");
    scanf("%f", &a);
    printf("\nInsira o segundo valor");
    scanf("%f", &b);

    if (a >= 0 && a <= 10 && b >= 0 && b <= 10){
        media = (a + b)/ 2;
        printf("\nA média é %.2f", media);
    } else {
        printf("\nValor inválido\n");
    }
    return 0;
}
