#ifndef CADASTRAR_ALUNO_H
#define CADASTRAR_ALUNO_H

#include<stdio.h>
#include<stdlib.h>

#include "dados.h"
#include "Calcula_media.h"
#include "Verifica_dt.h"

void Cadastrar_Aluno(const char *data){
    Aluno novo_aluno;

    FILE *dt;

    printf("\n==============================================================================");
    printf("\n=========================== Iniciando cadastro de Aluno ======================");

    printf("\n    == > Por favor, insira a matrícula do aluno:");
    printf("\n    == > ");
    scanf("%d", &novo_aluno.Matricula);
    
    printf("\n    == > Por favor, insira a primeira nota do aluno:");
    printf("\n    == > ");
    scanf("%f", &novo_aluno.Nota1);
    
    printf("\n    == > Por favor, insira a segunda nota do aluno:");
    printf("\n    == > ");
    scanf("%f", &novo_aluno.Nota2);
    
    printf("\n    == > Por favor, insira a terceira nota do aluno:");
    printf("\n    == > ");
    scanf("%f", &novo_aluno.Nota3);
    
    printf("\n    == > Por favor, insira a quarta nota do aluno:");
    printf("\n    == > ");
    scanf("%f", &novo_aluno.Nota4);


    dt = fopen(data, "a"); 
    
    if(Verifica_dt("data.txt")){} else {
        return;
    }
    
    novo_aluno.Media = Calcular_a_Media(novo_aluno.Nota1, novo_aluno.Nota2, novo_aluno.Nota3, novo_aluno.Nota4);
    
       // Formato estruturado mais legível
    fprintf(dt, "MATRICULA:%d|NOTA1:%.2f|NOTA2:%.2f|NOTA3:%.2f|NOTA4:%.2f|MEDIA:%.2f\n", 
            novo_aluno.Matricula, 
            novo_aluno.Nota1, 
            novo_aluno.Nota2, 
            novo_aluno.Nota3, 
            novo_aluno.Nota4, 
            novo_aluno.Media);
    
    fclose(dt);
    printf("\n==============================================================================");
    printf("\n======================== CADASTRO REALIZADO ==================================");
    printf("\n    == > Matrícula: %d;", novo_aluno.Matricula);
    printf("\n    == > 1º Nota: %.2f;", novo_aluno.Nota1);
    printf("\n    == > 2º Nota: %.2f;", novo_aluno.Nota2);
    printf("\n    == > 3º Nota: %.2f;", novo_aluno.Nota3);
    printf("\n    == > 4º Nota: %.2f;", novo_aluno.Nota4);
    printf("\n    == > Media: %.2f;", novo_aluno.Media);
    printf("\n    == > Dados salvos em %s", data);
    printf("\n==============================================================================");
    printf("\n==============================================================================");
}

#endif