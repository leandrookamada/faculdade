#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
    int D;

    printf("\nInsira o número equivalente ao dia da semana de hoje,\n domingo sendo o número 1 e sábado o número 7:\n");
    scanf("%d", &D);

    switch (D)
    {
    case 1:
        printf("\n Domingo");
        break;
    case 2:
        printf("\nSegunda");
        break;
    case 3:
        printf("\nTerça");
        break;
    case 4:
        printf("\nQuarta");
        break;
    case 5:
        printf("\nQuinta");
        break;
    case 6:
        printf("\nSexta");
        break;
    case 7:
        printf("\nSábado");
        break;
    default:
        printf("\nValor inserido inválido!");
        break;
    }
    return 0;
}
//O primeiro problema estáva na ultilização de aspas simples. as aspas simples equivalem a um falor em caracter, ou seja:
//Um caracater um '1', possue um valor diferente para a maquinha do que um inteiro 1.