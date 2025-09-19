// AQUI TEMOS O ARQUIVO MAIN, QUE VAI SER O ARQUIVO PRINCIPAL DO PROJETO, ONDE VAI TER A FUNÇÃO MAIN, E VAI SER RESPONSÁVEL POR CHAMAR TODAS AS OUTRAS FUNÇÕES
// ELA VAI SER RESPONSÁVEL POR CHAMAR O MENU, E REDIRECIONAR O USUÁRIO PARA O QUE ELE QUISER FAZER


// PROBLEMAS:
// 1- Não estou conseguindo passar o valor dos números sorteados para o arquivo "exibe_ganhadores.h",
// 2- Falta criar a função que calcula os acertos e mostra se o usuário ganhou algo ou não.
// 3- Falta criar a função que mostra o valor arrecadado e como ele é dividido entre os ganhadores.
// 4- Falta criar a função que explica como funciona o jogo.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


// PROTÓTIPOS: Aqui eu estou fazendo uma declaração antecipada ao compilador sobre as próximas funçãos, que ainda não foram definidas, mas serão
void entender_como_funciona();
void menu();
int direcionamento_de_menu(struct usuarios usuario[], int numero_sorteado[6], int total);
void exibe_ganhadores(struct usuarios usuario[], int numero_sorteado[6]);
void sortear_numero(int sorteio[6]);
void fazer_novo_jogo(struct usuarios ListaDeUsuarios[]);
void verificar_jogos(struct usuarios ListaDeUsuarios[]);
void cadastra_novo_usuario(struct usuarios ListaDeUsuarios[]);
void exibe_ganhadores(struct usuarios usuario[], int numero_sorteado[6]);
void sorteio_automatico(int sorteio[6]);
void sorteio_manual(int sorteio[6]);
void supresinha(struct usuarios ListaDeUsuario[],int cpf_encontrado, int local_atual);
void fazer_jogo_na_mao(struct usuarios ListaDeUsuario[], int cpf_encontrado, int local_atual);
void verificar_valor(struct usuarios ListaDeUsuarios[], int total);
void verificar_usuario_especifico(struct usuarios ListaDeUsuarios[]);
void verificar_todos_os_jogos(struct usuarios ListaDeUsuarios[]);


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
    printf("==============================================\n");    
}
int direcionamento_de_menu( struct usuarios usuario[], int numero_sorteado[6], int total){
    int opcao;
    
    do { 

        // aqui eu estou chamando a função menu, e vou salvar a opção que o usuário desejar acessar 
        menu();
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
                verificar_valor(usuario, total);
                break;
            case 5:
                sortear_numero(numero_sorteado);
                break;
            case 6:
                exibe_ganhadores(usuario, numero_sorteado);
                break;
            case 7:
                entender_como_funciona();
                break;
            
            default:
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

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////////////////////
//! 3 - ////////////////// ÁREA DE EXIBIR GANHADORES /////////////////////////////////////
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
    for(int u = 0; u < MAXIMO_DE_USUARIOS; u++) {
        if(listaDeUsuarios[u].existente == 1 && listaDeUsuarios[u].quantidade >= 1) {
            printf("O usuário %s, ", listaDeUsuarios[u].nome);
            for(int i = 0; i < listaDeUsuarios[u].quantidade; i++) {
                printf("teve um acerto de %d números na aposta %d\n",  listaDeUsuarios[u].acerto[i], i+1);
            }
        }
    }
}

// Implementação da função para exibir os ganhadores por classe.
void exibe_ganhadores_por_classe(struct usuarios listaDeUsuarios[]) {
    printf("\n--- Ganhadores por Categoria ---\n");
    printf("\nSena (6 acertos):\n");
    for (int u = 0; u < MAXIMO_DE_USUARIOS; u++) {
        if (listaDeUsuarios[u].existente == 1 && listaDeUsuarios[u].quantidade >= 1) {
            for (int i = 0; i < listaDeUsuarios[u].quantidade; i++) {
                if (listaDeUsuarios[u].acerto[i] == 6) {
                    printf("  - O usuário %s acertou a sena na aposta %d!\n", listaDeUsuarios[u].nome, i + 1);
                }
            }
        }
    }

    printf("\nQuina (5 acertos):\n");
    for (int u = 0; u < MAXIMO_DE_USUARIOS; u++) {
        if (listaDeUsuarios[u].existente == 1 && listaDeUsuarios[u].quantidade >= 1) {
            for (int i = 0; i < listaDeUsuarios[u].quantidade; i++) {
                if (listaDeUsuarios[u].acerto[i] == 5) {
                    printf("  - O usuário %s acertou a quina na aposta %d!\n", listaDeUsuarios[u].nome, i + 1);
                }
            }
        }
    }

    printf("\nQuadra (4 acertos):\n");
    for (int u = 0; u < MAXIMO_DE_USUARIOS; u++) {
        if (listaDeUsuarios[u].existente == 1 && listaDeUsuarios[u].quantidade >= 1) {
            for (int i = 0; i < listaDeUsuarios[u].quantidade; i++) {
                if (listaDeUsuarios[u].acerto[i] == 4) {
                    printf("  - O usuário %s acertou a quadra na aposta %d!\n", listaDeUsuarios[u].nome, i + 1);
                }
            }
        }
    }
}


// A função principal de exibição, que coordena as outras.
// aqui eu vou precisar verificar dentro de todos os jogadores, tenho duas opões, ou faço um por um, ou faço todos de uma vez
// criei uma variável int no struct para que eu possa manter dentro dos usuários o número de acertos que eles tiveram.
void exibe_ganhadores(struct usuarios listaDeUsuarios[], int numero_sorteado[6]){
    int opcao;
    printf("Você deseja: \n");
    printf("    >> 1) Ver os acertos de cada jogador;\n");
    printf("    >> 2) Ver cada classe de ganhos.\n");

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

    // Em seguida, chamamos a função apropriada com base na escolha do usuário.
    switch (opcao) {
        case 1:
            exibe_acertos_por_jogador(listaDeUsuarios);
            break;
        case 2:
            exibe_ganhadores_por_classe(listaDeUsuarios);
            break;
        default:
            break;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////////////////
//! 4 - //////////////////// ÁREA DE VERIFICAR VALOR /////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void verificar_valor(struct usuarios ListaDeUsuarios[], int total){
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
    total = 1000*contador;
    if(contador > 0){
        printf("\n  - Total de jogos cadastrados: %d\n", contador);
        printf("  - O montante total arrecadado é: R$ %d,00\n", total);
    } else{
        printf("\n  - Nenhum jogo foi cadastrado ainda. O montante total é R$ 0,00\n");
    }
    printf("\n========================================================\n");
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////






//////////////////////////////////////////////////////////////////////////////////////////
//! 5 - ////////////////// ÁREA DE SORTEAR NÚMERO ////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////


// essa foi sem dúvidas a função mas difícil pra criar.


void sortear_numero(int sorteio[6]){
    
    int opcao;
    printf("\n====================================================================================================\n");
    printf("|                                    SORTEAR NÚMERO                                                  |\n");
    printf("======================================================================================================\n");

    printf("        >> Você deseja:\n");
    printf("    >> 1) Fazer o sorteio automático?\n");
    printf("    >> 2) Fazer o sorteio manual?\n");
    do{
        scanf("%d", &opcao);

        int c; 
        while((c = getchar()) != '\n' && c != EOF);

        if(opcao != 1 && opcao != 2){
            printf("Por favor, insira um valor válido");
        }
    } while (opcao < 1 && opcao > 2);

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
        scanf("%d", &sorteio[i]);
    }
    printf("Números sortidos:");
    for(int i = 0; i < 6; i++){
        printf("%dº número: %d \n",i + 1,  sorteio[i]);
    }
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
        int indice = (rand()%60) + 1;
        // adicionando o número sortido ao array
        sorteio[i] = embaralhamento[indice];
        // removendo o número sortido
        embaralhamento[indice] = embaralhamento[tamanho_atual - 1];
        // diminuindo o tamaho atual
        tamanho_atual--;
        printf("%d", sorteio[i]);
    }
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////







//////////////////////////////////////////////////////////////////////////////////////////
//! 6 - //////////////////// ÁREA DE VERIFICAR VALOR /////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void verificar_valor(struct usuarios ListaDeUsuarios[], int total){
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
    total = 1000*contador;
    if(contador > 0){
        printf("\n  - Total de jogos cadastrados: %d\n", contador);
        printf("  - O montante total arrecadado é: R$ %d,00\n", total);
    } else{
        printf("\n  - Nenhum jogo foi cadastrado ainda. O montante total é R$ 0,00\n");
    }
    printf("\n========================================================\n");
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////






//////////////////////////////////////////////////////////////////////////////////////////
//! 6 - //////////////////// ÁREA DE VERIFICAR VALOR /////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void entender_como_funciona(){
    printf(" Função de entender jogos em desenvolvimento");
    return;
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////






int main(){
    int total;
    int numeros_sorteados[6];
    struct usuarios lista_de_usuarios[8];
    direcionamento_de_menu(lista_de_usuarios, numeros_sorteados, total );
    return 0;
}