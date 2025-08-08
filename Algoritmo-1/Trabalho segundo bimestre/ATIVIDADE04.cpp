#include<stdio.h>
#include<math.h>

//FUNÇÃO QUE VERIFICA O MENOR, ELA NÃO RETORNA NADA
void verificaMenorNota(int NOTAS[10][3], int local[3]){
    
    int indicedemenor = 0;
    //FOR RESPONSÁVEL POR SEMPRE ZERAR O VALOR DO ARRAY "local", 
    for(int i = 0; i < 3; i++){
        local[i] = 0;
    }

    //FOR RESPONSÁVEL POR PASSAR POR CADA ALUNO
    for(int i = 0; i < 10; i++){ 
        // AQUI EU ESTOU DIZENDO QUE A MENOR NOTA DE CADA ALUNO SEMPRE VAI SER A DA PRIMEIRA PROVA, CASO TENHA OUTRA MELHOR, A VARIÁVEL "menor" VAI RECEBER O VALOR DELA.
        int menor = NOTAS[i][0];
            // FOR RESPONSÁVEL POR PASSAR POR CADA PROVA DO ALUNO "i"
            for(int j = 0; j < 3; j++){
                //CASO A NOTA DA PROVA DO ALUNO FOR MENOR QUE A DA PRIMEIRA PROVA, VOU SALVAR O INDICE("j") NA VARIÁVEL "indicemenor", 
                //CASO DE FATO A MENOR NOTA SEJA NO INDICE 0, O VALOR DA VARIÁVEL JÁ VALE ZERO, POR ISSO NÃO DÁ ERRO
                if( NOTAS[i][j] < menor || NOTAS[i][j] == menor){                                                                          
                    menor = NOTAS[i][j];
                    indicedemenor = j;
                }
                //DEPOIS DE PERCORRER AS NOTAS DO ALUNO, EU INCREMENTO UM NO ARRAY "local", NA POSIÇÃO "indicemenor", 
                //QUE VAI VALER O LOCAL QUE ESTÁ ARMAZENADO A MENOR NOTA DO QUERIDO
            }
            local[indicedemenor]++;
        }

    }
int main(){
    int local[3];
    int NOTAS[10][3];
    for(int i =0; i < 10; i++){
        for(int j = 0; j < 3; j++){
            printf("Por favor, insira a nota da %d° prova do %d° aluno: ", j+1, i+1);
            scanf("%d", &NOTAS[i][j]);
        }
    }

    //AQUI EU ESTOU CHAMANDO A FUNÇÃO, ELA VAI PERCORRER TODAS AS NOTAS E SALVAR DAR OS VALORES PARA OS MEUS PARÂMETROS
    //COMO EU DISSE QUE O PRIMEIRO PARÂMETRO É O "NOTAS", QUE CORRESPONDE AS PROVAS DE CADA INDIVÍDUO, E DISSE QUE O SEGUNDO PARÂMETRO É O "local"
    //QUE ME RETORNA ONDE EU SALVEI A QUATIDADE DE MENORES NOTAS EM CADA PROVA
    verificaMenorNota(NOTAS, local);
        printf("%d alunos tiram notas baixas na primeira prova. \n %d tiraram notas baixas na segunda prova.\n %d tiraram notas baixas na terceira prova\n", local[0], local[1], local[2]);
    
    return 0;
}

//preciso ver a menor nota de cada aluno =i