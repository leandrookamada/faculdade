// AQUI TEMOS O ARQUIVO MAIN, QUE VAI SER O ARQUIVO PRINCIPAL DO PROJETO, ONDE VAI TER A FUNÇÃO MAIN, E VAI SER RESPONSÁVEL POR CHAMAR TODAS AS OUTRAS FUNÇÕES
// ELA VAI SER RESPONSÁVEL POR CHAMAR O MENU, E REDIRECIONAR O USUÁRIO PARA O QUE ELE QUISER FAZER
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


// PROTÓTIPOS: Aqui eu estou fazendo uma declaração antecipada ao compilador sobre as próximas funçãos, que ainda não foram definidas, mas serão
void entender_como_funciona();
void menu();
int direcionamento_de_menu(struct usuarios usuario[], int numero_sorteado[6], int total);
void sortear_numero(int sorteio[6]);
void fazer_novo_jogo(struct usuarios ListaDeUsuarios[]);
void verificar_jogos(struct usuarios ListaDeUsuarios[]);
void cadastra_novo_usuario(struct usuarios ListaDeUsuarios[]);
void exibe_ganhadores(struct usuarios usuario[], int numero_sorteado[6], int total);
void sorteio_automatico(int sorteio[6]);
void sorteio_manual(int sorteio[6]);
void supresinha(struct usuarios ListaDeUsuario[],int cpf_encontrado, int local_atual);
void fazer_jogo_na_mao(struct usuarios ListaDeUsuario[], int cpf_encontrado, int local_atual);
void verificar_valor(struct usuarios ListaDeUsuarios[], int *total); // Use um ponteiro para alterar o valor de 'total'
void verificar_usuario_especifico(struct usuarios ListaDeUsuarios[]);
void verificar_todos_os_jogos(struct usuarios ListaDeUsuarios[]);

void calcula_acertos(struct usuarios listaDeUsuarios[], int numero_sorteado[6]);
void calcula_e_exibe_premios(struct usuarios listaDeUsuarios[], int total);
void exibe_acertos_por_jogador(struct usuarios listaDeUsuarios[]);
void exibe_ganhadores_por_classe(struct usuarios listaDeUsuarios[]);


//////////////////////////////////////////////////////////////////////////////////////////
//! //////////////////////// ÁREA DE DADOS//////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

#define MAXIMO_DE_USUARIOS 5

struct usuarios{
    char nome[50];
    char cpf[12];
    int jogo[4][16];
    int existente;

    // Eu precisei criar uma variável de quantidade para saber quantos foram feitos, e calcular depois 
    int quantidade;

    // Eu precisei criar isso para armazenar o número de acertos
    int acerto[5];

    int classe;
};

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////






//////////////////////////////////////////////////////////////////////////////////////////
//! //////////////////////// ÁREA DE MENU ////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
// FUNÇÃO DE MENU: Está função vai ser responsável por delimitar, e facilitar tudo o que o usuário vai fazer e redirecionar ele para o que ele quiser
void menu(){
    printf("==============================================\n");
    printf("|              Voce deseja:                  |\n");
    printf("==============================================\n");
    printf("|   >>  1- Criar novo jogador                |\n");
    printf("|   >>  2- Fazer um novo jogo                |\n");
    printf("|   >>  3- Verificar seus cartoes de jogos   |\n");
    printf("|   >>  4- Verificar valor da MegaSena       |\n");
    printf("|   >>  5- Sortear MegaSena                  |\n");
    printf("|   >>  6- Saiba quem ganhou!                |\n");
    printf("|   >>  7- Entender como funciona o jogo     |\n");
    printf("|   >>  0- Sair do programa                  |\n");
    printf("==============================================\n");    
}
int direcionamento_de_menu( struct usuarios usuario[], int numero_sorteado[6], int total){
    int opcao;
    
    do { 

        // aqui eu estou chamando a função menu, e vou salvar a opção que o usuário desejar acessar 
        menu();
        printf("Sua opcao: ");
        scanf("%d", &opcao);

        // neste momento eu estou limpando o buffer!!! isso é importante pois eu vou usar a função fgets para salvar uma string, 
        //e como ela lê o que vem do teclado ela acaba tendo erro o scanf, que por padrão lê o que eu inseri, porém quando ele quebra a linha, isso permanece no buffer.
        int c; 
        while((c = getchar()) != '\n' && c != EOF);

        // aqui eu estou criando um switch para direcionar o usuário conforme o que ele for querer fazer.
        switch (opcao)
        {
            case 1:
                cadastra_novo_usuario(usuario);
                break;
            case 2:
                fazer_novo_jogo(usuario);
                break;
            case 3:
                verificar_jogos(usuario);
                break;
            case 4:
                verificar_valor(usuario, &total);
                break;
            case 5:
                sortear_numero(numero_sorteado);
                break;
            case 6:
                exibe_ganhadores(usuario, numero_sorteado, total);
                break;
            case 7:
                entender_como_funciona();
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }} while (opcao != 0); 
return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////////////////////
//! //////////////////////// ÁREA DE  CRIAR USUÁRIOS /////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void criar_novo_usuario(struct usuarios *u){


        printf("========================================\n");
        printf("        CADASTRO DE NOVO USUARIO        \n");
        printf("========================================\n\n");
        printf("   >> Insira o nome do seu usuario: ");
        fgets(u->nome, 50, stdin);
        // removendo o "\n" para não ter erro
        u->nome[strcspn(u->nome, "\n")] = 0;


        printf("   >> Por favor, insira o seu CPF: ");
        fgets(u->cpf, 12, stdin);

        // removendo o "\n" para não ter outros erros:
        u->cpf[strcspn(u->cpf, "\n")] = 0;
        

}

void cadastra_novo_usuario(struct usuarios ListaDeUsuarios[]){
    int i; // COMO EU VOU USAR ESSA VARIÁVEL EM OUTROS MOMENTOS, FORA DO FOR, EU PRECISO DECLARAR ELA FORA, PARA PODER USAR ELA POR TODA A FUNÇÃO

    // Aqui eu estou procurando onde, na minha lista de usuários, eu tenho um usuário vazío.
    for(i = 0; i < MAXIMO_DE_USUARIOS; i++){
        if(ListaDeUsuarios[i].existente == 0 ){
            break;
        }
    }

    if(i < MAXIMO_DE_USUARIOS){
        printf("======================================================================\n");
        printf("   Perfeito!! Vamos cadastrar um novo usuario na posicao %d.\n", i + 1);
         printf("=====================================================================\n\n");
        criar_novo_usuario(&ListaDeUsuarios[i]);
        ListaDeUsuarios[i].existente = 1;
        ListaDeUsuarios[i].quantidade = 0; // Garante que a quantidade de jogos comece em 0


    } else {
        printf("\n========================================\n");
        printf("  | Limite de usuarios atingido. | \n");
        printf("  |  Aconselho a iniciar o jogo. |\n");
        printf("========================================\n\n");
    }
    
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////////////////////
//! 2 - ////////////////// ÁREA DE FAZER NOVOS JOGOS//////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////



// Para fazer essa área eu encontrei muita dificuldade, a melhor saida que eu encontrei foi buscar o usuário pelo cpf, 
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
            printf("\n Para o jogo %d, voce deseja\n", i + 1);
            printf("\n      >> 1)Escolher cada um dos seus números da sorte?\n");
            printf("\n      >> 2)Supresinha(A própria máquina gera um número)\n");
            printf("Sua opcao: ");
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
        printf("  Perfeito %s, finalizamos por aqui. Os cartoes feitos foram:\n", ListaDeUsuario[cpf_encontrado].nome);
        for(int i = 0; i < ListaDeUsuario[cpf_encontrado].quantidade; i++){
            printf("    >> %dº Cartão:", i+1);
            for(int j = 0; j < 12; j++ ){
                 if(ListaDeUsuario[cpf_encontrado].jogo[i][j] != 0) { // Mostra apenas números que foram preenchidos
                    printf(" %d ",ListaDeUsuario[cpf_encontrado].jogo[i][j] );
                 }
            }
            printf("\n");
        }
        printf("====================================================================================================\n");
    
    } else { 
        printf("\n| ERRO: CPF não encontrado. Por favor, tente novamente.\n");
    }

}

void supresinha(struct usuarios ListaDeUsuario[],int cpf_encontrado, int local_atual){
    srand(time(NULL));

    for(int i = 0; i < 6; i++){
       ListaDeUsuario[cpf_encontrado].jogo[local_atual][i] = (rand()%60) + 1;
    }
    printf("        >>Os números gerados foram: ");
    for(int i = 0; i < 6; i++){
        printf("%d ", ListaDeUsuario[cpf_encontrado].jogo[local_atual][i]);
    }
    printf("\n");
    
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

                    do{
                        scanf("%d", &ListaDeUsuario[cpf_encontrado].jogo[local_atual][j]);
                        int c;
                        while((c = getchar()) != '\n' && c != EOF);
                        if (ListaDeUsuario[cpf_encontrado].jogo[local_atual][j] < 1 || ListaDeUsuario[cpf_encontrado].jogo[local_atual][j] > 60){
                            printf("Por favor, insira um valor entre 1 e 60");
                        }
                    } while (ListaDeUsuario[cpf_encontrado].jogo[local_atual][j] < 1 || ListaDeUsuario[cpf_encontrado].jogo[local_atual][j] > 60);
            }
            printf("\n  Pronto, vamos para o próximo jogo.\n");

}

//////////////////////////////////////////////////////////////////////////////////////////
//! 3 - ////////////////// ÁREA DE VERIFICAR JOGOS //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
void verificar_jogos(struct usuarios ListaDeUsuarios[]){
    int opcao;
    printf("\n========================================================\n");
    printf("|                VERIFICAR JOGOS CADASTRADOS           |\n");
    printf("========================================================\n");
    printf("|   >> 1) Verificar jogos de um usuário específico     |\n");
    printf("|   >> 2) Verificar todos os jogos de todos os usuários|\n");
    printf("========================================================\n");
    printf("Sua opcao: ");
    scanf("%d", &opcao);
    int c; 
    while((c = getchar()) != '\n' && c != EOF);

    switch(opcao){
        case 1:
            verificar_usuario_especifico(ListaDeUsuarios);
            break;
        case 2:
            verificar_todos_os_jogos(ListaDeUsuarios);
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }
}

void verificar_usuario_especifico(struct usuarios ListaDeUsuarios[]){
    char busca_cpf[12];
    int cpf_encontrado = -1;

    printf("\n  >> Insira o CPF do usuário que deseja verificar: ");
    fgets(busca_cpf, 12, stdin);
    busca_cpf[strcspn(busca_cpf, "\n")] = 0;

    for(int i = 0; i < MAXIMO_DE_USUARIOS; i++){
        if(ListaDeUsuarios[i].existente == 1 && strcmp(ListaDeUsuarios[i].cpf, busca_cpf) == 0){
            cpf_encontrado = i;
            break;
        }
    }

    if(cpf_encontrado != -1){
        printf("\n--- Jogos do usuário %s ---\n", ListaDeUsuarios[cpf_encontrado].nome);
        if(ListaDeUsuarios[cpf_encontrado].quantidade == 0){
            printf("  Este usuário ainda nao fez jogos.\n");
        } else {
            for(int i = 0; i < ListaDeUsuarios[cpf_encontrado].quantidade; i++){
                printf("  >> Jogo %d:", i + 1);
                for(int j = 0; j < 12; j++){
                    if(ListaDeUsuarios[cpf_encontrado].jogo[i][j] != 0){
                        printf(" %d", ListaDeUsuarios[cpf_encontrado].jogo[i][j]);
                    }
                }
                printf("\n");
            }
        }
    } else {
        printf("\n| ERRO: CPF nao encontrado.\n");
    }
}

void verificar_todos_os_jogos(struct usuarios ListaDeUsuarios[]){
    printf("\n--- Listando todos os jogos cadastrados ---\n");
    int jogos_cadastrados = 0;
    for(int u = 0; u < MAXIMO_DE_USUARIOS; u++){
        if(ListaDeUsuarios[u].existente == 1 && ListaDeUsuarios[u].quantidade > 0){
            jogos_cadastrados = 1;
            printf("\n  Usuário: %s (CPF: %s)\n", ListaDeUsuarios[u].nome, ListaDeUsuarios[u].cpf);
            for(int i = 0; i < ListaDeUsuarios[u].quantidade; i++){
                printf("    >> Jogo %d:", i + 1);
                 for(int j = 0; j < 12; j++){
                    if(ListaDeUsuarios[u].jogo[i][j] != 0){
                        printf(" %d", ListaDeUsuarios[u].jogo[i][j]);
                    }
                }
                printf("\n");
            }
        }
    }
    if(jogos_cadastrados == 0){
        printf("\nNenhum jogo foi cadastrado no sistema ainda.\n");
    }
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////////////////
//! 4 - //////////////////// ÁREA DE VERIFICAR VALOR /////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
// essa foi sem dúvidas a função mas difícil pra criar.

void verificar_valor(struct usuarios ListaDeUsuarios[], int *total){
    printf("\n========================================================\n");
    printf("|                VERIFICAR VALOR ARRECADADO            |\n");
    printf("========================================================\n");

    printf("\n  | OBS: Cada jogo cadastrado vale R$ 1.000,00.          |\n");
    printf("  | O valor total é a soma de todos os jogos ja feitos. |\n");
    printf("  |-----------------------------------------------------|\n");

    int contador = 0;

    for(int i = 0; i <MAXIMO_DE_USUARIOS; i++){
        if(ListaDeUsuarios[i].existente == 1 && ListaDeUsuarios[i].quantidade >= 1){
            contador += ListaDeUsuarios[i].quantidade;
        }
    }
    *total = 1000 * contador; // Modificando o valor através do ponteiro
    if(contador > 0){
        printf("\n  - Total de jogos cadastrados: %d\n", contador);
        printf("  - O montante total arrecadado é: R$ %d,00\n", *total);
    } else{
        printf("\n  - Nenhum jogo foi cadastrado ainda. O montante total é R$ 0,00\n");
        *total = 0;
    }
    printf("\n========================================================\n");
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////






//////////////////////////////////////////////////////////////////////////////////////////
//! 5 - ////////////////// ÁREA DE SORTEAR NÚMERO ////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////




void sortear_numero(int sorteio[6]){
    
    int opcao;
    printf("\n====================================================================================================\n");
    printf("|                                    SORTEAR NÚMERO                                                  |\n");
    printf("======================================================================================================\n");

    printf("        >> Você deseja:\n");
    printf("    >> 1) Fazer o sorteio automático?\n");
    printf("    >> 2) Fazer o sorteio manual?\n");
    printf("Sua opcao: ");
    do{
        scanf("%d", &opcao);

        int c; 
        while((c = getchar()) != '\n' && c != EOF);

        if(opcao != 1 && opcao != 2){
            printf("Por favor, insira um valor válido: ");
        }
    } while (opcao < 1 || opcao > 2);

    switch (opcao)
    {
    case 1:
        sorteio_automatico(sorteio);
        break;
    
    case 2:
        sorteio_manual(sorteio);
        break;
    default:
        break;
    }

}


void sorteio_manual(int sorteio[6]){
    printf("\nShow de bola!! Vamos gerar o sorteio manualmente.\n");
    

    for(int i = 0; i < 6; i++){
        printf("\nPor favor, insira o %dº número do sorteio: ", i+1);
        do{
            scanf("%d", &sorteio[i]);
            int c;
            while((c = getchar()) != '\n' && c != EOF);
            if (sorteio[i] < 1 || sorteio[i] > 60){
                printf("Por favor, insira um valor entre 1 e 60");
            }
        } while (sorteio[i] < 1 || sorteio[i] > 60);
    }
    printf("\nNúmeros sorteados manualmente:");
    for(int i = 0; i < 6; i++){
        printf(" %d", sorteio[i]);
    }
    printf("\n");
}


// A IDEIA DESSA FUNÇÃO É A SEGUINTE:
// eu tenho uma variável chamado "num", que é um array que vai armazenar todos os números sortidos,
// mas quando eu estava criando essa função eu percebi um problema, e se ele sortesse números repetidos?? 4
// para evitar esse problema a minha ideia foi a seguinte: 
// criar um variável que armazenasse todas as possibilidades (numeros de um a sessenta), 
// cada indice dessa variável seria um número a ser tirado. 
// depois, eu "tiro" essa variável do jogo, como? diminuindo o valor dela para o anterior.
void sorteio_automatico(int sorteio[6]){
    // essa variável 
    int tamanho_atual = 60;

    // aqui eu estou criando uma variavel que vai armazenar todos os números (de um a 60)    
    int embaralhamento[60];
    for(int i = 0; i < 60; i++){
        embaralhamento[i] = i+1;
    }

    srand(time(NULL)); // isso vai fazer gerar o número aleatório todas as vezes. se eu colocar dentro do for, ele vai gerar o mesmo número todas as vezes.

    for(int i = 0; i < 6; i++){
        // salvando o que vai servir como indice
        int indice = rand() % tamanho_atual;
        // adicionando o número sortido ao array
        sorteio[i] = embaralhamento[indice];
        // removendo o número sortido (trocando com o último e diminuindo o tamanho)
        embaralhamento[indice] = embaralhamento[tamanho_atual - 1];
        // diminuindo o tamaho atual
        tamanho_atual--;
    }

    printf("\nNúmeros sorteados automaticamente:");
    for(int i = 0; i < 6; i++){
        printf(" %d", sorteio[i]);
    }
    printf("\n");
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////////////////
//! 6 - ////////////////// ÁREA DE EXIBIR GANHADORES /////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
// Implementação da função para calcular os acertos.
void calcula_acertos(struct usuarios listaDeUsuarios[], int numero_sorteado[6]) {
    // esse array vai percorrer todos os usuários
    for(int u = 0; u < MAXIMO_DE_USUARIOS; u++) {
        if(listaDeUsuarios[u].existente == 0 || listaDeUsuarios[u].quantidade < 1) continue;

        // esse array vai percorrer todos os jogos do usuário
        for(int i = 0; i < listaDeUsuarios[u].quantidade; i++) {
            listaDeUsuarios[u].acerto[i] = 0; // zera antes de contar

            // esse array vai percorrer todos os números que o usuário usou
            for(int j = 0; j < 12; j++) {
                if (listaDeUsuarios[u].jogo[i][j] == 0) continue; // Pula números não preenchidos

                // esse array vai verificar se o número bate com algum dos sortidos
                for(int k = 0; k < 6; k++) {
                    
                    // condição, se o número analisado bate com algum dos sortidos
                    if(listaDeUsuarios[u].jogo[i][j] == numero_sorteado[k]) {
                        
                        // adiciona um a variável acertos na posição do jogo(i)
                        listaDeUsuarios[u].acerto[i] += 1;
                    }
                }
            }
        }
    }
}

// Implementação da função para exibir os acertos por jogador.
void exibe_acertos_por_jogador(struct usuarios listaDeUsuarios[]) {
    printf("\n--- Acertos por Jogador ---\n");
    for(int u = 0; u < MAXIMO_DE_USUARIOS; u++) {
        if(listaDeUsuarios[u].existente == 1 && listaDeUsuarios[u].quantidade >= 1) {
            printf("Usuário: %s\n", listaDeUsuarios[u].nome);
            for(int i = 0; i < listaDeUsuarios[u].quantidade; i++) {
                printf("  - Aposta %d: teve %d acerto(s)\n", i+1, listaDeUsuarios[u].acerto[i]);
            }
        }
    }
}

// Implementação da função para exibir os ganhadores por classe.
void exibe_ganhadores_por_classe(struct usuarios listaDeUsuarios[]) {
    printf("\n--- Ganhadores por Categoria ---\n");
    int sena = 0, quina = 0, quadra = 0;

    printf("\nSena (6 acertos):\n");
    for (int u = 0; u < MAXIMO_DE_USUARIOS; u++) {
        if (listaDeUsuarios[u].existente == 1 && listaDeUsuarios[u].quantidade >= 1) {
            for (int i = 0; i < listaDeUsuarios[u].quantidade; i++) {
                if (listaDeUsuarios[u].acerto[i] == 6) {
                    printf("  - O usuário %s acertou a sena na aposta %d!\n", listaDeUsuarios[u].nome, i + 1);
                    sena++;
                }
            }
        }
    }
    if(sena == 0) printf("  - Ninguém acertou a Sena.\n");

    printf("\nQuina (5 acertos):\n");
    for (int u = 0; u < MAXIMO_DE_USUARIOS; u++) {
        if (listaDeUsuarios[u].existente == 1 && listaDeUsuarios[u].quantidade >= 1) {
            for (int i = 0; i < listaDeUsuarios[u].quantidade; i++) {
                if (listaDeUsuarios[u].acerto[i] == 5) {
                    printf("  - O usuário %s acertou a quina na aposta %d!\n", listaDeUsuarios[u].nome, i + 1);
                    quina++;
                }
            }
        }
    }
    if(quina == 0) printf("  - Ninguém acertou a Quina.\n");

    printf("\nQuadra (4 acertos):\n");
    for (int u = 0; u < MAXIMO_DE_USUARIOS; u++) {
        if (listaDeUsuarios[u].existente == 1 && listaDeUsuarios[u].quantidade >= 1) {
            for (int i = 0; i < listaDeUsuarios[u].quantidade; i++) {
                if (listaDeUsuarios[u].acerto[i] == 4) {
                    printf("  - O usuário %s acertou a quadra na aposta %d!\n", listaDeUsuarios[u].nome, i + 1);
                    quadra++;
                }
            }
        }
    }
    if(quadra == 0) printf("  - Ninguém acertou a Quadra.\n");
}


//função para calcular e exibir os prêmios (essa aqui quase que não saiu !)
void calcula_e_exibe_premios(struct usuarios listaDeUsuarios[], int total_arrecadado) {
    if (total_arrecadado == 0) {
        printf("\nNenhum valor foi arrecadado, portanto não há prêmios a distribuir.\n");
        return;
    }

    int ganhadores_sena = 0;
    int ganhadores_quina = 0;
    int ganhadores_quadra = 0;
    
    for (int u = 0; u < MAXIMO_DE_USUARIOS; u++) {
        if (listaDeUsuarios[u].existente == 1 && listaDeUsuarios[u].quantidade >= 1) {
            for (int i = 0; i < listaDeUsuarios[u].quantidade; i++) {
                if (listaDeUsuarios[u].acerto[i] == 6) {
                    ganhadores_sena++;
                } else if (listaDeUsuarios[u].acerto[i] == 5) {
                    ganhadores_quina++;
                } else if (listaDeUsuarios[u].acerto[i] == 4) {
                    ganhadores_quadra++;
                }
            }
        }
    }

    double premio_bruto = total_arrecadado * 0.46;
    double premio_sena = premio_bruto * 0.35;
    double premio_quina = premio_bruto * 0.20;
    double premio_quadra = premio_bruto * 0.20;

    printf("\n\n--- Divisão dos Prêmios ---\n");
    printf("Total Arrecadado: R$ %d,00\n", total_arrecadado);
    printf("Prêmio Bruto (46%% da arrecadação): R$ %.2f\n", premio_bruto);
    
    printf("\nPrêmio da Sena (35%% do bruto):\n");
    if (ganhadores_sena > 0) {
        double premio_por_ganhador = premio_sena / ganhadores_sena;
        printf("  - %d ganhador(es). Prêmio total: R$ %.2f\n", ganhadores_sena, premio_sena);
        printf("  - Cada ganhador receberá: R$ %.2f\n", premio_por_ganhador);
    } else {
        printf("  - Não houve ganhadores da Sena. O prêmio acumula.\n");
    }

    printf("\nPrêmio da Quina (20%% do bruto):\n");
    if (ganhadores_quina > 0) {
        double premio_por_ganhador = premio_quina / ganhadores_quina;
        printf("  - %d ganhador(es). Prêmio total: R$ %.2f\n", ganhadores_quina, premio_quina);
        printf("  - Cada ganhador receberá: R$ %.2f\n", premio_por_ganhador);
    } else {
        printf("  - Não houve ganhadores da Quina.\n");
    }

    printf("\nPrêmio da Quadra (20%% do bruto):\n");
    if (ganhadores_quadra > 0) {
        double premio_por_ganhador = premio_quadra / ganhadores_quadra;
        printf("  - %d ganhador(es). Prêmio total: R$ %.2f\n", ganhadores_quadra, premio_quadra);
        printf("  - Cada ganhador receberá: R$ %.2f\n", premio_por_ganhador);
    } else {
        printf("  - Não houve ganhadores da Quadra.\n");
    }
}


// A função principal de exibição, que coordena as outras.
// aqui eu vou precisar verificar dentro de todos os jogadores, tenho duas opões, ou faço um por um, ou faço todos de uma vez
// criei uma variável int no struct para que eu possa manter dentro dos usuários o número de acertos que eles tiveram.
void exibe_ganhadores(struct usuarios listaDeUsuarios[], int numero_sorteado[6], int total){
    int opcao;
    printf("\nVocê deseja: \n");
    printf("    >> 1) Ver os acertos de cada jogador;\n");
    printf("    >> 2) Ver ganhadores por classe e a divisão do prêmio.\n");

    do {
        printf("Sua opcao: ");
        scanf("%d", &opcao);
        int c;
        while((c = getchar()) != '\n' && c != EOF);

        if(opcao < 1 || opcao > 2){
            printf("Por favor, escolha uma opção válida.\n");
        }
    } while (opcao < 1 || opcao > 2);

    // Primeiro, calculamos os acertos para evitar repetição de código.
    calcula_acertos(listaDeUsuarios, numero_sorteado);
    // Atualiza o valor arrecadado antes de mostrar os prêmios
    verificar_valor(listaDeUsuarios, &total);


    // Em seguida, chamamos a função apropriada com base na escolha do usuário.
    switch (opcao) {
        case 1:
            exibe_acertos_por_jogador(listaDeUsuarios);
            break;
        case 2:
            exibe_ganhadores_por_classe(listaDeUsuarios);
            calcula_e_exibe_premios(listaDeUsuarios, total);
            break;
        default:
            break;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////
//! 7 - //////////////////// ÁREA DE ENTENDER O JOGO /////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void entender_como_funciona(){
    printf("\n================ COMO FUNCIONA O JOGO ================\n");
    printf("1. O sistema permite cadastrar ate %d jogadores com nome e CPF.\n", MAXIMO_DE_USUARIOS);
    printf("2. Cada jogador pode fazer de 1 a 4 jogos.\n");
    printf("3. Cada jogo pode ter de 6 a 12 números (entre 1 e 60).\n");
    printf("4. Voce pode escolher os números ou usar a Surpresinha (geracao automatica).\n");
    printf("5. Para fins de simulacao, cada jogo custa R$ 1.000,00.\n");
    printf("6. Apos o sorteio (manual ou automatico), o sistema confere os acertos.\n");
    printf("7. O prêmio bruto corresponde a 46%% do total arrecadado e é dividido assim:\n");
    printf("   a) 35%% entre os acertadores de 6 números (Sena);\n");
    printf("   b) 20%% entre os acertadores de 5 números (Quina);\n");
    printf("   c) 20%% entre os acertadores de 4 números (Quadra);\n");
    printf("======================================================\n\n");
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////


int main(){
    int total = 0; 
    int numeros_sorteados[6] = {0,0,0,0,0,0};
    struct usuarios lista_de_usuarios[MAXIMO_DE_USUARIOS];
    
    // Zera os dados dos usuários no início para evitar lixo de memória
    for(int i = 0; i < MAXIMO_DE_USUARIOS; i++) {
        lista_de_usuarios[i].existente = 0;
        lista_de_usuarios[i].quantidade = 0;
        for(int j=0; j<4; j++){
            for(int k=0; k<16; k++){
                lista_de_usuarios[i].jogo[j][k] = 0;
            }
        }
    }
    
    direcionamento_de_menu(lista_de_usuarios, numeros_sorteados, total );
    
    return 0;
}