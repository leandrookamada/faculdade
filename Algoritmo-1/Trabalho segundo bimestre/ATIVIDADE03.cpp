#include<stdio.h>
#include<math.h>

int calculadora(char resultado, int num1, int num2){
    switch (resultado)
    {
    case '+':
        return num1 + num2;
    case '-':
    return num1 - num2;
    case '*':
    return num1 * num2;
    case '/':
    if (num1 == 0 || num2 == 0){
        printf("Não podemos fazer divisão por 0, baby");
    } else {
        if (num1 < num2){
            return num2/num1;
        } else{
            return num1/num2;
        }
    }
    default:
        return 0;
    }
}
int main(){
    int num1, num2, R;
    char resultado;


    printf("por favor, insira o primeiro valor: \n");
    scanf("%d", &num1);
    
    printf("Por favor, insira o segundo valor: \n");
    scanf("%d", &num2);

    printf("Por favor, o tipo de operação que você deseja realizar(+, -, *, /): ");
    scanf(" %c", &resultado);

    R = calculadora(resultado, num1, num2);
    
    printf("O resultado da operação escolhida é: %d", R);
    return 0;
}