#include<stdio.h>
#include<stdlib.h>

struct data {
    int dia;
    int mes; 
    int ano; 
    int total_de_dia;
};

int main(){
    int diferenca;
    struct data data1, data2;

    printf("Por favor, insira o dia da primeira data: ");
    scanf("%d", &data1.dia);
    printf("Por favor, insira o mes da primeira data: ");
    scanf("%d", &data1.mes);
    printf("Por favor, insira o ano da primeira data: ");
    scanf("%d", &data1.ano);


    printf("Por favor, insira o dia da segunda data: ");
    scanf("%d", &data2.dia);
    printf("Por favor, insira o mes da segunda data: ");
    scanf("%d", &data2.mes);
    printf("Por favor, insira o ano da segunda data: ");
    scanf("%d", &data2.ano);
    
    data1.total_de_dia = data1.dia + data1.mes * 30 + data1.ano * 365;
    data2.total_de_dia = data2.dia + data2.mes * 30 + data2.ano * 365;

    if(data1.total_de_dia < data2.total_de_dia){
       diferenca =  data2.total_de_dia - data1.total_de_dia;
    } else {
        diferenca = data1.total_de_dia - data2.total_de_dia;
    }

    printf("total de dias na data um: %d \n", data1.total_de_dia);
    printf("total de dias na data um: %d \n", data2.total_de_dia);
    printf("diferença de dias: %d", diferenca);


    
    return 0; 
}