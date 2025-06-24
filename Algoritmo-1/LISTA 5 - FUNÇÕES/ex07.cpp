#include<stdio.h>
#include<math.h>

float transforamaTemperatura(float C){
    float F;
    F = C * (9.0/5.0) + 32.0;

    return F;
}

int main(){
    float C, F;
    printf("\n Por favor, insira a temperatura atual (em Celcius): ");
    scanf("%f", &C);

    F = transforamaTemperatura(C);

    printf("\nIsso equivale a %.1f graus Fahrenheit.", F);

    return 0;
}