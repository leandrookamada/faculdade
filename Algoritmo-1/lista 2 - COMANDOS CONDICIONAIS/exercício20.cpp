#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int num[3];

    for (int i = 0; i < 3; i++){
        printf ("\nInsira o %dº valor:", i+1);
        scanf("%d", &num[i]);
    }
    if(num[0] < num[1] + num[2] && num[1] < num[2] + num[0] && num[2] < num[0] + num[1]){
        printf("\nEsses 3 valores podem ser um triagulo\n");
        if (num[0] == num[1] && num[0] == num[2] && num[1] == num[2]){
            printf("\n Esse valor corresponde a um triangulo equilátero, onde todos os lados são iguais.");
        } else  if (num[0] != num[1] && num[0] != num[2] && num[2] != num[1]){
            printf("\nEsse equivale a um triagulo escaleno, que possue todos os lados diferentes.");
        }else{
            printf("\nEsse vale a um triangulo isóceles, onde dois dos lados são iguais");            
        }
    } else{
        printf("\nEsses valores não podem corresponder a um triangulo.");
    }

    return 0;
}//|| num[0]!=num[1]&& num[1]!=num[2]