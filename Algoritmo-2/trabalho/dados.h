#ifndef DADOS_H
#define DADOS_H

#include<stdio.h>
#include<stdlib.h>


#define MAXIMO_DE_USUARIOS 5

struct usuarios{
    char nome[50];
    char cpf[12];
    int jogo[4][16];
    int existente;

    // Eu precisei criar uma variável de quantidade para saber quantos foram feitos, e calcular depois 
    int quantidade;

    // Eu precisei criar isso para armazenar o número de acertos
    int acerto[];
};


#endif