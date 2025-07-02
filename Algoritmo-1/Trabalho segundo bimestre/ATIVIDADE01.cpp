#include<stdio.h>
#include<math.h>

float calculaAMedia(float A[15]){
    float media;
    for(int i = 0; i < 15; i++){
        media += A[i];
    }
    
    return media/15;
}
void calculaMaioreMenor(float A[15], float *maior, float *menor) {
    *maior = A[0];
    *menor = A[0];
    for (int i = 1; i < 15; i++) {
        if (*maior < A[i]) *maior = A[i];
        if (*menor > A[i]) *menor = A[i];
    }
}
int main(){
    float media, maior, menor, A[15];
    for (int i = 0; i < 15; i++){
        printf("\nPor favor, insira a nota do %d aluno: ", i+1);
        scanf("%f", &A[i]);
    }
    media = calculaAMedia(A);
    calculaMaioreMenor(A, &maior, &menor);

    printf("\nA media da turma é: %.1f\n", media);
    printf("\nA maior nota da turma foi: %.1f\n", maior);
    printf("\nA menor nota da turma foi: %.1f\n", menor);

    return 0;
    
}