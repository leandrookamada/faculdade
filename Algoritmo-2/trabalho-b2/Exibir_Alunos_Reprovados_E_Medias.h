#ifndef EXIBIR_ALUNOS_REPROVADOS_E_MEDIA_H
#define EXIBIR_ALUNOS_REPROVADOS_E_MEDIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"
#include "Verifica_dt.h"

void Exibir_Alunos_Reprovados_E_Medias(void){
    FILE *dt;
    char linha[500];
    Aluno aluno_temporario;
    int contador = 0;

    dt = fopen("data.txt", "r");

    if(Verifica_dt("data.txt")){} else {
        return;
    }

    printf("\n==============================================================================");
    printf("\n=================== Lista de medias de alunos Rerovados ======================");
    printf("\n==============================================================================");

    while(fgets(linha, sizeof(linha), dt) != NULL){
        if(sscanf(linha, "MATRICULA:%d|NOTA1:%f|NOTA2:%f|NOTA3:%f|NOTA4:%f|MEDIA:%f|ESTADO:%s",
            &aluno_temporario.Matricula,
            &aluno_temporario.Nota1,
            &aluno_temporario.Nota2,
            &aluno_temporario.Nota3,
            &aluno_temporario.Nota4,
            &aluno_temporario.Media,
            aluno_temporario.Estado) == 7){
                if(strcmp(aluno_temporario.Estado, "ALUNO_REPROVADO") == 0){
                    contador ++;
                    printf("\n==============================================================================");
                    printf("\n--- ALUNO %d ---", contador);
                    printf("\n    == > Matrícula: %d", aluno_temporario.Matricula);
                    printf("\n    == > Média: %.2f", aluno_temporario.Media);
                    printf("\n    == > %s", aluno_temporario.Estado);
                    printf("\n==============================================================================");
                }
            
        }

    }
    if (contador == 0){
        printf("\n==============================================================================");
        printf("\n======================== Nenhum aluno Reprovado =============================");
        printf("\n==============================================================================");
    } else {
        printf("\n==============================================================================");
        printf("\n======================== Total de alunos Reprovados: %d =====================", contador);
        printf("\n==============================================================================");

    }
    
    fclose(dt);
}
#endif