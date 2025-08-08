#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void escrevedataporextenso(int dia, int mes, int ano){
    const char *meses[12]= {"janeiro", "fevereiro", "março", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro","novembro", "dezembro"};
    if (dia <= 1 || dia >= 31 || mes <= 1 || mes >= 12){
        printf("valor inserido incorretamente");
        return;
    }
    printf ("\n %d de %s, de %d", dia, meses[mes-1], ano);
}
int main(){
    int dia, mes, ano;
    printf("\n por favor, insira o dia, mes e ano em que você está\n");
    scanf("%d %d %d", &dia, &mes, &ano);

    printf ("o dia em questão é: \n");
    escrevedataporextenso(dia, mes, ano);
    return 0;
}