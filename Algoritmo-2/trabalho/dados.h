#ifndef DADOS_H
#define DADOS_H

#include<stdio.h>
#include<stdlib.h>


#define MAXIMO_DE_USUARIOS 8

struct usuarios{
    char nome[50];
    char cpf[12];
    int jogo[4][16];
    int existente;

    // Eu precisei criar uma variável de quantidade para saber quantos foram feitos, e calcular depois 
    int quantidade;
};


#endif