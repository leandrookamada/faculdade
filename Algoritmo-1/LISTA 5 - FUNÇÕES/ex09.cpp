#include<stdio.h>
#include<math.h>

// V = pi ∗raio2 ∗altura, onde π = 3.141592

float calcularArea(int R, int H){
    float pi = 3.141592, V;

    V = pi * pow(R, 2) * H;

    return V;

}

int main(){
    int R, H;
    float V;

    printf("Por favor, insira o raio, e a altura do seu cilindro, respectivamente: \n");
    scanf ("%d %d", &R, &H);

    V = calcularArea(R, H);

    printf("A area do cilindro em questão é: %.0f", V);

    return 0;
}