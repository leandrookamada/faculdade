#include<stdio.h>
#include<math.h>

int verificador (int num){
    if (num < 0){
        printf("Números negativos não são considerados.\n");
        return 0;
    }
    int raiz = (int)sqrt(num);
    return (raiz * raiz == num); // SE EU COLOCASSE A FUNÇÃO COMO VOID, ELA NÃO RETORNARIA NADA, NESSE CASO ELA RETOR UM "true", OU UM "false"
}
int main(){
    int numero;
    printf("\nPor favor, insira um valor: \n");
    scanf("%d", &numero);

    if(verificador(numero)){
        printf("\nO número %d eh um quadrado perfeito", numero);
    }
    else{
        printf("\nO número %d no é um quadrado perfeito.", numero);
    }

    return 0;
}