#include<stdio.h>
#include<stdlib.h> 


struct usuario{
    char nome[50];
    int cpf;
    int jogo[4][4];
};

void criar_usuario(struct usuario *u){
    printf("Por favor, insira o nome do usuario: ");
    fgets(u->nome, 50, stdin);
    printf("Por favor, insira o cpf: ");
    scanf("%d", &u->cpf);


    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int cadastrar_novo_jogo(struct usuario *u){
    int quantidade;


    printf("Quantos jogos você deseja cadastrar: \n ");
    printf("OBS: são permitidos no máximo 4 jogos por participante.\n ");


    do {

        //Aqui eu estou salvando o que a quantidade que o usuário quer
        scanf("%d", &quantidade);

        // verifico se é menor que 4, se não, ele retorna no loop
        if(quantidade > 4 || quantidade < 1){
            printf("Por favor, insira um valor menor, ou igual a 4 para que possamos continuar.");
        }
    } while(quantidade > 4 || quantidade < 1);

    printf("Perfeito!! Vamos fazer %d jogos.", quantidade);
    printf("Como funciona? você deve escolher 4 números de 1 a 60 em cada jogo, depois de escolher os jogos vamos para o próximo, ok?");
    printf("Certo, vamos lá.");

    for(int i = 0; i < quantidade; i++){
        for (int j = 0; j < 4; j++){
            printf("Por favor, insira o %d, do %d cartão", j+1, i+1);
            scanf("%d", &u->jogo[i][j]);
        }
    }

    return quantidade;
  
}
int main(){
    struct usuario teste1;
    criar_usuario(&teste1);
    int quantidade = cadastrar_novo_jogo(&teste1);

    printf("\n--- Dados do Usuario ---\n");
    printf("Nome: %s\n", teste1.nome);
    printf("CPF: %d\n", teste1.cpf);

    for(int i = 0; i < quantidade; i++){
        for(int j = 0; j < 4; j++){
            printf("  %d  ", teste1.jogo[i][j]);
        }
        printf("\n");
    }
    return 0;
}