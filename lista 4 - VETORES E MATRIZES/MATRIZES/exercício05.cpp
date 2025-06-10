#include<stdio.h>
#include<stdlib.h>

int main(){
    int A[5][5], a, b;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("Insira o %dº valor: ", (j + 1) + (i*5));
            scanf("%d", &A[i][j]);
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(A[i][j] == 15){
                a = i + 1;
                b = j + 1;
            }
        }
    }
    if(a > 0 && b > 0){
        printf("valor encontrado na posição %d, na linha %d", b - 1 ,a - 1);
    } else {
        printf("\n O valor não foi encontrado.");
    }
    return 0;
}

                // printf("\nVocê achou o número desejado na posição %d, da linha %d", j , i);
