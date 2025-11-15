#include<stdio.h>
#include<stdlib.h>

#include "dados.h"

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
    
    if(dt == NULL){
        printf("Tivemos um problema ao encontrar o arquivo em questão");
        return;
    }

    fprintf(dt, "    == > Matrícula: %d;", novo_aluno.Matricula);
    fprintf(dt, "    == > 1º Nota: %f;", novo_aluno.Nota1);
    fprintf(dt, "    == > 2º Nota: %f;", novo_aluno.Nota2);
    fprintf(dt, "    == > 3º Nota: %f;", novo_aluno.Nota3);
    fprintf(dt, "    == > 4º Nota: %f;", novo_aluno.Nota4);

    fclose(dt);
}