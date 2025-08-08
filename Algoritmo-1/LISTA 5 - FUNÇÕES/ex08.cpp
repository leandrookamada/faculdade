#include<stdio.h>
#include<math.h>

// hipotenusa = √a2 + b2

float CalcularHiponetenusa(int a, int b){
    float hipotenusa;

    hipotenusa = sqrt(pow(a, 2) + pow(b, 2));

    return hipotenusa;
}

int main(){
    int a, b; 
    float hipotenusa;

    printf("Por favor, insira o valor dos seus catetos: ");
    scanf("%d %d", &a, &b);

    hipotenusa = CalcularHiponetenusa(a, b);

    printf("A hipotenusa do seu triangulo é: %.2f", hipotenusa);

    return 0;
}