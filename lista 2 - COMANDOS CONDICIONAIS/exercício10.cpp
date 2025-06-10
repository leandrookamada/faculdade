#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    float H, I;
    char S;

    printf("\nInsira a sua altura em metros:");
    scanf("%f", &H);

    printf("\nInsira o seu sexo(se homem, insira h, se mulher insira m)");
    scanf(" %c", &S); // Por algum motivo quando eu vou chamar uma variável do tipo "char", 
                      // eu preciso dar um espaço.

    if(S == 'h'){
        I = (72.7 * H) - 58;
        printf("\nPara um homem, o seu peso ideal é %.2f", I);
    } else{
        I = (62.1 * H) - 44;
        printf("\nPara uma mulher, o peso ideal é: %.2f", I);
    }
    return 0;
}