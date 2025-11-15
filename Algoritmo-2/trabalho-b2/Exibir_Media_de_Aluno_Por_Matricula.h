#ifndef EXIBIR_MEDIA_DE_ALUNO_POR_MATRÍCULA_H
#define EXIBIR_MEDIA_DE_ALUNO_POR_MATRÍCULA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"
#include "Verifica_dt.h"

void Exibir_Media_de_Aluno_Por_Matricula(){
    FILE *dt;
    char linha[500];
    Aluno aluno_temporario;
    int matricula;
    int achado = 0;

    dt = fopen("data.txt", "r");
    if(Verifica_dt("data.txt")){} else {
        return;
    }
    printf("\n==============================================================================");
    printf("\n=========================== Area de busca de Aluno ===========================");

    printf("\n    == > Por favor, insira a matrícula do aluno:");
    printf("\n    == > ");
    scanf("%d", &matricula);

    while(fgets(linha, sizeof(linha), dt) != NULL){
        if(sscanf(linha, "MATRICULA:%d|NOTA1:%f|NOTA2:%f|NOTA3:%f|NOTA4:%f|MEDIA:%f|ESTADO:%s",
            &aluno_temporario.Matricula,
            &aluno_temporario.Nota1,
            &aluno_temporario.Nota2,
            &aluno_temporario.Nota3,
            &aluno_temporario.Nota4,
            &aluno_temporario.Media,
            aluno_temporario.Estado) == 7){ 
                if(matricula == aluno_temporario.Matricula){
                achado = 1;
                printf("\n==============================================================================");
                printf("\n    == > Matrícula: %d", aluno_temporario.Matricula);
                printf("\n    == > Média: %.2f", aluno_temporario.Media);
                printf("\n==============================================================================");
                return;
                }
            }
    }
    if (achado == 0){
        printf("\n==============================================================================");
        printf("\n======================== Nenhum aluno Encontrado =============================");
        printf("\n==============================================================================");
    } 
    fclose(dt);
}

#endif