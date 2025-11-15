#ifndef DADOS_H
#define DADOS_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    int Matricula;
    float Nota1;
    float Nota2;
    float Nota3;
    float Nota4;
    float Media;
    char Estado[20];
} Aluno;

#endif // DADOS_H
