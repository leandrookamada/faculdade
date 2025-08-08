#include<stdio.h>
#include<math.h>

float tranformaHoras(int hor, int min, int sec){
    hor = hor*3600;
    min = min*60;
    float valorTotal = hor + min + sec;

    return (valorTotal);
}

int main(){
    int hor, min, sec;
    float segundos;
    printf("Por favor, insira a hora, minuto e os segundos em que você digitar:\n");
    scanf("%d %d %d", &hor, &min, &sec);

    segundos = tranformaHoras(hor, min, sec);

    printf("O valor que você inseriu corresponde a %.0f segundos", segundos);

    return 0;
}