#ifndef VERIFICA_DT_H
#define VERIFICA_DT_H

#include <stdio.h>
#include <stdbool.h>

bool Verifica_dt(const char *data){
    FILE *dt;

    dt = fopen(data, "r");

    if(dt == NULL){
        printf("\n==============================================================================");
        printf("\n==================== ERRO: Não foi possível abrir o arquivo ==================");
        printf("\n==============================================================================");
        return false;
    }

    fclose(dt);

    return true;
}


#endif