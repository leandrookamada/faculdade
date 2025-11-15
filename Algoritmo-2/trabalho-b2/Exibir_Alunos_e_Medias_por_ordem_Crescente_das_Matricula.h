#ifndef EXIBIR_ALUNOS_E_MEDIAS_POR_ORDEM_CRESCENTE_DE_MATRICULA_H
#define EXIBIR_ALUNOS_E_MEDIAS_POR_ORDEM_CRESCENTE_DE_MATRICULA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"
#include "Verifica_dt.h"

int compararPorMatricula(const void *a, const void *b) {
    Aluno *alunoA = (Aluno *)a;
    Aluno *alunoB = (Aluno *)b;

    return (alunoA->Matricula - alunoB->Matricula);
}

void Exibir_Alunos_e_Medias_por_ordem_Crescente_das_Matricula(){
    FILE *dt;
    char linha[500];
    int contador = 0;

    if(!Verifica_dt("data.txt")) {
        return;
    }

    dt = fopen("data.txt", "r");
    

    while(fgets(linha, sizeof(linha), dt) != NULL) {
        contador++;
    }

    if (contador == 0) {
        printf("\n==============================================================================");
        printf("\n======================== Nenhum aluno Encontrado =============================");
        printf("\n==============================================================================");
        fclose(dt);
        return;
    }

    Aluno *alunos = (Aluno *) malloc(contador * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro de alocação de memória!\n");
        fclose(dt);
        return;
    }

    rewind(dt);

    int i = 0;
    while(fgets(linha, sizeof(linha), dt) != NULL && i < contador){
        sscanf(linha, "MATRICULA:%d|NOTA1:%f|NOTA2:%f|NOTA3:%f|NOTA4:%f|MEDIA:%f|ESTADO:%s",
            &alunos[i].Matricula, &alunos[i].Nota1, &alunos[i].Nota2,
            &alunos[i].Nota3, &alunos[i].Nota4, &alunos[i].Media, alunos[i].Estado);
        i++;
    }

    qsort(alunos, contador, sizeof(Aluno), compararPorMatricula);

    printf("\n==============================================================================");
    printf("\n============== Alunos e Médias em Ordem Crescente de Matrícula ===============");
    for (i = 0; i < contador; i++) {
        printf("\n==============================================================================");
        printf("\n    == > Matrícula: %d", alunos[i].Matricula);
        printf("\n    == > Média: %.2f", alunos[i].Media);
        printf("\n    == > Estado: %s", alunos[i].Estado);
    }
    printf("\n==============================================================================");

    fclose(dt);
}
#endif