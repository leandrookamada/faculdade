#include<stdio.h>

int multiplica(int num){
    if(num == 1){
        return 1;
    } else {
        return(num + (multiplica(num-1)));
    }
}

int main(){
    int num;
    printf("Por favor, insira um valor: ");
    scanf("%d", &num);

    int multiplicacao = multiplica(num);

    printf("A soma de todos os números é: %d", multiplicacao);

    return 0;
}