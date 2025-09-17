// Aqui temos a função para fazer um novo jogo 
// Nessa função usamos o cpf para encontrar o usuário
// Depois perguntamos quantos jogos ele quer fazer, e se ele quer escolher os números ou
// se ele quer a supresinha
// Depois mostramos os jogos feitos

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include"dados.h"
void supresinha(struct usuarios ListaDeUsuario[],int cpf_encontrado, int local_atual);
void fazer_jogo_na_mao(struct usuarios ListaDeUsuario[], int cpf_encontrado, int local_atual);

// Para fazer essa área eu encontrei muita dificuldade, a melhor saida que eu encontri foi buscar o usuário pelo cpf, 
// por isso eu precisei criar uma area apenas para buscar o cpf 

void fazer_novo_jogo(struct usuarios ListaDeUsuario[]){
            // essa variável eu vou usar para pegar o cpf que ele deseja fazer o jogo
            char busca_cpf[12];
            // essa variável eu vou usar para saber quemm que é o usuário que ele quer fazer o jogo
            int cpf_encontrado = -1; 

            printf("\n====================================================================================================\n");
            printf("|                                  FAZER NOVO JOGO                                                 |\n");
            printf("====================================================================================================\n");
            
            
            printf("\n  Para isso, precisamos do CPF do jogador.\n");
            printf("  >> Insira o CPF: ");
            fgets(busca_cpf, 12, stdin);
            //retirando o "\n"
            busca_cpf[strcspn(busca_cpf, "\n")] = 0;

            // for para procurar usuário, nos usuários cadastrado
            for(int i = 0; i < MAXIMO_DE_USUARIOS; i++){

                // condição para encontrar usuário cadastrado
                if(ListaDeUsuario[i].existente == 1 && strcmp(ListaDeUsuario[i].cpf , busca_cpf) == 0){
                    cpf_encontrado = i;
                    break;
                }
            }

    // parte de fazer o jogo de fato
    if(cpf_encontrado != -1){
        // para mostrar o nome dele eu usei a variável "cpf_encontrado", que armazena o indice dele
        printf("\n----------------------------------------------------------------------------------------------------\n");
        printf("  Show de bola %s, chegou a hora de mudar a sua vida na Mega!\n", ListaDeUsuario[cpf_encontrado].nome);
        printf("----------------------------------------------------------------------------------------------------\n");

        // variável para salvar a quantidadede de jogo
        int quantidade; 
        int local_atual = 0;
        printf("\n  >> Quantos jogos você deseja fazer? (1 a 4): ");
        printf("\n  >> Lembre-se que é permitido fazer no máximo 4 jogos ");


        // do para verificar se a quantidade de jogos está dentro do permitido.
        do {
            scanf("%d", &quantidade);
            int c; 
            while((c = getchar()) != '\n' && c != EOF);
            if(quantidade > 4 || quantidade < 1){
                printf("\n\t| ATENÇÃO: Você pode fazer de 1 a 4 jogos. Tente novamente.\n");

            }
        } while (quantidade > 4 || quantidade < 1);

        printf("\n Perfeito, %s!!, vamos fazer os jogos.\n", ListaDeUsuario[cpf_encontrado].nome);

        for(int i = 0; i < quantidade; i++){
            int opcao;
            printf("\n Você deseja\n");
            printf("\n      >> 1)Escolher cada um dos seus números da sorte?\n");
            printf("\n      >> 2)Supresinha(A própria máquina gera um número)\n");
            scanf("%d", &opcao);

            int c; 
            while((c = getchar()) !='\n' && c != EOF);
            
            switch (opcao)
            {
                case 1:
                fazer_jogo_na_mao(ListaDeUsuario, cpf_encontrado, local_atual);
                break;
                case 2:
                supresinha(ListaDeUsuario, cpf_encontrado, local_atual);
                break;
                
                default:
                printf("Insira um valor válido.");
                    break;
            }
            local_atual++;
        }

       
        ListaDeUsuario[cpf_encontrado].quantidade = quantidade;
        printf("\n===================================================================================================\n");
        printf("  Perfeito %s, finalizamos por aqui. Os catôes feitos foram:\n", ListaDeUsuario[cpf_encontrado].nome);
        for(int i = 0; i < ListaDeUsuario[cpf_encontrado].quantidade; i++){
            printf("    >> %dº Cartão:", i+1);
            for(int j = 0; j < 12; j++ ){
                printf("        >> %d \n",ListaDeUsuario[cpf_encontrado].jogo[i][j] );
            }
        }
        printf("====================================================================================================\n");
    
    } else { 
        printf("\n| ERRO: CPF não encontrado. Por favor, tente novamente.\n");
    }

}

void supresinha(struct usuarios ListaDeUsuario[],int cpf_encontrado, int local_atual){
    srand(time(NULL));

    for(int i = 0; i < 6; i++){
       ListaDeUsuario[cpf_encontrado].jogo[local_atual][i] = (rand()%59) + 1;
    }
    printf("        >>Os números foram: ");
    for(int i = 0; i < 6; i++){
        printf("        >>%d \n", ListaDeUsuario[cpf_encontrado].jogo[local_atual][i]);
    }
    
}
void fazer_jogo_na_mao(struct usuarios ListaDeUsuario[], int cpf_encontrado, int local_atual){
        int quantidade_por_jogo;

            printf("\n  >> Jogo %d: quantos números você deseja colocar? (6 a 12): ", local_atual+1);
            
            do {
                scanf("%d", &quantidade_por_jogo);
                int c; 
                while((c = getchar()) != '\n' && c != EOF);
                if(quantidade_por_jogo < 6 || quantidade_por_jogo > 12){
                    printf("Por favor, insira um número válido.\n");
                }
            } while (quantidade_por_jogo < 6 || quantidade_por_jogo > 12);

            

            for(int j = 0; j < quantidade_por_jogo; j++){
                printf("     - Insira o %dº número: ", j+1);
                scanf("%d", &ListaDeUsuario[cpf_encontrado].jogo[local_atual][j]);
            }
             printf("\n  Pronto, vamos para o próximo jogo.\n");

}