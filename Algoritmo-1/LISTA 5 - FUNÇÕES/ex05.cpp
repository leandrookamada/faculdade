#include<stdio.h>
#include<math.h>

int calcularArea(int R){
    float V;
    float pi = 3.14 ;

    V = (4/3)*pi*pow(R, 3);
    return (V);
}

int main(){
    int R;
    float A;
    printf("Por favor, insira o valor do raio da area que você quer calcular.");
    scanf("%d", &R);

    A = calcularArea(R);

    printf("\nA área em questão é %.2f", A);
    return 0;
}