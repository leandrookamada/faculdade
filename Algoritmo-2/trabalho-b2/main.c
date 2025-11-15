#include <stdio.h>
#include <stdlib.h> 

void Menu(void Cadastrar_Aluno(), void Exibir_Alunos_E_Media(), void Exibir_Alunos_Aprovados_E_Medias(), void Exibir_Alunos_Reprovados_E_Medias(), void Exibir_Media_de_Aluno_Por_Matricula(), void Exibir_Alunos_e_Medias_por_ordem_Crescente_das_Medias(), void Exibir_Alunos_e_Medias_por_ordem_Crescente_das_Matricula()){
    int opcao;
    printf("==============================================================================");
    printf("==================== Programa de gerenciamento de Notas ======================");
    printf("    == > 1) Inserir matrícula do aluno e notas;");
    printf("    == > 2) Exibir alunos e médias;");
    printf("    == > 3) Exibir alunos aprovados e médias;");
    printf("    == > 4) Exibir alunos reprovados e médias;");
    printf("    == > 5) Exibir a média de um aluno específico a partir da sua matrícula;");
    printf("    == > 6) Exibir alunos e médias em ordem crescente das notas médias;");
    printf("    == > 7) Exibir alunos e médias em ordem crescente das matrículas;");
    printf("    == > 8) Sair do programa;");
    printf("==============================================================================");
    printf("==============================================================================");
    scanf("%d", &opcao);
    
    switch(opcao){
        case 1:
            Cadastrar_Aluno();
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
            printf("==============================================================================");
            printf("============================== Saindo do Programa ============================");
            printf("==============================================================================");
            printf("    == > Obrigado por participar ;) ");
            printf("    == > Leandro Nóbrega Lobato Kamada ");
            break;

        default:
            printf("==============================================================================");
            printf("====================== Opção Invalida, tente novamente =======================");
            printf("==============================================================================");
            break;
    }
}