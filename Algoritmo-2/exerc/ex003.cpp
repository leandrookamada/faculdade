#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool verificar_senhas(char senha[], char verifica_senhas[]){
    if (strcmp(senha,verifica_senhas) == 0){
        return true;
    } else {
        return false;
    }
}

int main(){
    char senha[9], verifica_senha[9];
    printf("Insira Uma senha com no maximo 8 caracteres:");
    scanf("%8s", senha);
    printf("Verifique sua senha:");
    scanf("%8s", verifica_senha);

    if(verificar_senhas(senha,verifica_senha)){
        printf("senha inserida corretamente.");
    } else {
        printf("Verifique sua senha:");
        scanf("%8s", verifica_senha);
    }

    return 0;
}