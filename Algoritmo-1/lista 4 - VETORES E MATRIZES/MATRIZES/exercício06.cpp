#include<stdio.h>
#include<stdlib.h>

int main(){
    int A[4][4], B[4][4], C[4][4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("\nInsira o %dº valor no primeiro vetor: ", (j+1) + (i*4));
            scanf("%d", &A[i][j]);
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("\nInsira o %dº valor no segundo vetor: ", (j+1) + (i*4));
            scanf("%d", &B[i][j]);
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(A[i][j] > B[i][j]){
                C[i][j] = A[i][j];
            } else {
                C[i][j] = B[i][j];
            }
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("\nO %dº valor do terceiro vetor é: %d ", (j+1)+(i*4), C[i][j]);
    }
    return 0;
}
