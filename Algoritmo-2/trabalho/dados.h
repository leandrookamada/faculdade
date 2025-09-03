#ifndef DADOS_H
#define DADOS_H

#include<stdio.h>
#include<stdlib.h>


#define MAXIMO_DE_USUARIOS 8

struct usuarios{
    char nome[50];
    int cpf;
    int jogo[4][16];
    int existente;
};


#endif