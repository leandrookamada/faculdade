#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

float somar(float num1,float num2){// Nesse ponto, precisamos dizer que tipo de variavel vai ser usada, que no caso é uma variável do tipo "float", que pode possuir casas flutuantes.
    return num1 + num2; // "return", uma tag de saída, que vai padronizar o que será usado quando chamarmos a constante somar
}

float subtrair(float num1, float num2){
    return num1 - num2;
}

float multiplicar(float num1, float num2){
    return num1 * num2;
}

float dividir(float num1, float num2){
    if (num2 == 0){ // quando trabalhamos com divisor, qualquer número dividido por zero não existe, logo a conta não pode se concretizar
        printf("\nValos inexistente!");
        return 0;
    } else {
        return num1/num2;
    }
}

void abrir_menu(){
    printf("\n----MENU DE OPERAÇÕES BÁSICAS----\n");
    printf("\n1.SOMAR\n");
    printf("\n2.SUBTRAIR\n");
    printf("\n3.MULTIPLICAR\n");
    printf("\n4.DIVIDIR\n");
    printf("\n0.VOLTAR AO MENU\n");
    printf("\nEscolha uma das alternativas e insira o seu número:\n");
    printf("\n----------------------------------\n");
}

int main(){
    float num1, num2, resultado;
    int M;
    abrir_menu ();
    scanf("%d", &M);
        switch (M){
            case 1:
                printf("\nInsira o primeiro número:\n");
                scanf("%f", &num1);
                printf("\nInsira o segundo número:\n");
                scanf("%f", &num2);
                resultado = somar(num1, num2);//depois de criar uma constante, eu preciso trazer as variaveis que ela vai carregara para isso
                printf("\no reuslta é:%.2f", resultado);    
                break;
            case 2:
                printf("\nInsira o primeiro número\n:");
                scanf("%f", &num1);
                printf("\nInsira o segundo número:\n");
                scanf("%f", &num2);
                resultado = subtrair(num1, num2);
                printf("\no reuslta é:%.2f", resultado);    
                break;
            case 3:
                printf("\nInsira o primeiro número:\n");
                scanf("%f", &num1);
                printf("\nInsira o segundo número:\n");
                scanf("%f", &num2);
                resultado = multiplicar(num1, num2);
                printf("\no reuslta é:%.2f", resultado);   
                break;
            case 4:
               // if(num2 != 0){
                    printf("\nInsira o primeiro número:\n");
                    scanf("%f", &num1);
                    printf("\nInsira o segundo número:\n");
                    scanf("%f", &num2);
                    resultado = dividir(num1, num2);
                    printf("\no reuslta é:%.2f", resultado);    
                //} else {
                    printf("\nValor inváldo.\n");
                //}
                break;
            case 0:
                printf("\nVoltar ao menu.");    
                break;
            default: 
                printf("\nValores invalidos!.");
        }
        
    return 0;
}
//Para escrever esse código, primeiro preciso criar constantes para as escolhas que podem ser feitas pelo ususário.
//Depois disso, precisei criar o menu, como não soube usar tabela e nem sei se é possivel, dei as opçções para os usuários e faço com que ele escolha um número das opções, esse número é uma variável do tipo inteira.