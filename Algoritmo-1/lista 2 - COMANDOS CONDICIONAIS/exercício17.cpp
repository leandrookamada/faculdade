#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
    int B_maior, B_menor;
    float H, A;
    printf("\nInsira o valor da Base Menor do trapezio:\n");
    scanf("%d", &B_menor);
    printf("\nInsira o valor da Base Maior do trazio:\n");
    scanf("%d", &B_maior);
    printf("\nInsira o valor da altura desse trapezio:\n");
    scanf("%f", &H);

    if(B_maior > 0 && B_menor>0){
        A=((B_menor+B_maior)*H)/2;
        printf("\nA área desse trapézio equivale a: %.1f\n", A);
    } else{
        printf("\n Valores inseridos invalidos.");
    }
    return 0;
}