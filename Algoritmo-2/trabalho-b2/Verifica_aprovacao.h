#ifndef VERIFICA_APROVACAO_H
#define VERIFICA_APROVACAO_H

#include<stdio.h>
#include<stdlib.h> 

const char* Verifica_aprovacao( float Media){
    if (Media >= 6){
        return "ALUNO APROVADO" ;
    } else {
        return  "ALUNO REPROVADO";
    }
    
}

#endif