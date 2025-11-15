#include<stdio.h>
#include<stdlib.h>
 
#include "dados.h"
#include "Cadastrar_Aluno.h"
#include "Exibir_Alunos_E_Media.h" 
#include "Exibir_Alunos_Aprovados_E_Medias.h" 
#include "Exibir_Alunos_Reprovados_E_Medias.h" 
#include "Exibir_Media_de_Aluno_Por_Matricula.h"
#include "Exibir_Alunos_e_Medias_por_ordem_Crescente_das_Medias.h"
#include "Exibir_Alunos_e_Medias_por_ordem_Crescente_das_Matricula.h"



int Menu(){
    int opcao;
    printf("\n==============================================================================");
    printf("\n==================== Programa de gerenciamento de Notas ======================");
    printf("\n    == > 1) Inserir matrícula do aluno e notas;");
    printf("\n    == > 2) Exibir alunos e médias;");
    printf("\n    == > 3) Exibir alunos aprovados e médias;");
    printf("\n    == > 4) Exibir alunos reprovados e médias;");
    printf("\n    == > 5) Exibir a média de um aluno específico a partir da sua matrícula;");
    printf("\n    == > 6) Exibir alunos e médias em ordem crescente das notas médias;");
    printf("\n    == > 7) Exibir alunos e médias em ordem crescente das matrículas;");
    printf("\n    == > 8) Sair do programa;");
    printf("\n==============================================================================");
    printf("\n==============================================================================");
    printf("\n    == > ");
    scanf("%d", &opcao);
    return opcao;
}

int main(){
    int opcao;
    do {
        opcao = Menu();
        
        switch(opcao){
            case 1:
                Cadastrar_Aluno("data.txt");
                break;
                
            case 2:
                Exibir_Alunos_E_Media();
                break;

            case 3:
                Exibir_Alunos_Aprovados_E_Medias();
                break;

            case 4:
                Exibir_Alunos_Reprovados_E_Medias();
                break;

            case 5:
                Exibir_Media_de_Aluno_Por_Matricula();
                break;

            case 6:
                Exibir_Alunos_e_Medias_por_ordem_Crescente_das_Medias();
                break;

            case 7:
                Exibir_Alunos_e_Medias_por_ordem_Crescente_das_Matricula();
                break;

            case 8:
                printf("\n==============================================================================");
                printf("\n============================== Saindo do Programa ============================");
                printf("\n==============================================================================");
                printf("\n    == > Obrigado por participar ;) ");
                printf("\n    == > Leandro Nóbrega Lobato Kamada \n");
                break;

            default:
                printf("\n==============================================================================");
                printf("\n====================== Opção Invalida, tente novamente =======================");
                printf("\n==============================================================================");
                break;
        }
    } while (opcao != 8);

    return 0;
}